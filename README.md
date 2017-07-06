# SampleRate

A sample rate and beats-per-minute calculator for music production. It run on 
Windows and Linux and is written in C++. It was originally released on 
http://zetacentauri.com and was downloaded more than 20,000 times before
being open-sourced.

![Sample Rate Screenshot](https://github.com/Xangis/SampleRate/blob/master/images/SampleRate1.02.png)

A prebuilt installer for Windows is available in the installer folder:

https://github.com/Xangis/SampleRate/blob/master/installer/SampleRate1.02Setup.exe

This project uses the MIT License.

# Usage

To calculate the semitone shift from one sample rate or BPM to another, fill in 
the first two blanks and then click "Calc" next to the Semitone Shift text box.

To calculate the sample rate or BPM change to alter audio by a specific number 
of semitones, fill in the first blank, enter the semitone shift, and then click 
"Calc" next to the End Sample Rate/BPM text box.

# Building

Building requires that wxWidgets be installed (3.0 recommended, but older 
versions should also work).  

### Linux

There is a Makefile included for use on Linux. If your wx-config is in a 
different location than that in the Makefile, change the path in the Makefile.

To get the required wxWidgets development libraries on an Ubuntu or Debian-based
system, run:

sudo apt-get install libwxgtk3.0-dev

### Windows

To get wxWidgets for Windows, download it here:

http://wxwidgets.org/downloads/

There is a Visual Studio project included as PixelSwapper.sln. However, you'll need to
edit the "Additional Library Directories" and "Additional Include Directories"
paths in the project settings to point to where wxWidgets is on your system.

If it complains about not finding "wx/wx.h", then you need to set the include
path.

If it complains about a bunch of "unresolved external symbols" starting with wx,
then you need to set the library path.

#### Windows Installer

There is an InnoSetup installer script in the installer directory. You'll need to
edit it to match the paths where your project is located since they are all absolute
paths.

You can get InnoSetup here:

http://www.jrsoftware.org/isinfo.php

# Changelog

Changes in version 1.02:

- First open-source version.
- wxWidgets libraries updated from 2.8 to 3.0.
- Visual Studio redistributable is included in the installer for users who don't have it yet.

# Development Status

I consider this application to be finished and it is no longer under active 
development.

I do still maintain it and will update it as operating systems evolve.
