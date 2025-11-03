---
layout: default
title: `Duration` and `Period`
---

## `Duration` and `Period`

The `java.time` API has two classes for representing time intervals: `Duration` and `Period`.

* Use their static `between` method to get the time interval between two temporal values.

`Duration` represents time intervals that include clock time - seconds and nanoseconds.

```java
LocalTime start = LocalTime.now();
for (int i = 0; i < 1000000; i++) {
  // do nothing
}
LocalTime finish = LocalTime.now();
Duration howLongToCountTo1000000 = Duration.between(start, finish);
System.out.println(howLongToCountTo1000000);
// "PT0.013S"
```

`Period` represents time intervals in calendar time - years, months, and days.

```java
LocalDate christmas = LocalDate.of(2018, 12, 25);
LocalDate today = LocalDate.now();
Period daysUntilXMas = Period.between(today, christmas);
System.out.println(daysUntilXMas);
// "P10M19D"
```

Instead of calling the `between()` method, you can use one of several static `of()` methods to create a `Duration` or `Period` directly.

```java
Period sixMonths = Period.ofMonths(6);
System.out.println(sixMonths);
// "P6M"
Duration napTime = Duration.ofMinutes(73);
System.out.println(napTime);
// "PT1H13M"
```

The `toString` for both `Duration` and `Period` starts with `P` (for period), followed by intuitive unit abbreviations and quantities.

### Drill
> `DatesAndTimes/com.example.datesandtimes.drills.IntervalDrill`
>
> Open `IntervalDrill` and add the following code:
> * Create a LocalDate representing the start date of your cohort.
> * Create a LocalDate representing today.
> * Print out both dates.
> * Create a Period object representing the interval between the two dates, and print it.
> * Create a LocalTime representing when you arrived today.
> * Create a LocalTime representing now.
> * Print out both times.
> * Create a Duration object for the interval between now and when you arrived, and print it.
> * What happens if you try to create a Duration representing the interval between your cohort start date and today?
>
> (Solution: `DatesAndTimes/com.example.datesandtimes.solutions.drills.IntervalDrill`)

<hr>

[Prev](LocalDateTime.md) -- [Up](README.md) -- [Next](DateTimeFormatter.md)

