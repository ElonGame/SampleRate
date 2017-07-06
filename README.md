# SampleRate

A sample rate and beats-per-minute calculator for music production. It run on 
Windows and Linux and is written in C++. It was originally released on 
http://zetacentauri.com and was downloaded more than 20,000 times before
being open-sourced.

![Sample Rate Screenshot](https://github.com/Xangis/SampleRate/blob/master/images/SampleRateAndBPMCalculator1.png)

A prebuilt installer for Windows is available in the installer folder:

https://github.com/Xangis/SampleRate/blob/master/installer/SampleRateAndBPMCalculator1.01Setup.exe

This project uses the MIT License.

# Building

Building requires that wxWidgets be installed (3.0 recommended, but older 
versions should work).  

### Linux

There is a Makefile included for use on Linux. If your wx-config is in a 
different location than that in the Makefile, change the path in the Makefile.

### Windows

This will also build on Windows, but you'll have to create your own Visual Studio project.
There are two .hpp and two .cpp files, so that should be easy. Setting paths and libraries
in Visual Studio is the most annoying part of creating a project, and wxWidgets is a
particular nuisance in that respect.

# Development Status

I consider this application to be finished and it is no longer under active 
development.

I do still maintain it and will update it as operating systems evolve.
