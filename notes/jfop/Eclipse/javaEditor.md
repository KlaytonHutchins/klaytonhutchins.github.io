---
layout: default
title: The Java Editor
---


The whole point of an IDE is to help us code faster so we spend less time and attention typing and more time thinking about the solutions we're creating.

The _Java Editor_ does everything it can to handle mundane details of coding Java.

* As you type, it incrementally recompiles your code to check for syntax errors.

* Errors and warnings are marked in the left margin of the editor.

  * Problems in the source code are also underlined in red.

* Hover over the marker to see details and suggested solutions.

### Drill
Open `HelloEclipse.java` in the Java Editor.
* Delete the semicolon at the end of the `System.out.println()` statement.  Notice the editor immediately sees the problem even though you haven't tried to compile or run your program.  Hover over the red marker in the left gutter; hover over the red underline in the code.
  * Retype the semicolon.

Every time you save a Java file, Eclipse will compile it for you.

  * Any compiler errors are visible in the _Problems_ view at the bottom of the screen.

As you type, the Jave Editor tries to anticipate your intentions and provide code-completions and recommendations.

`Ctrl-Space` invokes the _Content Assist_ feature.

### Drill
* Open a new line below the `System.out.println()` statement.
* Type `sysout`, then hit `Ctrl-Space`.
* Select `sysout - print to standard out` and hit `Enter`.
  * Notice in addition to writing `System.out.println();`, it left your cursor in the parentheses so you can immediately start typing what you want to print.
* Type a `"` - note that it closes it for you and leaves the cursor inside the quotes.
* Type `Awesome` and hit `Enter` - rather than actually adding a newline, it just moves you to the end of the line.
* Hit `Enter` again to start a new line of code.
* Type `if (true) {` and hit `Enter` - the editor closes the brace and puts you in the `if` block, automatically indenting.
* Type `if` and hit `Ctrl-Space`; choose `ifElse` from the Content Assist menu and hit `Enter` - it stubs out an `if`-`else` statement for you and waits for you to type the `if` condition.
* With your cursor on the first `if` line, hit `Cmd-D` to delete the line; repeat until the rest of the if and if-else block is gone.
  * If you delete too many lines, use `Cmd-Z` to undo.

<hr>

[Prev](editorsViewsAndPerspectives.md) -- [Up](README.md) -- [Next](shortcutKeys.md)

