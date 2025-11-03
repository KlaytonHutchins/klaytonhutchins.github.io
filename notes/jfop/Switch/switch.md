## `switch` Statements: Multi-Way Decisions

Sometimes we'll compare a value with several different values, and follow a different execution path depending on which value matches.

A `switch` statement compares a single value to a list of possibilities.

```java
int answer;
//...
switch (answer) {
  case 0:
    statements;
    statements;
    break;
  case 1:
    statements;
    statements;
    break;
  case 2:
    statements;
    statements;
    break;
  default:
    statements;
    statements;
}
```
This `switch` compares `answer` to each `case` value, in order.

When it finds a matching `case`, it executes the statements in that `case`.

```java
char grade = 'A';
String message;

switch (grade) {
case 'A':
  message = "Keep it up";
  break;
case 'B':
  message = "Good job";
  break;
case 'C':
  message = "Doing alright";
  break;
case 'D':
  message = "Let's talk";
  break;
case 'F':
  message = "You should come to class";
  break;
default:
  message = "That's not a grade";
}
```

Of the data types we know, we can use `int`, `char`, and `String` data types in `switch` statements.

### Practice Exercise
Cases must be constant values, like literals: `"A"`, `12`, `'C'`. They cannot be variables or anything else Java has to determine at runtime.
```java
switch(num) {
  case 1:
    break;
  case variable: //NO
    break;
}
```


### Drill
`Switch/src/drills/SwitchInvestigation.java`

We're going to figure out what `break;` does in a `switch`. This drill switches on a `String` value.

* Run the program with a letter grade.
* Comment out the `break;` statements for `case` `"A"` and `"B"`.
* Run the program and enter `A`. What output do you notice? Uncomment the break in `case: "B"`. Now what happens?
* Move the entire `default` case before `case "A":`. Your code will look like:
```java
switch (grade) {
  default:
    System.out.println("That's not a grade");
  case "A":
    System.out.println("Keep it up");
    //break;
  case "B":
    System.out.println("Good job");
    break;
  //...
}
```
* Run the program again with the grade `Z`. What output do you see?

<hr>

[Prev](README.md) -- [Up](README.md) -- [Next](switch-break-default.md)

