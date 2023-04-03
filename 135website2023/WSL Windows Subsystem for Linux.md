---
aliases: [WSL]
---

**Windows Subsystem for Linux** (**WSL**) is the easiest way to run Linux on a Windows computers. Compared to a traditional virtual machine installation of Linux, WSL starts faster, and interacts with Windows files and folders without any extra setup.

## Step 1: Install Windows Terminal
[Install the Windows Terminal through the Microsoft Store](https://aka.ms/terminal).

This will give you a nice modern command-line for using WSL.

## Step 2: Installing WSL
Follow the instructions here: [Installing WSL on Windows 10/11](https://docs.microsoft.com/en-us/windows/wsl/install). 

Use Windows 11 if you can, since that lets you run graphical Linux programs. WSL on Windows 10 does **not** support graphical Linux apps, just command-line programs. 

## Step 3: Using WSL
### Getting to Your Files
On Windows, the name of the main disk drive is usually "C:", and in WSL the C: drive is in the folder `/mnt/c`.  Your desktop folder should be in `/mnt/c/Users/<loginname>`.

For example, if your Windows login name is `bgates`, then the terminal command `cd /mnt/c/Users/bgates` should take you to your desktop folder. 

 Any other disks you have can be accessed similarly, e.g. if you have a D: drive it's at `/mnt/d`.

### Editing Your Files
The [VS Code text editor](https://code.visualstudio.com/) is an excellent (and free!) programming editor that also has direct support for WSL.



