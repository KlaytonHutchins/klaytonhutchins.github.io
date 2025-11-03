## Declaring an Array

When we declare variables, we must declare the _type_ and _name_.

```java
int aSingleInt; // declare a variable to hold an int value
```

The array operator, `[]`, is how we make a single variable refer to multiple elements.

```java
int arrayOfInts[]; // declare a variable to refer to an array of int values
```

### Practice Exercise
The `[]` can go on either side of the variable name when you declare it.
```java
int arrayOfInts[];
int[] arrayOfInts;
```

An array holds data all of the same _type_.
* The array below can only hold `String` objects - we would not be able to store an `int` in this array.
```java
String stringsArr[];
```

### Practice Exercise
Any time you have a number of related data items that are all of the same type and purpose, you should consider using an array.


### Drill
`Arrays/src/drills/ArrayDeclare.java`
* Declare a variable for an array of `String` objects to hold the name of each weekday.
* Declare a variable to hold letter grades for each of a student's six classes.
* Declare a variable to hold the average monthly precipitation for a year.

<hr>

[Prev](array.md) | [Up](README.md) | [Next](creating.md)

