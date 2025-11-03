## Labs

1. Write a program with a method that calculates a power — a base number raised to the power of an exponent. The method should take two parameters: a double (the base) and an int (the exponent). The method should return a double: the base raised to the power of the exponent. In the `main` method, prompt the user to enter the base and the exponent; use the method to perform the calculation; then print the result returned by the method. (Do not use `Math.pow(double, double)` in your solution.)

   (Solution: _PowerMethod.java_)

2. We will be writing several methods in one class.

   1. Write a method named `calculateTriangle` to calculate the "n<sup>th</sup> triangle" for a given `n`. The triangle of a number `n` is `1 + 2 + ... + n`. For example, calculating the triangle of `5` is ` 1 + 2 + 3 + 4 + 5` and the result is `15`. The method will take an integer and return an integer. (Do not use the formula `n * (n + 1) / 2` in your solution.)
   2. Write a method named `getNumber` that prompts the use to enter a number. It will take no parameters, but will prompt the user to enter a number. The method will return the integer the user entered.
   3. Call `getNumber` and your `calculateTriangle` method from (1) in `main`. Print the returned number. Now test your program. The `main` method below may help with the organization of your class.

      ```java
      public static void main(String[] args) {
        //Call the method to get user data

        //Use the data to get triangle

        //Output the triangle
      }
      ```

      (Solution: _TriangleCalc.java_)

   4. Write another method named `calculateTriangleString` to return a `String` representing the addition for an n<sup>th</sup> triangle. For example, for the input `5`, the method would return `1 + 2 + 3 + 4 + 5`. Call the method from `main` after you output the triangle of a number. Test your program.

      (Solution: _TriangleCalcString.java_)

3. We will write overloaded test methods in our class from (2) to test triangle calculation.

   1. Write a method called `testEquals`, which returns a `boolean`. The method will have two `int` parameters. The first parameter is the expected value. The second is a test value. If the two values are equal, print `Passed` and return `true`. If they are not equal, print `Failed: expected X but was Y` (where `X` and `Y` are the actual values of the parameters) and return `false`.
   2. Comment out all code in `main`. Call your `calculateTriangle` method in `main`, and use the returned value in a call to `testEquals`. Do this method call with several values, and make sure you do so with a value that would cause `testEquals` to fail.

      (Solution: _TriangleCalcTest.java_)

   3. Write a `testEquals` method with two `String` parameters. Use it to test the output of your `calculateTriangleString` Remember to use `.equals()` when testing the equality of `String` data.
      (Solution: _TriangleCalcStringTest.java_)

4. Review all vocabulary words from this section.

<hr>

[Prev](overloading.md) | [Up](README.md)

