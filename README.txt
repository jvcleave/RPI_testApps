DESCRIPTION:
A directory of projects to help transition the RPi to the new ofGLProgrammableRenderer. To use this clone the repo into your openFrameworks/apps folder

I have also included binaries in case you want to run the apps without compiling. They are named like ProjectName_RendererType.bin

e.g.
ShaderExample_PostProcessing_GLES2.bin
ShaderExample_PostProcessing_ProgrammableGL.bin

RESULTS LOG
http://is.gd/OF_RPI_render_results

TESTING ENVIRONMENT
Raspberry Pi Model B
GPU set to 128MB
Overclock set to Medium (900Mhz)
HDMI Monitor at 1280x720/60hz

Notes:
Each project implements a FPSLogger class that averages the FPS and writes out a .log file to the bin/data directory. The log file name is a timestamp and the name of the renderer type


The config.make file and main.cpp file are setup to allow quicker cross testing. If the file ofGLProgrammableRenderer.h exists the ofGLProgrammableRenderer is used. If not the ofGLES2Renderer is used. In my setup I have 2 openFrameworks folders, the default contains the latest develop from https://github.com/openframeworks/openFrameworks/tree/develop and the second folder contains the ofGLES2Renderer based branch at the state before the merge
https://github.com/openFrameworks-RaspberryPi/openFrameworks/commit/9aa292b00f1825e7654e231e1fe5370d04be08cf




