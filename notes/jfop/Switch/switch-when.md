---
layout: default
title: When to Use a `switch` Control Statement
---


We can make `switch` statements into _if-then-else_ statements.

```java
switch(num) {
  case 0: System.out.println("zero");
    break;
  case 1: System.out.println("one");
    break;
  default: System.out.println("neither");
}

// translated to if else...
if (num == 0) {
  System.out.println("zero");
}
else if (num == 1) {
  System.out.println("one");
}
else {
  System.out.println("neither");
}
```
Since `switch` and `if` statements are similar, when do we use a `switch` over an `if`?

`switch` is useful when we have a discrete, constant set of cases, like the buttons on a remote control.

> #### discrete
> Individually separate and distinct.

```java
switch(buttonPressed){
  case "0":
    //...
    break;
  case "1":
    //...
    break;
}
```

Use `if` when you need to compare against something that varies, like comparing if a number is in a range of values.

```java
if (value >= 18 && value <= 34) {
  //...
}
```
Use `switch` if you need fall through.

### Drill
`Switch/src/examples/PrintDots.java`
* Examine and run the program.

   (We will learn better ways to create this kind of output. This example just takes advantage of fall through.)


### Practice Exercise
You will use `if` much, much more than `switch`.

<hr>

[Prev](switch-break-default.md) -- [Up](README.md) -- [Next](labs.md)

