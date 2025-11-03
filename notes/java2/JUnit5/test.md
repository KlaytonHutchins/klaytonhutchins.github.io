## Test Cases
Below is a test case, created using the default settings.

```java
package com.example.junit5.drills;

import static org.junit.jupiter.api.Assertions.*;

import org.junit.jupiter.api.Test;

class AccountTests {

  @Test
  void test() {
    fail("Not yet implemented");
  }

}
```
There are some things to note, which are different than JUnit 4.

* **Package Imports** - The code for JUnit 5 is in the package `org.junit.jupiter.api`.

* **Visibility** - Classes and methods no longer need to be `public`.

Each test still needs the `@Test` annotation.

<hr>

[Prev](junit5.md) | [Up](README.md) | [Next](before-and-after.md)

