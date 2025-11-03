## Iterating Arrays

`for` loops are made for iterating through arrays.

```java
String[] daysOfWeek = new String[7];
daysOfWeek[0] = "Sunday";
daysOfWeek[1] = "Monday";
daysOfWeek[2] = "Tuesday";
daysOfWeek[3] = "Wednesday";
daysOfWeek[4] = "Thursday";
daysOfWeek[5] = "Friday";
daysOfWeek[6] = "Saturday";

for(int i = 0; i < 7; i++) {
  System.out.println(i + ":" + daysOfWeek[i]);
}
```
Note how we use the value of `i` to access each element.

Since the array indexes start at `0` and end at `6`, the loop condition is `i < 7`.

### `length` Field

All arrays have a field named `length` that contains the number of elements in the array.

A better way to iterate is using the `length` field.

```java
for(int i = 0; i < daysOfWeek.length; i++) {
  System.out.println(i + ":" + daysOfWeek[i]);
}
```

Remember that if `daysOfWeek.length` is `7`, the last index in the array is `6`.

### Drill
`Arrays/src/drills/Iterating.java`
* Iterate through the `names` array to print the index of the name, and the name, e.g. `0 : Mike`.
* Iterate through the `precip` array, but only print values greater than `2.5`.
  
  (Solution: _Iterating.java_)

* After iterating, print the daysOfWeek array itself: `System.out.println(daysOfWeek)`. Note the format, and what _doesn't_ get printed.

<br >

### Practice Exercise
Printing an array does not print its members. Instead we see a `[`, the type that is in the array, and a numeric representation of the array.

```java
String[] daysOfWeek = new String[7];
daysOfWeek[0] = "Sunday";
daysOfWeek[1] = "Monday";
daysOfWeek[2] = "Tuesday";
daysOfWeek[3] = "Wednesday";
daysOfWeek[4] = "Thursday";
daysOfWeek[5] = "Friday";
daysOfWeek[6] = "Saturday";
System.out.println(daysOfWeek); // [Ljava.lang.String;@7852e922

double[] arr = new double[4];
System.out.println(arr); // [D@4e25154f
```

<hr>

[Prev](initializing.md) -- [Up](README.md) -- [Next](passing.md)

