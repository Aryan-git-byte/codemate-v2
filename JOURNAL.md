---
title: "Codemate-v2"
author: "Aryan-git-byte"
description: "A 16 key custom hackpad designed to ease simple tasks through one click , with rotary knob to control volumes etc , and a oled with cute eyes, tracking what u doing etc, and fully rgb board"
created_at: "2026-03-09"
---

# March 9th - 11th: Started schematic, assigned footprints, and routed PCB!

Hi so from the last few days i've been working on a project, but coudlnt journal it because i was using obs studio to record and it wasnt supported at that time, then i forgot.
so this is a combined journal of 3 days work, lets start:

**Date - 9/03**

so i wanted to upgrade my previous codemate (https://github.com/Aryan-git-byte/CodeMate)    
and make a version 2 of it, which will have more buttons & aesthetic too.   
so i outlined my need, and came to conclusion that i wanted a macropad which can help me in various tasks such as autodesk, or it can be used as calculator, and much more so i decided to use **16 SPSTs**, **2 Rotary encoder with Switch**, **1 OLED** and obviously **RGBs**. Also i wanted to use TFT at first , but that would be too big for my need, so i skipped it.

so with these requirements kept in mind i started searching for the components i wanted to use, first came the **MCU**,    
requirements? must've native usb, type c port, and enough pins.  

with this requirements i started searching for the perfect MCU, some MCU i looked upon were:    

> **Raspberry Pi pico W/2W** — these were great tbh but missed one thing they didnt had type c port, and microusb is a pain in ass tbh. so i skipped it    
> **xiao series** — they were uhh kinda expensive tbh here and also out of stock at most vendors    
> **esp32-s3-zero by waveshare** — chose this at last, satisfied all the requirements ✓

now next was oled & rotary with switch, they were easy to find.

now come the led , dude this was the hardest one to find,

| LED | Status |
|-----|--------|
| neopixel | out of stock, no vendor in india |
| sk6812 | no vendor in india, and im not paying custom duties for these RGBs. |
| WS2812 | okay, okay these were good but i realized this late so i kept searching |

then i paused for a moment rethink my whole life, and then started drawing schematic, i first made the matrix, then i found out that i m lacking GPIOs so i added an **I2C expander** and pretty much completed the schematic with all the features, (which was later polished just a bit)

schematic on that date:

![schematic](https://raw.githubusercontent.com/Aryan-git-byte/codemate-v2/master/journal-img/image-1.png)

so yhh these were the work i did on 9 march

**10/03**

today i didnt did much work honestly, i just came and assigned all **footprints** and **3d models** of each symbol (yhh this was a pain too) i mean it didnt take that long but frustrated me enough 

today's work photo:

![footprints](https://raw.githubusercontent.com/Aryan-git-byte/codemate-v2/master/journal-img/image-2.png)

nnow dont ask me why are those switches that way in the photo (i fixed that thing when i wasnt recording afterwards, cuz it was a small change)

**11/03**

today i started my another peaceful day not knowing what is waiting for me in that scary software of **kicad**, i started recording opened kicad, everything seems to be going normal, i was routing then after some routing i came to routing leds, which were nightmare, all leds were placed not in numberwise but here & there so because of that i had to redo the schematic of the leds, arrange them in the way i had did in my pcb, so after all these i finally routed all the compennts and completed it.

the pcb , next is **3D model of the case**, which i believe willl be done soon

Youtube: https://youtu.be/ggxAWWdpk_k?si=SCKBwQzEbwkj9NhI

**Total time spent: ~5h 53 min**

# March 19th: Started CAD model of the case!

Today i started working on the CAD model of the codemate-v2, here are some pics:

![cad start](https://raw.githubusercontent.com/Aryan-git-byte/codemate-v2/master/journal-img/image-3.png)

today i also changed my setup from that potato laptop to a beast pc (which is ofc my institute lab's pc) TT.

so i found out that my 3d models of some were missing so i assigned them again , then exported 3d model of the pcb , then made the case around it, starting with the **base**, then **walls**, then the **curvature for the type C**:

![cad base](https://raw.githubusercontent.com/Aryan-git-byte/codemate-v2/master/journal-img/image-4.png)

![cad walls](https://raw.githubusercontent.com/Aryan-git-byte/codemate-v2/master/journal-img/image-5.png)

![cad usbc curve](https://raw.githubusercontent.com/Aryan-git-byte/codemate-v2/master/journal-img/image-6.png)

after which i imported my dxf from **ai03 plate generator**, and started making the top part.
and as of now i've completed this much design, will do polishing tmrw.

Lapse: https://public.lapse-hackclub.link/timelapses/jxMuQGCbdSnj/timelapse-jxMuQGCbdSnj.mp4

**Total time spent: ~2h 43 min**

---

# April 2nd: Finalizing files, organizing GitHub, and polishing CAD!

So i started working on the project and the goal of this session was to start finalizing my files so i can submit it and also start organizing the github, i started by working on the 3d model in which i had to do some works such as many bodies that were supposed to be combined were not, and when i tried it didnt let me combine em, i couldnt make new components etc. then i got to know about the **hybrid thing** , apparently my project was just a component or a body ig instead of hybrid design which allows us to put both bodies and components so i did that. combined bodies that were supposed to be together, and yes i also imported an oled 3d model and assembled it in the final assembly build in the CAD and did a bit branding on the backside because the front was already very populated. after which i read the docs and made sure my project is following everything. Polished the final assembly a bit then exported the **main body** & **front panel** separately and tried to render the full assembly from blender ,but i didnt know a shit on how that worked so i just ignored it.. after that i opened canva thinking to make the poster but i remebered about the firmware, so i went to read it docs, and figured out its kinda complicated but i'll figure it out.

the final build photo:

![final build 1](https://raw.githubusercontent.com/Aryan-git-byte/codemate-v2/master/journal-img/image-7.png)

![final build 2](https://raw.githubusercontent.com/Aryan-git-byte/codemate-v2/master/journal-img/image-8.png)

![final build 3](https://raw.githubusercontent.com/Aryan-git-byte/codemate-v2/master/journal-img/image-9.png)

Lapse: https://public.lapse-hackclub.link/timelapses/eKwN3tI9GYHY/timelapse-eKwN3tI9GYHY.mp4

**Total time spent: ~1h 35 min**

---

# April 3rd: Tested WS2812B NeoPixel LED code in Wokwi!

Today i read about the **WS2812B NeoPixel** led code, and tested it in **wokwi**.
first off which i started by setting up the file and wackatime to my **arduino ide**, after that i opened tinker cad and started tinkering with the WS2812B led and arduino to learn about how its code is written. then i downloaded the libraries and boards to my arduino ide and also synced all the timelapses to my hackatime project. then to test the WS2812B led with esp32 i opened the wokwi editor and read docs about the ws2812b led:

![wokwi test](https://raw.githubusercontent.com/Aryan-git-byte/codemate-v2/master/journal-img/image-10.png)

and then referencing my code from a doc from https://iotwebplanet.com/esp32-with-ws2812-neopixel-led/?srsltid=AfmBOopXigoNd1Ef20ZVot9wFrPmHvmjztVqUW6OPCEOBJlMukhi5L6i
i got the code to test the leds on the board after soldering them and before soldering other components

Lapse: https://public.lapse-hackclub.link/timelapses/BJizs8soNoUa/timelapse-BJizs8soNoUa.mp4
Lapse: https://public.lapse-hackclub.link/timelapses/P3uvmIZazKJ7/timelapse-P3uvmIZazKJ7.mp4

**Total time spent: ~55 min**

---

# April 19th: Fought Blender (and lost... for now)

yoo, why blender is so hardd mannn, like this time again i tried to use blender but god damn itt.
i had to install like **3 versions** of it , then i got the plugin **pcb2blender** working. and even after importing it i didnt knew what to do with this mann 

![blender struggle](https://raw.githubusercontent.com/Aryan-git-byte/codemate-v2/master/journal-img/image-11.png)

Lapse: https://public.lapse-hackclub.link/timelapses/H7cz5NOCKMke/timelapse-H7cz5NOCKMke.mp4

**Total time spent: ~16 min**

---

# April 22nd: Assigned keycap and knob 3D models, imported to Fusion 360!

Hii, so today i started by opening the codemate-v2 PCB, and assigning **3d models of keycaps & knob** to switches and encoders, it was a hard time finding models as most were in **stl files**, but stilll i smhow converted those stls to steps and assigned em, and it looks pretyy nice now:

![keycaps assigned](https://raw.githubusercontent.com/Aryan-git-byte/codemate-v2/master/journal-img/image-12.png)

so after that i started to import this pcb in **fusion 360** and now will work on it further    

Lapse: https://public.lapse-hackclub.link/timelapses/jFNNw9AM3DWv/timelapse-jFNNw9AM3DWv.mp4

**Total time spent: ~1h 4 min**

---

# May 2nd: Rendered PCB in Fusion 360 and fixed GPU strain issues!

i started by importing the exported 3d model of my pcb in kicad but omg the strain it was putting on my gpu and cpu due to its **millions of faces** but still i thought this is workable and i tried to work with this:

![fusion heavy](https://raw.githubusercontent.com/Aryan-git-byte/codemate-v2/master/journal-img/image-13.png)

and rendered it :

![render](https://raw.githubusercontent.com/Aryan-git-byte/codemate-v2/master/journal-img/image-14.png)

so after that i came back 2 days later , trying to render it beautifully again and adding appearances to faces etc
but this was so heavy heavy that i had to work on fixing it.
i searched for ways, asked people in the slack and they told me to **change the model of the keycap and the knob** so i did it . After that it was workign as smooth as butter so i continued forward

Lapse: https://public.lapse-hackclub.link/timelapses/GyKJ0a0nzVtK/timelapse-GyKJ0a0nzVtK.mp4
Lapse: https://public.lapse-hackclub.link/timelapses/nAhz6AsD8Oq7/timelapse-nAhz6AsD8Oq7.mp4

**Total time spent: ~1h 29 min**

---

# May 14th: Final render done and zine designed!

I started by first opening fusion 360 and rendering my product which turned out very good: 

![final render](https://raw.githubusercontent.com/Aryan-git-byte/codemate-v2/master/journal-img/image-15.png)

After that I started working on the **zine** which also turned out very good :

![zine](https://raw.githubusercontent.com/Aryan-git-byte/codemate-v2/master/journal-img/image-16.png)

Its a very minimalist aesthetic zine, my favourite as of now

So after both of these i arranged my repo and also started searching for the **BOM** 

Lapse: https://public.lapse-hackclub.link/timelapses/e-RqM5W6dsiw/timelapse-e-RqM5W6dsiw.mp4

**Total time spent: ~3h 1 min**

---

# May 15th: Completed BOM and finalized repo!

i started by completing my **BOM**:

![bom](https://raw.githubusercontent.com/Aryan-git-byte/codemate-v2/master/journal-img/image-17.png)

which u can see in my repo.
after that i also arranged my repo and added everything and also wrote the readme 

![readme](https://raw.githubusercontent.com/Aryan-git-byte/codemate-v2/master/journal-img/image-18.png)

Lapse: https://public.lapse-hackclub.link/timelapses/yTrNAkjzAvJ_/timelapse-yTrNAkjzAvJ_.mp4

**Total time spent: ~47 min**
