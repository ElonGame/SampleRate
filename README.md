SampleRate
==========

A sample rate and beats-per-minute calculator for music production.  It is written in C++
and uses wxWidgets for the user interface.

An installer for Windows is available here:

http://zetacentauri.com/software_samplerateandbpmcalculator.htm

Building requires that wxWidgets 2.6+ be installed (2.8 recommended).  There is a Makefile
included for use on Linux.  If your wx-config is in a different location than that in the
Makfile, change the path in the Makefile.

This will also build on Windows, but you'll have to create your own Visual Studio project.
There are two .hpp and two .cpp files, so that should be easy. Setting paths and libraries
in Visual Studio is the most annoying part of creating a project, and wxWidgets is a
particular nuisance in that respect.

This project uses the MIT License.
