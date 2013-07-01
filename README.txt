DESCRIPTION:
A directory of projects to help transition the RPi to the new ofGLProgrammableRenderer. To use this clone the repo into your apps folder


TESTING ENVIRONMENT
Raspberry Pi Model B
GPU set to 128MB
Overclock set to Medium (900Mhz)
HDMI Monitor at 1280x720/60hz

Notes:
FPSLogger class averages and writes out a .log file to the bin/data directory. The log file name is a timestamp and the name of the renderer type


The config.make file and main.cpp file are setup to allow quicker cross testing. If the file `../../../libs/openFrameworks/gl/ofGLProgrammableRenderer.h ` exists ofGLProgrammableRenderer is used. If not the ofGLES2Renderer is used. In my setup I have 2 openFrameworks folders, the default contains the latest develop from https://github.com/openframeworks/openFrameworks/tree/develop and the second folder contains the ofGLES2Renderer based branch at the state before the merge
https://github.com/jvcleave/openFrameworks/tree/develop-raspberrypi_to_master


TODO:
Post initial tests - add to README





