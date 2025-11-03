---
layout: default
title: Sorting and Filtering with Inner Classe
---

## Sorting and Filtering with Inner Classes

### Objectives
* Use member classes, local classes, and anonymous classes for sorting and filtering lists.

### Overview

The `President` class includes appropriate fields, getters and setters, and a constructor that takes all fields.  It also implements `Comparable<President>`, overriding `compareTo` to set the natural sort order using term number.

The file _resources/presidents.tsv_ consists of records with tab-separated fields.

1. Copy _PresidentAppDates.java_, naming the new copy _PresidentAppInnerClasses.java_.

   * Make sure the new class's `main` instantiates a `PresidentAppInnerClasses`, not `PresidentAppDates`.

   This class has a method that parses the file, creating an `ArrayList<President>`.  Its `printPresidents` method takes `List<President>` and prints it using `President`'s `toString`.

### Tasks

#### Sorting

1. Create a method that returns a list of presidents sorted by party and term number.  Use a **member class** that implements `Comparator<President>`.  Pass the original list to this method, and print the resulting list.

1. Create a method that returns a list of presidents sorted by the reason they left office, then by term number.  Use a **local class** for the comparator.  Pass the original list to this method, and print the resulting list.

1. Create a method that returns a list of presidents sorted by last name.  Use an **anonymous class** for the comparator.  Pass the original list to this method, and print the resulting list.

#### Filtering

The `PresidentMatcher` interface defines the `boolean` method `matches`, which takes a string and a `President` reference.  The `PresidentPartyMatcher` example returns true if the string matches the president's party (ignoring case).

In `PresidentAppInnerClasses`, the `filter` method takes a `String` and a `PresidentMatcher` implementation, returning a list containing presidents for which the matcher's `matches` method returns true.

1. Use `PresidentPartyMatcher` and the `filter` method to print a list of Whig presidents.

1. Define a **member class** that implements `PresidentMatcher`, with `matches` returning true if the president's first name starts with the string passed in.

1. Use a **local** (in `start`) implementation of `PresidentMatcher` that matches presidents based on why they left office.  Print the list of presidents who left when their term ended.

1. Use `filter()` and **anonymous** `PresidentMatcher` implementations to print lists of `President`s:
   1. Whose last names start with "C".
   1. Whose party contains the string "Democrat".
   1. Who died in office
   1. Who won only a single election.
   1. Whose terms started in the 19th century.

### Stretch Goals

1. If you haven't already, create a method that takes a list of presidents and writes it as tab-separated values to a file.

   * Records should be formatted so the existing code would be able to read and parse the records.

   * When testing, be careful NOT to use _resources/presidents.tsv_ as the output file!

2. Pass filtered lists and filenames to this method to save files with the presidents from each party.


<hr>

[Up](README.md)

