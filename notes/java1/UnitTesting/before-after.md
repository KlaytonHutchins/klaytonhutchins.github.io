---
layout: default
title: `@Before` and `@After`
---

## `@Before` and `@After`

JUnit provides annotations that allow us to execute methods _before_ each test, and _after_ each test.

The methods to execute are not `@Test` methods.
* They are separate methods used to do setup before and cleanup after each test.

### `@Before`

Adding this annotation above a method causes it to execute before _each_ test method is called.

* This guarantees each test method is run in isolation, without being affected by actions of previous test methods.

Use this method for creation and initialization of the object to test.

* Create a field for the object so it is available to all methods.

```java
public class StringManipulatorTests2 {

  private StringManipulator sm;

  @Before
  public void setUp() {
    sm = new StringManipulator();
  }

  @Test
  public void test_addExclamations_add_correct_number_of_exclamations() {
    String input = "hello";
    String expected = "hello!!!";
    String output = sm.addExclamations(input, 3);  // single method call
    assertEquals(expected, output);
  }
  // ...
}
```

### `@After`

Adding this annotation above a method causes it to execute after _every_ test.

This is for cleanup.
* We often explicitly set fields to `null` so Java can reclaim their memory.

```java
public class StringManipulatorTests2 {
  private StringManipulator sm;

  @Before
  public void setUp() {
    sm = new StringManipulator();
  }

  @After
  public void tearDown() {
    sm = null;
  }
  // ...
}
```

### Drill
`UnitTesting/test/com.example.unittesting.drills.TextConverterTests`

Copy code from `TextConverterTests3` if you did not complete the previous drill.
* Create a `private` field for a `TextConverter` instance.
* Change the test class to use `@Before` and `@After` to create the `TextConverter` instance, and set it to `null` when test methods complete.
* Change your `toCaps` methods to use the field instead of creating a local instance.

(Solution: _TextConverterTests4.java_)

<hr>

[Prev](assert.md) -- [Up](README.md) -- [Next](tdd.md)

