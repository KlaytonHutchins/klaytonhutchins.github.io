## Sorting and Filtering with Lambdas

1. Make a copy of your _PresidentAppInnerClasses.java_ (so you can keep the original for reference), and name the new copy _PresidentAppLambda.java_.

   * Make sure the new class's `main` instantiates a `PresidentAppLambda`, not `PresidentAppInnerClasses`.

1. In the new copy, replace all inner classes with Lambda expressions.

   * Start by replacing anonymous classes, then replace local and member class instantiations.

1. Remove any local or member class definitions from your class.

1. Update any remaining `sort` or `filter` calls to use lambdas.

1. Modify `filter` to use `BiPredicate` instead of `PresidentMatcher`.

### Stretch Goals

1. If you haven't already, create a method that takes a list of presidents and writes it as tab-separated values to a file.

   * Records should be formatted so the existing code would be able to read and parse the records.

   * When testing, be careful NOT to use _resources/presidents.tsv_ as the output file!

2. Pass filtered lists and filenames to this method to save files with the presidents from each party.


<hr>

[Up](README.md)

