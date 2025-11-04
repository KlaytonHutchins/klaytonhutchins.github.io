---
layout: default
title: Set Up the Initial Development Environment
---


You're going to use the command line to set up and use your initial development environment.

### Create Working Folders

Open a terminal.

The terminal application gives you access to a *shell* command line.
* This *command line interface* or CLI is the most basic and powerful way to access your system.
* Your continued mastery of the shell will give you much higher productivity than you can achieve without it.

We'll start laying out a directory structure and setting up the files we'll need to get started.

```bash
mkdir ~/SD  # You probably already created this for Prework. If not, create it now.
cd ~/SD
mkdir Java Tools
```
* In the shell, tilde (_~_) represents your account's home directory, */Users/yournamehere*
* The `cd` command changes your shell's current location in the file system.
* The `mkdir` (_make directory_) creates a new folder (we use the terms "folder" and "directory" interchangably).
  *  You can give it multiple directory names (_Java_ and _Tools_, in this case) and it will create them all.

* The `ls` command lists files.
* `ls -l` shows a _long listing_ that includes file size, permissions, modification time, and other information.

### Download and Extract Student Files

Download [Student Files](commandline.zip).

Copy the student files ZIP into the _Java_ folder, and unzip it there.

```bash
cd ~/SD/Java
cp ~/Downloads/commandline.zip .   # That's a space and a . at the end of the command.
unzip commandline.zip
cd jfop
ls
```
* The `cp` ("copy") command copies a file or files - it takes an existing filename and a new name or location to copy it to.
* The `..` ("dot-dot") represents your parent directory, one level up.
* The `.` ("dot") represents your current working directory, wherever that may be.
* The `unzip` command extracts a ZIP archive.
  * In this case, extracting _commandline.zip_ creates a subdirectory named _jfop/_.


<hr>

[Prev](README.md) -- [Up](README.md)

