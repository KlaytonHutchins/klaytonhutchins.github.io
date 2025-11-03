---
layout: default
title: `enum` Type
---

## `enum` Types

`enum` is a data type (like `class` and `interface`) that allows a variable to be a **set of predefined constants**.

* An `enum` can be in its own `.java` file, or part of another class.

Use `enum` types when you need to represent a fixed set of constants, such as:
* the names of planets.
* a set of command-line flags.
* menu options.


### Conventions

The name of the type is singular, like creating a `class`, because callers will use one of the discrete constant values.

```java
public enum Color {
  // ...
}
```

The members of the `enum` are constants, so we capitalize and use snake-case.

```java
public enum Color {
  RED, GREEN, BLUE  // comma-separated, no need for a ;
}
```

### Drill
> `EnumeratedTypes/com.example.enums.drills`
>
> * Create a new `enum` named `Day` for the days of the week, starting with Sunday.
>   * Be sure to observe naming conventions.

<hr>

[Prev](README.md) -- [Up](README.md) -- [Next](enum-details.md)

