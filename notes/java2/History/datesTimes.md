## Working with Dates and Times

The _presidents.tsv_ file includes fields with the first inauguration and end of term dates for each president (end of term is empty for the current president).

1. Modify the `President` class to include `String` fields for the term begin and end dates.
   * Create getters and setters.
   * Modify (or re-create) the constructor to include these new fields.
   * Add the new fields to `toString`

2. Copy `PresidentApp.java`, naming the new copy `PresidentAppDates`.

   * Make sure the new class's `main` instantiates a `PresidentAppDates`, not `PresidentApp`.
   * Modify `PresidentAppDates` to capture these fields from the file, and pass them to the `President` constructor.
   * Get this working and tested, printing out the full list of presidents.

3. In the `President` class, change the datatypes of the term begin and end dates to `LocalDate`.
   * Fix the getters, setters, and constructor.

4. In `PresidentApp` modify `loadPresidents` to convert the date strings from the file to `LocalDate` values using a `DateTimeFormatter`.

5. Add a new method to `President`: `getTermLength`.  This should return a `Period` object representing the interval between the term begin and end dates.  If the president has no term end date (that is, the current president) it should return the difference between term start and the current date.

   * Include this in the president's `toString`.

### Stretch Goals

1. Create a method that takes a list of presidents and writes it as tab-separated values to a file.

   * Records should be formatted so the existing code would be able to read and parse the records.

   * When testing, be careful NOT to use _resources/presidents.tsv_ as the output file!

<hr>

[Up](README.md)

