---
layout: default
title: `@Override`
---


In Java 5, the designers of the language added the `@Override` annotation.

* This annotation is placed before, or _over_, a method.

```java
public class DataAnalyst extends Employee {
  // ...
  @Override
  public String getInfo() {
    return super.getInfo() + " " + securityClearance;
  }
}
```

`@Override` tells the compiler to check if the method is actually overriding a superclass's method.

  * If the method is not overriding a parent method (meaning it does not have the same signature), you will see a compiler error.

### Practice Exercise
Note that `@Override` does not _make_ the method an overriding method. It only allows the compiler to ensure that what we expect to be an override really is.

This annotation keeps us from accidentally _overloading_ a method, which could lead to unexpected behavior.
>
> ```java
> public class Employee extends Person {
>   // ...
>   public void executeJob(String data) {
>     System.out.println("Executing job " + data);
>   }
> }
>
> public class SoftwareDeveloper extends Employee {
>   public String produceSoftware() {
>     return "Hello World!";
>   }
>   // NOT AN OVERRIDE - different signature is an "overload"
>   public void executeJob() {
>     System.out.println(produceSoftware());
>   }
> }
> ```

<br >

### Drill
`Polymorphism/com.example.polymorphism.drills.employee.DataAnalyst`
* Add `@Override` over `executeJob(String)`.
* Add `@Override` over `getInfo()`.

`Polymorphism/com.example.polymorphism.drills.employee.DatabaseAdmin`
* Add `@Override` over `executeJob(String)`

`Polymorphism/com.example.polymorphism.drills.employee.SoftwareDeveloper`
* Add `@Override` over `executeJob(String)` and `getInfo()`.

`Polymorphism/com.example.polymorphism.drills.employee.Employee`
> * Add `@Override` over `getInfo()`.
> * Try to add `@Override` over `executeJob(String)`.
>   * Determine why this does not work.
>   * Remove the annotation.
>
> (Solution: _Employee3.java_, _DataAnalyst3.java_, _DatabaseAdmin3.java_, _SoftwareDeveloper3.java_)

<hr>

[Prev](override.md) -- [Up](README.md) -- [Next](override-rules.md)

