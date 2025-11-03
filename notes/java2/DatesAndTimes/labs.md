## Labs
We are going to modify classes to use Java 8's `LocalDate`.

Package: `DatesAndTimes/com.example.datesandtimes.labs`

Solutions: `DatesAndTimes/com.example.datesandtimes.solutions.labs`

1. Modify `USState`: instead of `String`, make the `admissionDate` a `LocalDate`, updating getters, setters, and constructors as needed.

   (Solution: _USState.java_)

2. Modify `USStatesApp`: in `loadStatesMapFromFile`, the date field must now be converted to a `LocalDate` before the `USState` constructor is called.  At the top of the method define a `DateTimeFormatter` with a pattern for parsing the date strings in the file.  In the loop, use the formatter to parse the string into a `LocalDate` to pass to the `USState` constructor.

   (Solution: _USStatesApp.java_)

<hr>

[Prev](DateTimeFormatter.md) -- [Up](README.md)

