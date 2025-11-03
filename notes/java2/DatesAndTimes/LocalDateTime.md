## Date-Times and `Instant`

`LocalDateTime` encapsulates both date and time information, with no time zone.

The overloaded `of` method allows you pass:
* Year as an `int`,
* Month, as a month number from `1` to `12`, or `Month` enum value,
* Day, hour and minute integers,
* Optional seconds, with optional nanoseconds.

... or use an overload that takes `LocalDate` and `LocalTime` objects.

```java
LocalDateTime ldt = LocalDateTime.of(2018, 12, 25, 7, 30);
LocalDate christmas = LocalDate.of(2018, 12, 25);
LocalTime sevenThirty = LocalTime.of(7, 30);
LocalDateTime xmasMorning = LocalDateTime.of(christmas, sevenThirty);
```

* ISO-8601 format for a datetime is <code><i>YYYY</i>-<i>MM</i>-<i>DD</i>T<i>hh</i>:<i>mm</i>:<i>ss</i></code>

  ```java
  System.out.println(xmasMorning);
  // "2018-12-25T07:30"
  ```

### `ZonedDateTime`

As the name implies, a `LocalDateTime` represents the time as seen on a local wall clock.

Like `LocalDateTime`, a `ZonedDateTime` encapsulates a calendar date and clock time, but the clock time is associated with a specific time zone.

```java
ZonedDateTime coloradoDay = ZonedDateTime.of(2018, 8, 1, 0, 0, 0, 0, ZoneId.of("UTC-6"));
System.out.println(coloradoDay);
// "2018-08-01T00:00-06:00[UTC-06:00]"
```

### Practice Exercise
> Time zone IDs can be expressed in multiple ways:
> * Hour offsets relative to UTC (Universal Coordinated Time, aka Greenwich Mean Time, aka Zulu or Z):
>   * `Z-7`
>   * `Z+1`
> * Prefixed offset IDs:
>   * `GMT-7`
>   * `UTC+1:00`
> * Regional IDs:
>   * `MST` (Mountain Standard Time)
>   * `CET` (Central European Time)
> * Names:
>   * `US/Mountain`, `America/Denver`
>   * `Europe/Paris`
>
> `java.time.ZoneId` can parse most of these.

### `Instant`

When interfacing with systems based on Unix times, use an `Instant` object.

```java
Instant thisInstant = Instant.now();
System.out.println(thisInstant.getEpochSecond());
// 1517958836
```

You can convert an `Instant` to a `LocalDateTime` or `ZonedDateTime` by providing a time zone ID.

```java
ZonedDateTime thisZonedDateTime = ZonedDateTime.ofInstant(thisInstant, ZoneId.of("US/Mountain"));
System.out.println(thisZonedDateTime);
// "2018-02-06T16:12:15.573-07:00[US/Mountain]
```

### Drill
> `DatesAndTimes/com.example.datesandtimes.drills.TimeDrill`
>
> In `main`:
> * Create a `LocalDateTime` for the current date and time.
> * What happens if you use the `LocalDateTime` above to create a `LocalDateTime` for 22 hours in the future?
>
> (Solution: `DatesAndTimes/com.example.datesandtimes.solutions.drills.TimeDrill2`)

<hr>

[Prev](LocalTime.md) | [Up](README.md) | [Next](DurationandPeriod.md)

