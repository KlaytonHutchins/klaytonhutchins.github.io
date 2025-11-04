---
layout: default
title: Testing Exception
---


The JUnit 4 way of testing exceptions involved adding `expected` to the `@Test` annotation, and allowing the exception to be thrown from the test method.

```java
@Test(expected=Exception.class)
public void test_withdrawException_throws_Exception_for_negative_input() throws Exception {
  Account a = new Account(100.0);
  a.withdrawException(-0.01);
}
```

The exception is thrown by `withdrawException` so JUnit can catch it.

### `assertThrows` to Test Exceptions
We can now keep the testing contained in our method with `assertThrows`.

`Throwable assertThrows(Class exceptionType, Executable)` - assert that `exceptionType` was thrown, and return it as a `Throwable`.
  * Returning a `Throwable` allows us to examine it.

We place our method call in an `Executable` implemented with a lambda expression.

```java
@Test
@DisplayName("withDrawException throws Exception for negative input")
public void testException() {
  Account a = new Account(100.0);
  Exception e = assertThrows(Exception.class,                       // expected type
                              () ->  a.withdrawException(-0.01)  ); // lambda Executable
  // examine the Exception
  assertEquals("Amount cannot be less than zero.", e.getMessage());
}
```

<hr>

[Prev](assertions.md) -- [Up](README.md) -- [Next](labs.md)

