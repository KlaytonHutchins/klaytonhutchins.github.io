---
layout: default
title: Lab
---

## Labs
The focus of this set of labs is reading, parsing, and writing files.

1. Create a class named `SearchEmployees` that searches through the file _employee.txt_ for the pattern "manager", and prints out any lines that match the pattern. (Hint: You can search through a string for a substring using the `indexOf` or `contains` methods in the `String` class.)

   (Solution: _SearchEmployees.java_)

2. Add code to `PlanetReader` to open _planets.txt_ and read it one line at a time.  As it reads each line, have it print just the planet's name. (Hint: `String.split`.)

   (Solution: _PlanetReader.java_)

3. Modify `PlanetReader`.  After reading a record, it should use the fields to construct a `Planet` object, then print it using `Planet`'s `toString`.

   (Solution: _PlanetReader2.java_)

4. Modify `PlanetReader`.  In `readPlanets` add a local variable of type `List<Planet>` initialized with an `ArrayList`.  While reading from the file, instead of printing the `Planet`, add it to the list.  Change the `readPlanets` return type from `void` to `List<Planet>`, and return the list after the file is closed.  In `main`, assign the returned list to a local variable and print it.

   (Solution: _PlanetReader3.java_)

5. Modify `PlanetReader`.  Create a `writePlanets` method that takes a `String` filename and a `List<Planet>` parameter.  It should open the named file for output, and for each planet, write its name, orbit, and diameter to the file, separated by tab (`\t`) characters.  Make sure you **don't** use _planets.txt_ as the output file name!  Check the results in your output file by opening it with the Eclipse Text Editor (Hint: In Eclipse, when a program creates a file in your project, Eclipse won't notice and display it until you do a _File_ | _Refresh_ (or _F5_.)

   (Solution: _PlanetReader4.java_)


_planets.txt_
```
Mercury, 57910000, 4880
Venus, 108200000, 12103
Earth, 149600000, 12756
Mars, 227940000, 6794
Jupiter, 778330000, 142984
Saturn, 1429400000, 120536
Uranus, 2870990000, 51118
Neptune, 4504000000, 49532
```

<hr>

[Prev](ClosingStreams.md) -- [Up](README.md)

