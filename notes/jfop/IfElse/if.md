## `if` Statement

We know `if` statements in everyday language. If some condition is true, an action follows.

* "**If** it is raining, I will **take my umbrella**."
* "**If** you don't bathe, you will **not be very popular**."
* "**If** you keep shouting at that horse, you will **have a bad day**."

In Java, an `if` statement controls whether a statement (or group of statements) executes.
* Its basic format is below, in _pseudo code_.

  ```
  if ( expression evaluating to true )
    statement
  ```

> #### pseudo code
> Text that looks like code but may not compile. Its purpose is to explain what code does.

Our English examples above might look like

```java
boolean isRaining = false;
// ... code to determine if it's raining
if (isRaining == true)
  takeUmbrella();

boolean doesBathe = false;
int popularityLevel = 100;
// ...
if (doesBathe == false)
  popularityLevel = 0;

boolean shoutingAtHorse = false;
// ...
if (shoutingAtHorse)
  haveBadDay();
```

The condition in parentheses has to evaluate to `true` for the next statement to execute.
* Note the difference between the first (_raining_) and third (_shouting_) examples.
* Since `shoutingAtHorse` is a `boolean`, it is already `true` or `false`.

### Practice Exercise
Some programming languages allow values that do not evaluate to `true` or `false` in conditions. For example, a language may consider `0` to be the same as `false` and `1` to be the same as `true`.

Java is not one of these languages. The condition **must** evaluate to a `boolean` value.

<hr>

[Prev](flow.md) -- [Up](README.md) -- [Next](if-details.md)

