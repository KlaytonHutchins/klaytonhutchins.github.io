---
layout: default
title: Shortcut Key Sequence
---


`Ctrl-Space` - Content Assist

* Use this key sequence to have Eclipse generate a list of possible matches for the current entry in the code.

`Cmd-Option-N` - New

`Cmd-Shift-O` - Organize Imports

* Click on a class that has been flagged as "not resolved" and use this key sequence to have Eclipse automatically discover and add an import for the class as well as eliminate any imports that aren't being used.

`Ctrl-M` - Maximize Active View or Editor

* This will take the current view or editor you are working in and maximize
it; use the sequence again to go back to the original size.

`Cmd-Shift-F` - Format Code

* You can customize the code formatter to understand your coding standards (_Eclipse_ | _Preferences_ | _Java_ | _Code Style_ | _Formatter_).

### Drill
Hit `Cmd-Option-N`, arrow down to `Class` on the menu and hit `Enter`.
* Type `NewClass` as the class name and click **Finish**.
* Type `Ctrl-M` to maximize the Java editor view.
* Inside the class body, type `main` and hit `Ctrl-Space`.
  * Select `main - main method` on the menu and hit `Enter`.
* Inside main, add: `Scanner keyboard;`.
  * You'll see error markers - hover over the red marker or the red underline to see Eclipse's suggested fixes.
  * Don't choose any: instead, hit `Cmd-Shift-O` to organize imports.
* Below the scanner definition, type `keyboard = new ` (with a space at the end) and hit `Ctrl-Space`.
  * Select `Scanner(InputStream source)` on the content assist menu and hit `Enter`.
  * Type `sys`, hit `Ctrl-Space`, select `System`, type a `.`, and select `in` from the menu.
* Hit `Enter` and type a semicolon.
* On the next line, type `keyboard.` and when the menu appears type `c` to select `close()`; hit `Enter`.
* Type `Cmd-Shift-F` to format your code (you'll be doing this a lot!)
* Type `Ctrl-M` to de-maximize the Java editor.

`Cmd-/` - Quick Comment

* This key sequence will comment out the current line or lines with a `//` comment; press it again to uncomment.

`Cmd-Ctrl-/` - Quick Block Comment

* Use this key sequence to comment out the currently highlighted block of lines with a block comment `/* */`;

  * Use a `Cmd-Ctrl-\` to remove a block comment.

### Drill
* Click on the `keyboard.close();` line and hit `Cmd-/`.
  * Notice the Java editor displays some warnings - your code creates the scanner but doesn't use it, and also fails to close it before exiting.
* Highlight all of the `main` method and hit `Cmd-Ctrl-/`; hit `Cmd-Ctrl-\` to uncomment.
* Uncomment the `keyboard.close();` statement by clicking on it and hitting `Cmd-/`.
* Hit `Cmd-S` to save the editor contents.

#### Copying and moving lines

* `Cmd-Option-DownArrow` - Duplicate line down.

* `Cmd-Option-UpArrow` - Duplicate line down.

* `Option-UpArrow` - Move line up.

* `Option-DownArrow` - Move line down.

### Drill
* Open a new line _above_ `keyboard.close();`.
* Type `sysout` and hit `Ctrl-Space`.
  * In the `System.out.println()` add `"Hi, what's your name?"`.
* On the next line, type `k` then `Ctrl-Space` and select `keyboard`, then type `.` then `n` and select `next()` from the content-assist menu; add a semicolon at the end.
* Type `Cmd-2` to pop up a menu. Then type `L` to assign the value returned by `keyboard.next()` to a new local variable - change the variable name to `name`.
* With your cursor on the `println()` statement use `Cmd-Option-DownArrow` to duplicate the line, then use `Option-DownArrow` to move the new line below `keyboard.next();`.  Change the text to `"Welcome to Eclipse, " + name`.
* `Cmd-S` to save your work, then run your program using the _Run_ button in the toolbar.
* Click into the console to type your name.


### More Shortcut Key Sequences

Eclipse is loaded with features that tend to be hidden deep beneath menu options. To see a list of all of the shortcut keys, use `Cmd-Shift-L`.

`Cmd-Shift-T` - Open Type

* Use the Open Type dialog to quickly jump to a class or interface in your project or in the Java libraries.

* For example, type `Str` for all classes that start with these three characters (String, StringBuffer, etc.)

`Cmd-Shift-R` - Open Resource

* Use the Open Resource dialog to find any kind of file in your project.

`F3` - Open Declaration

* Any time you have clicked on a method call in code, you can click F3 to jump to the method declaration in the Java editor.

`Cmd-O` - Quick Outline

* Use this key sequence to launch a dialog that helps you quickly find a method within the current file by simply typing in the first few letters of the method you are looking for.

<hr>

[Prev](javaEditor.md) -- [Up](README.md) -- [Next](importingProjects.md)

