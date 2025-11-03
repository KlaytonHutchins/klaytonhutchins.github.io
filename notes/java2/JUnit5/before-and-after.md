---
layout: default
title: Test Case Setup
---

## Test Case Setup

The annotations that designate methods to run _before_ and _after_ each test case have changed with JUnit 5.

### `@BeforeEach`
This method will execute before _each_ test case.
* This was `@Before` in JUnit 4.

```java
@BeforeEach
void setUp() {
}
```

### `@AfterEach`
This method will execute after _each_ test case.
* This was `@After` in JUnit 4.

```java
@AfterEach
void tearDown() {
}
```

### Practice Exercise
> There are annotations for executing methods when a class loads.
> * `@BeforeAll`
> * `@AfterAll`
>
> These methods must be `static`, and execute once.

<br />

### Drill
> `JUnit5/test/com.example.junit5.drills.AccountTests`
>
> * Add a field `private Account account` to your test case.
> * Add a method to instantiate a new `Account` object before each test case.
> * Add a method to set the field to `null` after each test case.
>
> (Solution: _AccountTests2.java_)

<hr>

[Prev](test.md) -- [Up](README.md) -- [Next](display-name.md)

