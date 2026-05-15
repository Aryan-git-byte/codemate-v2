#include <Wire.h>
#include <Keypad.h>
#include <FastLED.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_PCF8574.h>
#include "USB.h"
#include "USBHIDKeyboard.h"
#include "USBHIDConsumerControl.h"

// my pins
byte rPins[4] = {4, 5, 6, 7}; 
byte cPins[4] = {0, 1, 2, 3}; 

USBHIDKeyboard kb;
USBHIDConsumerControl media;
Adafruit_SSD1306 oled(128, 64, &Wire, -1);
Adafruit_PCF8574 pcf;
CRGB myLeds[16];

char myKeys[4][4] = {
  {'1', '2', '3', '4'}, 
  {'5', '6', '7', '8'}, 
  {'9', 'A', 'B', 'C'}, 
  {'D', 'E', 'F', 'G'}  
};
Keypad pad = Keypad(makeKeymap(myKeys), rPins, cPins, 4, 4);

uint8_t oldKnobs = 0xFF;
int vol = 50; 
bool quiet = false;

void setup() {
  Serial.begin(115200);
  
  kb.begin();
  media.begin();
  USB.begin();

  Wire.begin(); 
  oled.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  oled.clearDisplay();
  sayThing("my macro", "yay!");

  pcf.begin(0x20, &Wire);
  pcf.digitalWriteByte(0xFF); // make inputs work
  
  FastLED.addLeds<WS2812B, 10, GRB>(myLeds, 16);
  FastLED.setBrightness(50);
}

void loop() {
  doLights();
  checkButtons();
  spinnyThings();
  delay(10); 
}

void doLights() {
  // math from internet
  float b = (exp(sin(millis() / 2000.0 * PI)) - 0.36787944) * 108.0;
  FastLED.setBrightness((uint8_t)b);
  for(int i = 0; i < 16; i++) {
    myLeds[i] = CRGB::Teal; // my fav color
  }
  FastLED.show();
}

void checkButtons() {
  char k = pad.getKey();
  if (k) {
    String msg = "";
    
    if(k == '1') { kb.press(KEY_LEFT_CTRL); kb.press('c'); delay(50); kb.releaseAll(); msg = "copy"; }
    if(k == '2') { kb.press(KEY_LEFT_CTRL); kb.press('x'); delay(50); kb.releaseAll(); msg = "cut"; }
    if(k == '3') { kb.press(KEY_LEFT_CTRL); kb.press('v'); delay(50); kb.releaseAll(); msg = "paste"; }
    if(k == '4') { kb.press(KEY_LEFT_GUI); kb.press(KEY_LEFT_SHIFT); kb.press('s'); delay(50); kb.releaseAll(); msg = "snip"; }
    
    if(k == '5') { kb.press(KEY_LEFT_CTRL); kb.press('z'); delay(50); kb.releaseAll(); msg = "undo"; }
    if(k == '6') { kb.press(KEY_LEFT_CTRL); kb.press('y'); delay(50); kb.releaseAll(); msg = "redo"; }
    if(k == '7') { kb.press(KEY_LEFT_CTRL); kb.press('s'); delay(50); kb.releaseAll(); msg = "save"; }
    if(k == '8') { kb.press(KEY_LEFT_CTRL); kb.press(KEY_LEFT_SHIFT); kb.press(KEY_ESC); delay(50); kb.releaseAll(); msg = "taskman"; }

    if(k == '9') { kb.write(KEY_F13); msg = "vscode"; }
    if(k == 'A') { kb.write(KEY_F14); msg = "cmd"; }
    if(k == 'B') { kb.write(KEY_F15); msg = "fusion"; }
    if(k == 'C') { kb.write(KEY_F16); msg = "chrome"; }

    if(k == 'D') { media.write(CONSUMER_CONTROL_PLAY_PAUSE); msg = "play"; }
    if(k == 'E') { media.write(CONSUMER_CONTROL_MUTE); msg = "shh"; }
    if(k == 'F') { kb.press(KEY_LEFT_GUI); kb.press('v'); delay(50); kb.releaseAll(); msg = "clip"; }
    if(k == 'G') { kb.press(KEY_LEFT_GUI); kb.press('l'); delay(50); kb.releaseAll(); msg = "bye"; }

    sayThing("button:", msg);
  }
}

void spinnyThings() {
  uint8_t now = pcf.digitalReadByte();
  
  if (now != oldKnobs) {
    
    // first knob vol
    uint8_t a1 = bitRead(now, 0);
    if (a1 != bitRead(oldKnobs, 0) && a1 == 1) { 
      if (bitRead(now, 1) != a1) {
        media.write(CONSUMER_CONTROL_VOLUME_UP);
        vol = min(100, vol + 2);
        sayThing("vol", String(vol) + "%");
      } else {
        media.write(CONSUMER_CONTROL_VOLUME_DOWN);
        vol = max(0, vol - 2);
        sayThing("vol", String(vol) + "%");
      }
    }

    // push to quiet
    if (bitRead(now, 2) == 0 && bitRead(oldKnobs, 2) == 1) {
      media.write(CONSUMER_CONTROL_MUTE);
      quiet = !quiet;
      if(quiet) sayThing("sound", "no");
      else sayThing("sound", "yes");
    }

    // second knob bright
    uint8_t a2 = bitRead(now, 4);
    if (a2 != bitRead(oldKnobs, 4) && a2 == 1) {
      if (bitRead(now, 5) != a2) {
        media.write(CONSUMER_CONTROL_BRIGHTNESS_UP);
        sayThing("sun", "up");
      } else {
        media.write(CONSUMER_CONTROL_BRIGHTNESS_DOWN);
        sayThing("sun", "down");
      }
    }

    // push for night
    if (bitRead(now, 6) == 0 && bitRead(oldKnobs, 6) == 1) {
      kb.write(KEY_F17); 
      sayThing("eyes", "safe");
    }

    oldKnobs = now;
  }
}

void sayThing(String line1, String line2) {
  oled.clearDisplay();
  oled.setTextSize(1);
  oled.setTextColor(SSD1306_WHITE);
  oled.setCursor(0,10);
  oled.println(line1);
  oled.setTextSize(2);
  oled.setCursor(0, 30);
  oled.println(line2);
  oled.display();
}