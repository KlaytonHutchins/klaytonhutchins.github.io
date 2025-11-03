## Labs
These labs are designed to use a `switch` statement.


1. Write a program that asks for a temperature and scale. Use a `switch` statement and take advantage of fall through.

   * If the scale is `C`, `c`, `Celsius`, or `celsius`, convert the number from Celsius to Fahrenheit with the formula `Fahrenheit = (9.0/5.0 Celsius) + 32`.
   * If the scale is `F`, `f`, `Fahrenheit`, or `fahrenheit`, convert the number from Fahrenheit to Celsius with the formula `Celsius = 5.0/9.0 (Fahrenheit - 32)`.
   * Depending on the scale, the output should look like `32 degrees Fahrenheit is 0 degrees Celsius`.
   * If the scale is invalid, print an error message.

   (Solution: _IfCelsFahrSwitch.java_)

1. Write a simple calculater program.

   * Ask the user to enter two numbers, reading them into two `double` variables.
   * Ask the user to enter an operation: `+`, `-`, `*`, `/`, or `%`.
   * Use a switch to determine which operation they entered, and output the correct result.
   * If an invalid operation is entered, output "Operation not valid".
   * Use fall-through to allow a variety of valid input for each operation, such as `*`, `times`, `multiply`, etc., calculating the result in only one place for each type of operation.

   (Solution: _CalculatorSwitch.java_)

<hr>

[Prev](switch-when.md) | [Up](README.md)

