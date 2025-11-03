---
layout: default
title: Lab
---

## Labs
In these labs we will write test cases in existing test classes. Our test cases will call other classes' methods and ensure that those methods throw exceptions.

1. This lab uses `src/com.example.exceptionsjunit.reference.Calculator` and `test/com.example.exceptionsjunit.reference.CalculatorTests`. Copy each class into your `com.example.exceptionsjunit.labs` packages - this package must exist in both the `src` and `test` source directories. (You will have to fix package declarations in the files after pasting.)
   * Integer division by zero is illegal and will throw `ArithmeticException`. Add a test case for this to `CalculatorTests` using `expected`.
   * Add the same test using try/catch.

   (Solution: _CalculatorTests.java_)

2. The `src/com.example.exceptionsjunit.reference.StringReplacer` class has two methods. Each throws a `BadInputException`.

   * Based on the code in `StringReplacer`, add test cases to `test/com.example.exceptionsjunit.reference.StringReplacerTests` that verifies that these exceptions are thrown.

   (Solution: _StringReplacerTests.java_)

<hr>

[Prev](trycatch-exceptions.md) -- [Up](README.md)

