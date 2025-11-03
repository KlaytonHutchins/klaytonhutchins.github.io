## Labs
In this set of labs we will create JUnit test cases and use Test-Driven Development (TDD).

1. Create a JUnit Test Case for the `com.example.unittesting.labs.Calculator` class, and use TDD to implement test methods and class functionality.

   The `Calculator` class has five methods.
   * `int add(int first, int second)`
   * `int subtract(int first, int second)` - subtracts `second` from `first`
   * `int multiply(int first, int second)`
   * `int divide(int numerator, int denominator)`
   * `double divide(double numerator, double denominator)`

   Be sure to make the test class in the `test` source folder, in the correct package.

   Notes:
   * Clearly, implementing the methods is easy, but use TDD to create test methods first.
   * Be sure to test both `divide` methods, and that the method using `int`s loses any remainder.
   * Do not worry about testing Exceptions (to be explained later) or cases like dividing by zero.

   (Solution: _src/...solutions.Calculator_, _test/...solutions.CalculatorTests_)

   Optional: add a `int modulus(int numerator, int denominator)` method to your class and write test method(s) for it.

2. Create a set of test cases for the `java.lang.String` class.

   Test the following String methods for the listed criteria:
   * contains()
     * `Hello World!` contains `Hello` returns `true`
     * `Hello World!`  contains `hello` returns `false`
   * length()
     * `Hello World!` has length() equal to `12`
   * startsWith()
     * `Hello World!` starsWith `Hello` returns `true`
     * `Hello World!` startsWith `hello` returns `false`
   * toUpperCase()
     * `"Hello World!"` toUppercase returns `HELLO WORLD!`

   (Solution: _StringTests.java_)

<hr>

[Prev](tdd.md) | [Up](README.md)

