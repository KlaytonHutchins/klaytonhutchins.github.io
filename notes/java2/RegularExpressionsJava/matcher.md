---
layout: default
title: The Matcher Cla
---

## The Matcher Class

A `Matcher` object allows you to process the results of a regex pattern match

```java
String dataToMatch = "This is the other text that this matcher will match";
Pattern pat = Pattern.compile("th(?:is|at|e other)", Pattern.CASE_INSENSITIVE);
Matcher m = pat.matcher(dataToMatch);
```

The boolean method `find()` searches for a substring that matches the pattern.

```java
if (m.find()) {
  System.out.println("Match found for " + pat.pattern());
  // Match found for th(?:is|at|e other)
}
```

* Successive calls to `find()` will start searching at the next character after the last character of the previous match.

The `Matcher` class has methods that return data about a previous match.

* `group()` returns the string which was previously matched by the pattern.

* `start()` returns the start index of the previous match.

* `end()` returns the index of the last character matched, plus one.

  ```java
  m.reset();
  while (m.find()) {
    System.out.println("Found [" + m.group() + "] at position " + m.start());
  }
  // Found [This] at position 0
  // Found [the other] at position 8
  // Found [that] at position 23
  // Found [this] at position 28
  ```

The `reset()` method sets the starting search position to the first character in the string.

* `reset(String s)` replaces the search text.

`replaceFirst(String s)` returns a new `String` with the first matched pattern replaced by `s`.

`replaceAll(String s)` replaces all occurrences of the pattern with `s`.

### Drill
> `RegularExpressionsJava/com.example.java2.drills.AddressParser`
>
> This code reads lines containing addresses from a file.  A regex is provided that matches part of the address lines.  Add code inside the loop to see if the line was matched, and if so print it.




<hr>

[Prev](pattern.md) -- [Up](README.md) -- [Next](groups.md)

