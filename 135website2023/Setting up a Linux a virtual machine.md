> **Important** These instructions are no longer maintained, and may be inaccurate. For Windows, it is easier to use [[WSL Windows Subsystem for Linux]] instead. 

The following describes one way install and run [Ubuntu](https://www.ubuntu.com/) on a virtual machine on Windows. 

**If you are using the CSIL lab computers, you don't need to do any of this --- all the necessary software should already there.**

1. Save a copy of the latest ISO for the version of [Ubuntu Linux](https://www.ubuntu.com/download/desktop). 
2. **Download and install [VirtualBox](https://www.virtualbox.org/)**.
3. **Create a new virtual machine** for 64-bit Linux. Here are some reasonable default settings for you virtual machine:
   - **RAM**: 4096 MB
   - **Number of CPUs**: 2
   - **Virtual disk size**: 25 GB (choose to create a disk during the installation, and select all the default options)
   - **Video memory**: 128 MB (this is in the [VirtualBox](https://www.virtualbox.org/))
   
   Of course, you may want to try different values depending upon the specs of your computer. But be aware: if you use too little RAM your virtual machine might be sluggish, and if you run out of virtual disk space it can be a hassle to set up a new disk.
   
4. **Run your virtual machine** from the previous step by clicking the green arrow at the top of the [VirtualBox](https://www.virtualbox.org/) manager screen. It should ask you for a CD image, and you should select the Linux ISO file you saved in step 1., and create a new Ubuntu virtual machine using the ISO file you downloaded from step 1. 

    If your virtual machine screen is to small, then you can resize it within Linux. For example, with [Pop! OS](https://pop.system76.com/), you can click on the installation window that shows up and move it out of the way so you can access the desktop. Then right-click on the desktop and choose "Display Settings", select "Resolution", and choose a bigger resolution.
    
5. When you have your virtual machine up and running, you should also install the **Guest Additions**. This will make it easier to resize the screen, and will even let you drag-and-drop between your virtual machine and the host computer. To install Guest Additions, go to your virtual machine window and open the Devices menu. Then select "Insert Guest Additions CD image ..." and follow the instructions. When Guess Additions are added, you may want to in the **Devices menu**:
    - **Enable shared clipboard**: set it to "bidirectional", and you will be able to cut-and-paste between your virtual machine and your host computer
    - **Enable shared drag and drop**: set it to "bidrectional" if you want to be able to drag-and-drop between your virtual machine and host computer
    - **Add a shared folder**: in "Shared Folders" you can add a folder on your host computer that your virtual machine can read/write. When you add the folder path, **select the "automount" box** so it will be ready to use each time you run your virtual machine. 
      
	  After you've added the Shared Folder name in the Device menu, you need to give your account permission to access in Linux. To do that, run the Linux terminal, and type this command:
	  ```bash
	  sudo adduser $USER vboxsf
	  ```
	  Then, re-boot your virtual machine.
6. When you have the virtual machine set up, see [[Getting Your C++ Environment Up and Running]] for how to compile and run C++ programs in this course.

It can be tricky to install virtual machines on some computers, but it's worth the effort --- using a virtual machine is a valuable skill for any software developer.

Be patient, and make sure you are following all the steps carefully. If neither [VirtualBox](https://www.virtualbox.org/), you could read about [other ways to install Ubuntu](https://www.ubuntu.com/download/desktop).
