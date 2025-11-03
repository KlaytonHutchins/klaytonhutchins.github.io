---
layout: default
title: JUnit and Exception
---

## JUnit and Exceptions
If a method is expected to throw an exception, we need to test that it does.

The `Account` class below throws the unchecked exception `IllegalArgumentException` when a negative withdrawal is attempted.

```java
public class Account {
  private double balance;

  public void withdraw(double amount) {
    if(amount < 0.0) {
      throw new IllegalArgumentException("Amount cannot be less than zero.");
    }
    balance -= amount;
  }
  // ...
}
```

We can test that a method throws an Exception with the `expected` attribute.

Add `expected` to the `@Test` annotation, with the type of exception class.

```java
@Test(expected=IllegalArgumentException.class)
public void test_withdraw_throws_IllegalArgumentException_for_negative_input() {
  Account a = new Account(100.0);
  a.withdraw(-0.01);
}
```

If a method throws a checked exception, we must declare it in the test method.
* The point of `expected` is that an exception is thrown from the method for JUnit to examine.

This method throws `Exception`.
```java
public class Account {
  private double balance;
  // ...
  public void withdrawException(double amount) throws Exception {
    if(amount < 0.0) {
      throw new Exception("Amount cannot be less than zero.");
    }
    balance -= amount;
  }
  // ...
}
```

This method must declare it.
```java
@Test(expected=Exception.class)
public void test_withdrawException_throws_Exception_for_negative_input() throws Exception {
  Account a = new Account(100.0);
  a.withdrawException(-0.01);
}
```

### Drill
> `ExceptionsJUnit/test/com.example.exceptionsjunit.examples.AccountTests`
> * Run the example to see that the tests pass.
> * Change the withdraw amount to a positive number. What happens when you run the program? Change it back.
> * Change the expected exception to `NullPointerException` and run the program. What happens? Change it back.

<hr>

[Prev](README.md) -- [Up](README.md) -- [Next](trycatch-exceptions.md)

