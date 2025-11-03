## `LocalTime`

`LocalTime` represents a 24-hour _wall-clock time_, encapsulating hour, minute, and second - with nanosecond precision.

* No date or time-zone information is stored.

The static `of` method is overloaded, allowing callers to pass:

* Just the hour and minute
* The hour, minute, and second
* Hour, minute, second, and nanonsecond

```java
LocalTime oneThirty = LocalTime.of(13, 30);
```

Like `LocalDate`, use the `now` method to get the current time.

```java
LocalTime rightNow = LocalTime.now();
System.out.println(rightNow);
// "14:20:55.939"
```

Both `LocalDate` and `LocalTime` are immutable; any method you call that seems to modify the object actually builds a new instance and returns it to you.

```java
LocalTime twoThirty = oneThirty.plusHours(1);
System.out.println(oneThirty);
// "13:30"
System.out.println(twoThirty);
// "14:30"
```

### Drill
> `DatesAndTimes/com.example.datesandtimes.drills.TimeDrill`
>
> In `main`:
> * Create a `LocalDate` and a `LocalTime` representing the current date and time.
> * Print both out.
> * Use the `LocalTime` above to create a `LocalTime` for 90 minutes in the future, and print it out. (Refer to the `LocalTime` JavaDoc for methods: https://docs.oracle.com/javase/8/docs/api/java/time/LocalTime.html)
> * What happens if you use your original `LocalTime` to create a `LocalTime` for 22 hours in the future?
>
> (Solution: `DatesAndTimes/com.example.datesandtimes.solutions.drills.TimeDrill`)

<hr>

[Prev](LocalDate.md) -- [Up](README.md) -- [Next](LocalDateTime.md)

