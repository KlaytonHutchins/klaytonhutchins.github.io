---
layout: default
title: Roman Numeral
---

### Roman Numerals

#### Application Overview

You are going to make an application that translates Hindu-Arabic Numerals (i.e. 1,2,3) into Roman Numerals (i.e. I, II, III).

You will build up the logic user story by user story to allow for larger and larger numbers to be converted. Don't try to jump ahead too fast, make sure that each step is working, and that the previous user stories are still working correctly after you've moved onto the next solution.

You will create the class `com.example.translation.RomanNumeralTranslatorImpl`. It will implement this interface:

```java
public interface Translator {
  String translateWord(String word);
}
```

(Note: you can copy-paste the interfaces's source code, above, into your `com.example.translation` package in _Package Explorer_, and _Eclipse_ will create the file for you.)

You will use JUnit tests to confirm your translation works.  A starting set of JUnit tests is provided in [RomanNumeralTranslatorImplTests.java](resources/RomanNumeralTranslatorImplTests.java).  As you work on larger and larger numbers, add additional test cases (you don't need to test every possible number, obviously.)

#### Prerequisites

Implement a `RomanNumeralTranslatorImpl` class that overrides `String translateWord(String)` so that the test methods all pass.

#### User Story #1

The user is asked to input a number less than 10.

#### User Story #2

The user is presented with the Roman Numeral which corresponds to the number they entered.

#### User Story #3

If the user inputs non-integer text, their original text is returned.

#### User Story #4

User is re-prompted to enter a number up to 100.

#### User Story #5

User is re-prompted to enter a number up to 1,000.

### Stretch Goals

* User is re-prompted to enter a number over 1,000,000.

* Now that you understand the logic to go from numbers to numerals, can you do the reverse? Take Roman Numerals as input and convert them into Hindu-Arabic Numbers.

<hr>

[Up](../README.md)
