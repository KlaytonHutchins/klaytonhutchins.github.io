## Installing Eclipse

On some systems, installing Eclipse consists of nothing more than unzipping the download and creating a shortcut to the `eclipse` program.

> #### Do This Now
> On MacOS, open the downloaded DMG file and drag `Eclipse.app` into `/Applications/`.
> * Drag `Eclipse.app` from `/Applications/` to the dock to create a shortcut.


Since it's written in Java, Eclipse needs a Java Runtime Environment - it doesn't include one.

* You must install a recent JRE and have the `java` command in your path.

  * If Eclipse doesn't detect a JRE it will prompt you to specify where one is installed.

* If you have the full Java Software Development Kit installed, Eclipse can do things like step through the library source code during debug.

* If you have multiple JDKs installed, you can choose which to use for a particular project.

### Practice Exercise
The `eclipse.ini` file, in the Eclipse install directory, has startup options that are passed to eclipse at runtime.  On MacOS this file is `/Applications/Eclipse.app/Contents/Eclipse/eclipse.ini`.

<hr>

[Prev](introToEclipse.md) | [Up](README.md) | [Next](workspaces.md)

