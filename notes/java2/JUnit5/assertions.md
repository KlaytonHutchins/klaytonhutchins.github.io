---
layout: default
title: Assertion
---

## Assertions

The `Assertions` class contains `static` methods for use in test cases.
* This class is in the `org.junit.jupiter.api` package.

### `assertEquals(a, b, message)` and `assertNotEquals`
Check equality or inequality of two things.

This has changed from JUnit 4; the optional `message` is now the last parameter.

### `assertTrue` and `assertFalse`
These are the same as JUnit 4, but with the message as the last parameter.

### `Executable` Interface and Assertions
A major change in JUnit 5 is that many assertions take an implementation of the `org.junit.jupiter.api.function.Executable` functional interface.

```java
public interface Executable {
  void execute();
}
```

We can use lambda expressions to create these instances.

One such assertion is `assertAll(Executable... executables)`

### `assertAll(Executable... executables)`
This allows us to group assertions.
* Any failures will be reported together.
* This also asserts that all supplied executables do not throw exceptions.

```java
@Test
@DisplayName("Failure Example")
void testDepositing() {
  account.deposit(50);
  assertAll(
      () -> assertEquals(150, account.getBalance())
      ,
      () -> assertEquals(550, account.getBalance()) // fail
      ,
      () -> assertEquals(999, account.getBalance()) // fail
  );
}
```

```
org.opentest4j.MultipleFailuresError: Multiple Failures (2 failures)
	expected: <550.0> but was: <150.0>
	expected: <999.0> but was: <150.0>
```

<hr>

[Prev](display-name.md) -- [Up](README.md) -- [Next](exceptions.md)

