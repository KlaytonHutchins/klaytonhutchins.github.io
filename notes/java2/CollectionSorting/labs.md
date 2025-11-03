## Labs
In these labs we will use the interfaces and sorting methods from this chapter to sort data.

Starter code: `CollectionSorting/com.example.sorting.labs`.

Solutions: `com.example.sorting.solutions.labs`

1. The `PlanetSorter` class loads and prints a list of `Planet` objects.  Create a `Comparator` that will sort planets in reverse order of orbit.  Use `Collections.sort` and the `Comparator` to sort the list before printing it.

   (Solution: _PlanetReverseOrbitComparator.java_, _PlanetSorter.java_)

1. Change `PlanetSorter` to have the list sort itself instead of using `Collections.sort`.

   (Solution: _PlanetSorter2.java_)

1. The _access\_log_ file contains records of hits to a web site. Consider each line equivalent to one hit, and the first space-separated word on each line identifies the visitor. Write a Java application that reads this file a line at a time, and counts the number of hits from each unique visitor, storing the results in a `Map`.

   When all the records have been read, display the unique visitors along with the corresponding number of total hits. (Hint: Use `String`'s `split()` method to get the first field of each line.)

   (Solution: _ShowHits.java_)

1. (Optional) Modify your solution to sort the displayed records according to the total number of hits for each visitor.

   (Solution: _ShowSortedHits.java_)

<hr>

[Prev](CollectionsClass.md) -- [Up](README.md)

