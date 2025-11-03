## Test-Driven Development (TDD)

Test-driven Development (TDD) is a development process where (failing) unit tests are written _before_ a method's functionality is added.

* The class under test has a _stub_ for each method.
  * The method is defined, but doesn't have functionality in the body; it just compiles.
* Each test method tests one feature.
* As test methods are added, just enough code is added to the class to make the test pass.

### Practice Exercise
TDD makes you think about what a method _should do_ before you think about writing tests for what it _already does_.

TDD also keeps you from adding functionality that isn't part of a class's requirements.

The TDD process, in short:

* Write a stub of the application object to be tested, with no implementation code
* Write a test for some requirement
* Run all tests to see if the new one fails
* Write implementation code in the application object
* Run tests
* Fix code
* Repeat

### Drill
`UnitTesting/test/com.example.unittesting.drills.TextConverterTestsTDD`

This drill uses the TDD process. __Do not__ add functionality to each `TextConverter` method until you have completed a `TextConverterTestsTDD` test method for it.
* Follow the instructions in `TextConverterTestsTDD`.

<hr>

[Prev](before-after.md) | [Up](README.md) | [Next](labs.md)

