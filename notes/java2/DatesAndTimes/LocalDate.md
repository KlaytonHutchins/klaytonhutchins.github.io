---
layout: default
title: `LocalDate`
---


Use a `LocalDate` to represent a calendar date.

* No time or time-zone information is stored, only year, month, and day.

Create a `LocalDate` object with the static factory method `of`, passing in the year, month, and day.

* Use `1` for January, `12` for December.

  ```java
  LocalDate christmas = LocalDate.of(2018, 12, 25);
  ```

* Or, pass the month value using the `Month` enumeration.

  ```java
  LocalDate mayDay = LocalDate.of(2018, Month.MAY, 1);
  ```

The `toString` method outputs ISO-8601 format dates, consisting of <code><i>YYYY</i>-<i>MM</i>-<i>DD</i></code>

```java
System.out.println(mayDay);
// "2018-05-01"
```

For a `LocalDate` object that represents the current date, call the static `now` method, instead.

```java
LocalDate today = LocalDate.now();
```

* Call various getter methods to retrieve properties of your date.

  ```java
  int day = today.getDayOfMonth();
  int year = today.getYear();
  ```

The `Month` enum provides utility methods:
```java
Month month = today.getMonth();
System.out.println(month.getDisplayName(TextStyle.FULL, Locale.getDefault())
                   + " has " + month.length(today.isLeapYear()) + " days");
// "February has 28 days"
```

<hr>

[Prev](temporalData.md) -- [Up](README.md) -- [Next](LocalTime.md)

