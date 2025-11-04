---
layout: default
title: `DateTimeFormatter`
---


### Formatting Dates and Times

`LocalDate` and `LocalTime` both override the `toString()` method, so presentation is easy.

```java
LocalDate today = LocalDate.now();
System.out.println(today);
// "2018-02-06"
```
You can, however, use the `java.time.format.DateTimeFormatter` to customize the output.

* Pass a format string to its static `ofPattern` method to create a formatter object.

  ```java
  DateTimeFormatter formatter = DateTimeFormatter.ofPattern("MM/dd/yyyy");
  System.out.println(formatter.format(today));
  // "02/06/2018"
  ```

`DateTimeFormatter` provides several prebuilt formatter objects as public fields.

```java
System.out.println(DateTimeFormatter.BASIC_ISO_DATE.format(today));
// "20180206"
System.out.println(DateTimeFormatter.ISO_DATE.format(today));
// "2018-02-06:
System.out.println(DateTimeFormatter.ISO_WEEK_DATE.format(today));
// "2018-W06-2"
System.out.println(DateTimeFormatter.ISO_ORDINAL_DATE.format(today));
// "2018-037"

LocalDateTime rightNow = LocalDateTime.now();
System.out.println(DateTimeFormatter.ISO_DATE.format(rightNow));
// "2018-02-06"
System.out.println(DateTimeFormatter.ISO_DATE_TIME.format(rightNow));
// "2018-02-06T17:11:01.666"
```

A formatter can only format data that's available in the temporal object.

```java
LocalDate todaysDate = LocalDate.now();
DateTimeFormatter formatter2 = DateTimeFormatter.ofPattern("MMM dd, yyyy HH:mm");
// System.out.println(formatter2.format(todaysDate));
// Exception in thread "main" java.time.temporal.UnsupportedTemporalTypeException: Unsupported field: HourOfDay

LocalDateTime currentDT = LocalDateTime.now();
System.out.println(DateTimeFormatter.ISO_ZONED_DATE_TIME.format(currentDT));
// Exception in thread "main" java.time.temporal.UnsupportedTemporalTypeException: Unsupported field: OffsetSeconds
```

### Parsing Dates and Times

You can use `DateTimeFormatter` to parse a `String` that's in a non-ISO format to a `LocalDate`, `LocalTime`, `LocalDateTime`, or `ZonedDateTime`.

* Pass a `DateTimeFormatter` reference to the `parse` method of the class you're instantiating.

  ```java
  String dateStr1 = "Feb 6, 2018";
  DateTimeFormatter dateFmt = DateTimeFormatter.ofPattern("MMM d, yyyy");
  LocalDate date1 = LocalDate.parse(dateStr1, dateFmt);
  System.out.println(date1);
  // "2018-02-06"

  String dtStr1 = "February 06, 2018; 8:20 AM";
  DateTimeFormatter dateTimeFmt = DateTimeFormatter.ofPattern("MMMM dd, yyyy; H:mm a");
  LocalDateTime dt1 = LocalDateTime.parse(dtStr1, dateTimeFmt);
  System.out.println(dt1);
  // "2018-02-06T08:20"
  ```

### Practice Exercise
> The `DateTimeFormatter` JavaDoc, https://docs.oracle.com/javase/8/docs/api/java/time/format/DateTimeFormatter.html, shows pattern specifiers and examples.  Some pattern letters behave differently depending on how many you use.  For example, `d` (day of month) by itself matches `9` or `29`, but `dd` would match `09` or `29`, but not `9`.
> 
> Similarly, with `M` for month:
> * `M` would match or format `5` or `12`.
> * `MM` would match or format `05` or `12`.
> * `MMM` would match or format `May` or `Dec`.
> * `MMMM` would match or format `May` or `December`.
> * `MMMMM` would match or format `M` or `D`.
> * `MMMMMM` would cause an `IllegalArgumentException`.

The input string needs to match the pattern, and the pattern itself must be self-consistent.

```java
DateTimeFormatter dateFmt = DateTimeFormatter.ofPattern("MMM d, yyyy");
DateTimeFormatter dateTimeFmt = DateTimeFormatter.ofPattern("MMMM dd, yyyy; H:mm a");
//...

String dateStr2 = "02 6, 2018";
LocalDate date2 = LocalDate.parse(dateStr2, dateFmt);
// Exception in thread "main" java.time.format.DateTimeParseException: Text '02 6, 2018' could not be parsed at index 0

String dtStr2 = "February 06, 2018; 8:20 PM";
LocalDateTime dt2 = LocalDateTime.parse(dtStr2, dateTimeFmt);
// Exception in thread "main" java.time.format.DateTimeParseException: Text 'February 06, 2018; 8:20 PM' could not be parsed: Conflict found: Field AmPmOfDay 0 differs from AmPmOfDay 1 derived from 08:20
```
* In the last example, the string includes the time "8:20", but also says "PM"; "8:20" by definition is "AM" - 8:20 pm must be given as "20:20".

* Like `Integer.parseInt`, `DateTimeFormatter` throws unchecked exceptions you can handle with a `try`/`catch`.


<hr>

[Prev](DurationandPeriod.md) -- [Up](README.md) -- [Next](labs.md)

