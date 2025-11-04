---
layout: default
title: Mad Lib
---


This application will prompt the user to enter a word that is either a noun, verb, or other part of speech.

It will then include their input in a story.

* Download the [project starter code](resources/MadLibs.zip).

* Move the `MadLibs.zip` file to your `~/SD/Java` folder:

  ```bash
  cd ~/SD/Java/
  mv ~/Downloads/MadLibs.zip .
  ```

* Import the zip file into Eclipse.

* Open `src/com.example.madlibs.MadLibsApp`. The multidimensional arrays hold story fragments and parts of speech:

   ```java
   {
      { "There once was a ", "NOUN" },
      { " from ", "NOUN" },
      { ". It was very ", "ADJECTIVE" },
      { ". One day it ", "VERB" },
      { " a ", "NOUN" },
      { ". There are no words for this kind of ", "VERB" },
      { ". The end.", null }
   }
   ```

Each line is a story fragment and then a prompt - the part of speech we request from the user. `null` means we don't prompt the user for anything.  You are going to use `StringBuilder` to turn these fragments into a story, using user input.

* Find the `addMadLibInput` method.  Follow the instructions in the comments to finish implementing the app.


<hr>

[Up](../README.md)
