## `assert` Methods

`assert` methods are methods JUnit executes to test whether the actual result of a method meets an expectation.

Most come from the `org.junit.Assert` class, and we import them using `static` import statements.

### Practice Exercise
When an `assert` method fails, the actual result is an `AssertionError`, a Java class that is _not_ a JUnit class.

### assertEquals(expected, actual)

This overloaded method allows us to test if two objects or primitives are equal.

```java
import static org.junit.Assert.assertEquals;

import org.junit.Test;

public class StringManipulatorTests {
  @Test
  public void test_addCharacters_add_correct_number_of_character() {
    StringManipulator sm = new StringManipulator();
    String input = "hello";
    String expected = "hello!!!";
    String output = sm.addCharacters(input, '!', 3);
    assertEquals(expected, output);
  }
  // ...
}
```

This method can handle `null` values without issue.

### Practice Exercise
Order of method arguments is important. Be sure to put the value you _expected_, followed by the _actual_ value the application method returns, because this affects JUnit's output. The test will fail either way, but your output would be misleading.

### assertEquals(expected, actual, delta)

`assertEquals` for `float` and `double` values has an additional parameter, `delta`.

* `delta` is how much difference there can be between the `expected` and `actual` values, to account for inaccuracy in the data types.
* `delta` can usually be a very small value, like `0.0001`.

### assertTrue(boolean) and assertFalse(boolean)

These statements test `boolean` conditions, like the output of a method or a logical statement.

### assertNull(Object) and assertNotNull(Object)

These test whether a `null` value was returned from a method call.

`assertNotNull` is useful when we expect to use an object's methods or fields, like an array's `length`.

```java
@Test
public void test_convertToArray_returns_non_null_array_of_length_four() {
  StringManipulator sm = new StringManipulator();
  String input = "I am a String.";
  String[] outArr = sm.convertToArray(input, " ");
  assertNotNull(outArr);
  assertEquals(4, outArr.length);
}
```

### Practice Exercise
Many `assert` methods are overloaded to add a custom `String` message as the first parameter.

<br >

### Drill
`UnitTesting/test/com.example.unittesting.drills.TextConverterTests`
>
> Copy code from `TextConverterTests2` if you did not complete the previous drill.
> * Complete the `toCaps` methods in the test class. (`toCaps` is the only method in `TextConverter` with full functionality.)
> * Note that you need an instance of `TextConverter` in your test methods. You cannot just call methods.
>
> (Solution: _TextConverterTests3.java_)

<hr>

[Prev](test-methods.md) -- [Up](README.md) -- [Next](before-after.md)

