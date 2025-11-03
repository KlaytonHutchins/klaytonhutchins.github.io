## Testing Exceptions with `try` and `catch`
You can test for exceptions within a test method by using a try/catch block and the `fail` method.
* The method under test _should_ throw an exception, so executing any line past the method is a failure.
* The `catch` block does not have to do anything since the code is expected to reach this point.

```java
import static org.junit.Assert.fail;
import org.junit.Test;

public class AccountTests2 {
  // ...
  @Test
  public void test_withdraw_throws_IllegalArgumentException_for_negative_value() {
    Account a = new Account(100.0);
    try {
      a.withdraw(-0.01);
      fail("Expected IllegalArgumentException");
    }
    catch (IllegalArgumentException e) {}
  }
  // ...
}
```
The advantage is that you can call the method several times in the same test method, each with its own try/catch block.

### `fail` on Checked Exception
A test should fail if a method throws a checked exception when it _should not_.
* Adding this kind of automated test ensures that any later change in the code does not break existing functionality.
```java
@Test
public void test_withdrawException_removes_amount_from_balance() {
  Account a = new Account(100.0);
  try {
    a.withdrawException(50.0);
    assertEquals(50.0, a.getBalance(), 0.01);
  }
  catch (Exception e) {
    fail(e.toString());
  }
}
```

<hr>

[Prev](test-exceptions.md) | [Up](README.md) | [Next](labs.md)

