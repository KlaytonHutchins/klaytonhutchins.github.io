## Changing Instance Fields

We can initialize fields by passing arguments to a constructor.

```java
Sphere4 sphere = new Sphere4(3.2);
```

So far, we have been able to change the state (fields) of our objects by accessing them directly.
```java
sphere.radius = 1.5;
```

Imagine we have a class with something sensitive, like an `Account` with a `balance` field.

* If any program can change the balance, we could have issues.

  ```java
  package com.example.encapsulation.drills;
  public class Account {
    public double balance;
    public String accountId;
  
    public Account(String aId) {
      accountId = aId;
    }
  
    public Account(String aId, double initialBalance) {
      balance = initialBalance;
      accountId = aId;
    }
  
    public void deposit(double amount) {
      balance = balance + amount;
    }
  
    public void withdraw(double amount) {
      balance = balance - amount;
    }
  }
  ```

  * This is bad practice.

We should not design classes that allow others to "reach into" an object and change its state.

We can solve this by changing the _visibility_ of our fields.


<hr>

[Prev](README.md) | [Up](README.md) | [Next](visibility.md)

