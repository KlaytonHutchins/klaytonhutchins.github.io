## `break;` and `default:` in `switch` Statements

When the `switch` finds a matching `case` value, it enters that `case` and begins executing statements.

It continues executing statements until it has a reason to "break out" of the `switch` statement's body.

Without a `break;` statement, it will continue executing statements, even if they are part of another `case`.

This is called _fall through_ because execution "falls through" to the next case.

> #### fall through
> Executing the next `case`'s statements because a `break;` was not encountered.

This can be useful - it's not just a bug.

```java
switch (grade) {
  case "A": //"A" falls through to "a"
              //so they both print the same message
  case "a":
    System.out.println("Keep it up");
    break;
  case "B":
  case "b":
    System.out.println("Good job");
    break;
  case "C":
  case "c":
    System.out.println("Doing alright");
    break;
  case "D":
  case "d":
    System.out.println("Let's talk");
    break;
  case "F":
  case "f":
    System.out.println("You should come to class");
    break;
  default:
    System.out.println("That's not a grade");
  }
```

Our program now allows users to enter uppercase or lowercase grades.

### `default:`
Think of `default:` as the `else` for when other cases do not match.

The `default:` case is optional (just like `else`) - we do not have to have one.

We often put it as the last case in a `switch`, but it can go anywhere.

Be careful, though: it is still a place for Java to enter the `switch`, just like any `case`, so it would need a `break;`.

### Practice Exercise
`switch` must have a code block as its body.

`switch` does not have to switch on a variable, nor have any `case` statements. This code is legal.

```java
switch(42) {

}
```

### Drill
`Switch/src/drills/SwitchFallthrough.java`
* Run the program and verify that it will handle lowercase grades the same as uppercase grades.

<hr>

[Prev](switch.md) -- [Up](README.md) -- [Next](switch-when.md)

