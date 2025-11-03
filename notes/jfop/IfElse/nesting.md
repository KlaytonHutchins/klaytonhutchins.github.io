---
layout: default
title: Nested Control Statement
---

## Nested Control Statements

When you put one control statement, such as an `if`, inside another control
statement, you have created _nested control statements_.

Worded another way, a nested control statement is one that is under the control of
another.

```java
if ( c < 10 )
  if ( resp == 'y' )  // nested
    System.out.println("Today is a warm day");

if ( c < 10 )
  System.out.println("Today is a warm day");
else
  if ( resp == 'n' )  // nested
    System.out.println("Today is a cold day");
```
This would be more readable with curly braces `{}` - look at the next set of statements.

```java
if ( x < y )
  if ( a == b )
    System.out.println("abc");
else
  System.out.println("sxyz"); // Whose "else" IS this?
```
* Indentation is irrelevant to program logic (but **critical** to your code's readability): the `else` here is paired to the closest `if` that it follows, the `a == b` condition.

Using code blocks makes this clearer and prevents bugs.

```java
if ( x < y ) {
  if ( a == b ) {
    System.out.println("abc");
  }
}
else {
  System.out.println("sxyz"); // Whose "else" IS this?
}
```

<hr>

[Prev](else.md) -- [Up](README.md) -- [Next](stringcomparison.md)

