## Throwing Your Own Exceptions

You can create an `Exception`, or any other `Throwable`, like you create any object: using the `new` operator with the `Exception` constructor.

```java
Exception ex = new Exception("Something went wrong");
```

* Use both the exception class and its message to provide information about the condition you are responding to.

  ```java
  IllegalArgumentException iae = new IllegalArgumentException("Amount cannot be less than zero.");
  ```

The `throw` keyword takes a `Throwable` object as its operand, stopping execution immediately and propagating the `Throwable` to the call stack.

```java
public void withdraw(double amount) {
  if (amount < 0.0) {
    throw new IllegalArgumentException("Amount cannot be less than zero.");
  }
  balance -= amount;
}
```

### Throwing Checked Exceptions

When you throw a checked exception, your method must declare it.

```java
public void withdrawException(double amount) throws Exception {
  if (amount < 0.0) {
    throw new Exception("Amount cannot be less than zero.");
  }
  balance -= amount;
}
```

* Callers of this method must either handle it with `try`/`catch`, or declare they also throw it.

### Practice Exercise
> A method can declare it throws a runtime exception:
> ```java
> private static void mayCrash2() throws RuntimeException { /*...*/ }
> ```
> This does not make this a checked exception, or require callers to catch or declare it.  While legal, methods don't normally declare `RuntimeException` or its descendants.

A method can declare multiple exceptions, as a comma-separated list after `throws`.

```java
private void printWithdrawalReceipt(Account acct, double amount)
  throws IOException, PrintException {
}
```
* A caller must either catch or declare each declared, checked exception.

  ```java
  try {
    printWithdrawalReceipt(acct, amount);
  }
  catch (IOException e) {
    e.printStackTrace();
  }
  catch (PrintException e) {
    e.printStackTrace();
  }
  ```



<hr>

[Prev](Throwable.md) -- [Up](README.md) -- [Next](exceptionSubclass.md)

