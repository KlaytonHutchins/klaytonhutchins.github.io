## Scope

Code blocks define _scope_, which is where a variable is available:

```java
  int i = 0;
  while (i < 5) {
    int iTimesTwo = 2 * i;
    System.out.println(iTimesTwo);
    i = i + 1;
  }
  // iTimesTwo is no longer available, i.e. "out of scope"
  System.out.println("i is still in scope with value " + i);
```

This is true for any code block, such as in an `if` statement.

```java
  boolean theTest = true;
  if (theTest) {
    String ifMessage = "In if block's scope";
  }
  System.out.println(ifMessage);  // DOES NOT COMPILE.
                                  // ifMessage was declared inside the if block
                                  // so it is not available here.
```

<hr>

[Prev](while-steps.md) -- [Up](README.md) -- [Next](do-while.md)

