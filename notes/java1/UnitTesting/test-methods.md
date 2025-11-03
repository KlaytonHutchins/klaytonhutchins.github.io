## Writing `@Test` Methods

A test class itself does not do anything. We need methods for JUnit to run.

### `@Test` Annotation

All test methods must have the _annotation_ `@Test` before them. This tells JUnit to run this method.

> #### annotation
> A marker in source code that provides data about the program. It is read by the compiler or the program using the code. Examples:
>
> * `@Override`
> * `@Test`
> * `@SuppressWarnings`

### Method Purpose

Each test method should call one of the methods of the class being tested, and usually test for one specific thing.

The test method tests a single application method's result.

```java
@Test
public void test_addExclamations_add_correct_number_of_exclamations() {
  StringManipulator sm = new StringManipulator();
  String input = "hello";
  String expected = "hello!!!";
  String output = sm.addExclamations(input, 3);  // single StringManipulator method call
  assertEquals(expected, output);
}
```

### Naming, Return Type, and Parameters

Name the method using *snake_case* or *camelCase* (snake case is easier to read).

The method should include which method it tests, and what condition it is testing - long, descriptive method names are fine.

Test method names usually begin with `test` (which was a requirement from an older version of JUnit, and has become convention now.)

Return type is always `void`, and the test method takes no parameters.

```java
@Test
public void test_convertToArray_splits_String_into_array_on_char(){
  // ...
}
```

### Method Body

The method body will set up test conditions, and call a single method.

It compares an expected result to the method's actual result using JUnit `assert` methods.

* These methods say whether a test passes or fails.

```java
@Test
public void test_addExclamations_add_correct_number_of_exclamations() {
  StringManipulator sm = new StringManipulator();
  String input = "hello";
  String expected = "hello!!!";
  String output = sm.addExclamations(input, 3);
  assertEquals(expected, output); // assert statement
}
```

### Methods Are Independent

Test methods _never_ depend on each other.

* We cannot guarantee the order in which JUnit will run test methods.
* Test method _A_ cannot depend on some effect of test method _B_.

### Drill
In this drill you will be creating methods in `TextConverterTests` to test the `TextConverter` methods. The purpose is to name the methods correctly, and remember to annotate them with `@Test`.
`UnitTesting/src/com.example.unittesting.drills.TextConverter`

`UnitTesting/test/com.example.unittesting.drills.TextConverterTests`
> * `toCaps`
>   * returns `null` for a `null` input String.
>   * returns all caps version of input String.
> * `removeOuterWhitespace`
>   * returns `null` for a `null` input String.
>   * returns String with outer whitespace removed.
>   * returns String with inner whitespace intact.
> * `concatStrings`
>   * returns `null` for a `null` input String.
>   * returns empty String for no input.
>   * returns empty String for empty String input.
>   * returns single String same length as input String
>   * returns two Strings concatenated without extra whitespace.
>   * returns two Strings concatenated with whitespace intact.
>
> (Solution:_TextConverterTests2.java_ )

<hr>

[Prev](test-class.md) -- [Up](README.md) -- [Next](assert.md)

