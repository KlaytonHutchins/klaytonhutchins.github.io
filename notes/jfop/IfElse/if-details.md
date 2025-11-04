---
layout: default
title: `if` Syntax
---


```java
if ( expression )
  statement;
```
* `if` is the required keyword
* `()` follow `if`, and the expression inside _must_ evaluate to a `boolean`
* The next statement after the `()` will execute if the expression is `true`.

Notice how the "controlled statement" is indented from the `if`.
* This is not required, but is _very important_ for readability. Do it.

### Practice Exercise
If you do not indent correctly, such as indenting an `if`'s statement, other programmers will think you don't know what you're doing. Get in the habit of indenting.

```java
if ( answer != 42 )
  System.out.println("Wrong answer ...");
```

We may draw a **flow chart** to represent this logic, with the condition in a _decision diamond_.

![If Flow Chart](images/ifFlowChart.png)

### Practice Exercise
The first statement after an `if (expression)` is the one to execute. Look at this code.
```java
boolean isBuggy = false;
if (isBuggy);
  System.out.println("Yes, there are bugs");
```
The developer added a `;` after the `if` statement. Since `;` is the first statement<sup>*</sup> after the `if`, it is the one that executes. "Yes, there are bugs" will always print because it is not part of the `if`.

<sub>* `;` is the shortest statement in Java.</sub>


### Practice Exercise
The code below will not compile.
```java
int x = 50;
int y;
if (x < 100){
  y = 99;
}
System.out.println("y is " + y); //Compiler error
```
An `if` statement's body may not execute. Because `x` is a variable, and variables could change, the compiler thinks there is a chance `y` will not be initialized. Trying to use a variable before it is initialized causes a compiler error.

<hr>

[Prev](if.md) -- [Up](README.md) -- [Next](codeblock.md)

