# Table of Contents
1. [General Info](#general-info)
2. [Videos](#videos)
3. [Technologies](#technologies)
4. [Installation](#installation)
5. [Run](#run)
6. [Collaboration](#collaboration)
7. [Repository overview](#repository-overview)
8. [License](#license)
### General Info
***
**Lab 4**

In this lab, you will learn about the micro:Bit, how to programme it, how to flash it, and some fundamental programming.

***Setup***

You will need a micro:Bit board and a USB cord for this lab.
Both at the beginning of the lab and during the lecture, these will be handed out.
A directory for micro:Bit projects could be useful.
The system should already have the cross compiler and make tools installed. 

Change into your chosen directory and clone the micro:Bit v2 samples git repository:
```
$ git clone https://github.com/lancaster-university/microbit-v2-samples 
```

A directory called microbit-v2-samples will be created.
Change into that and then look in the source directory; the default hello world programme should be in main.cpp.
This can be built using the python3 build.py command in the build directory.
It takes a while to get the most recent set of microbit libraries the first time.
You should have a file named MICROBIT.hex if the build was successful.
This is the firmware file for the device's micro:Bit processor. 

Connect the micro:Bit to a USB port to flash it.
A USB drive should be able to mount the micro:Bit.
Transfer the MICROBIT.hex file to the USB disc that is mounted.
After that, the micro:Bit should flash itself and start executing the new image again.


If this works, the words "HELLO WORLD!" will scroll across the micro:display. Bit's 

***Task***

For this lab, there are two main programs and one advanced program to write.

Program 1:
* There is a file named blink1.cpp attached to this lab and located in the /home/compx349/lab4 directory.
To show what it works, compile this as the main.cpp file.
* Change this programme to shift the display's blinking led around.
When it hits the edge of the display, it should reverse its path and move in the opposite x and y directions.
Keep in mind that each direction's pixel numbers range from 0 to 4.
There are no changes made to the display when passing pixel values outside of this range. 

Program 2:
* There is code (under Without Events) to retrieve readings and shift a pixel on the display as a form of tiltmeter in the micro:Bit docs for the accelerometer at https://rneacy.dev/mbv2/ubit/accelerometer/.
Compile and run the programme on the micro:Bit after incorporating the code into a complete programme. 

Program 3 (Advance):
* Create a programme that causes the pixel to move as though it had inertia, so that when the accelerometer tilts, the pixel begins to move in that direction and continues to move even after the micro:Bit levels out.
The pixel should stop moving with a brief tilt in the other direction.
When the device is level, the pixel should also "bounce" off the edge of the display.
When a pixel approaches the edge of the screen and the device is tilted to keep it moving, you should provide the proper behaviour. 

***Marks***

* This lab is worth 2% of the final grade.

***Outcomes***

Once this lab is compleate you should have a program that moves the blinking led around the display.
and a program that moves the pixel as if it had inertia.. I have learned alot inregard to the 
C programming language and how multi-threaded tasks are handled accross multi-paged programs. However, due to personal family matters and a change of circumstances, I was unable to 
fix the remaining memory issues which I believed to have caused the results below.

### Videos
***
***Task One***


https://user-images.githubusercontent.com/109124700/201029656-021d562f-9caa-4152-9c78-d15aa2067dd7.mp4


* As you can see when you run the program, the leds blinks as it goes around the edge.

***Task Two***


https://user-images.githubusercontent.com/109124700/201029903-65a57af7-abc2-4c3d-a1a2-b0c25e9c2399.mp4


* As you can see when you run the program, the leds move around as you tilt the micro:bit.

## Technologies
***
A list of technologies used within the project:
* [gcc](https://gcc.gnu.org/): Version 9.4.0
* [nano](https://nano-editor.org/): Version 4.8

## Installation
***
A little intro about the installation. 
```
$ git clone https://github.com/lancaster-university/microbit-dal.git
```
## Run
***
**How to run**

To edit the code:
```
$ cd micro\:bit/
$ cd microbit-v2-samples/
$ source/
$ nano main.cpp
```
In a different termial, to compile the code:
```
$ cd micro\:bit/
$ cd microbit-v2-samples/
$ cd build
$ make
```
From this it will make a .hex file that you just need to drag onto the micro:bit which is located in:
```
$ cd micro\:bit/
$ cd microbit-v2-samples/
~"MICROBIT.hex"
```

## Collaboration
***
Just do what you want with this.
> Do what you want, whats done is done. 
## Repository overview
An overview of the directory structure and files:
```
.
├── README.md
├── src
│   ├── main.cpp
│   └── MICROBIT.hex
└── vids
    ├── taskOne.mp4
    └── taskTwo.mp4

2 directories, 5 files

```
## License
MIT License

Copyright (c) 2022 Cameron Cox

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

https://github-readme-stats.vercel.app/api?username=coxxy12
