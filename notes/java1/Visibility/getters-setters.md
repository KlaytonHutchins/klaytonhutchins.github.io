---
layout: default
title: Getters and Setter
---

## Getters and Setters

We add getters and setters to the _superclass_ to allow subclasses to access `private` superclass fields.

```java
public class Employee2 extends Person {
  private String title;
  private double salary;
  // ...
  public String getTitle() {
    return title;
  }
  public void setTitle(String title) {
    this.title = title;
  }
  public double getSalary() {
    return salary;
  }
  public void setSalary(double salary) {
    this.salary = salary;
  }
}
```

The subclass can now call the inherited getter or setter method to access or change the superclass field.

```java
public class DataAnalyst2 extends Employee2 {
  private String securityClearance;
  // ...

  public String getInformation() {
    return firstName + " " + lastName + " " + age  // protected in Person
        + " " + getTitle() + " " + getSalary()     // visible methods from Employee
        + " " + securityClearance;                 // private in DataAnalyst
  }
}
```

### Validation in Setters
Setters may use validation or data manipulation to ensure that data is acceptable or formatted correctly.

Below, the setter for `hour` ensures the field is not greater than `12`.

```java
public class Clock {
  private int hour;
  private int seconds;
  private long nanoseconds;
  private String amOrPm;

  public void setHour(int h) {
    if (h > 12) {
      h = h - 12;
    }
    hour = h;
  }

  // ...
}
```


### Methods are Inherited, Not Copied
The compiler does not copy superclass methods into the subclass.
* The methods exist only in the superclass.
* Since the methods are part of the superclass, but _callable from the subclass_, the subclass can access the superclass's `private` data.

![Getters and Setters to access private data](images/gettersAndSetters.png)

### Practice Exercise
When we instantiate a subclass, only one object is created in memory.

The new object contains memory allocations for all of the fields in the
subclass, as well as those in the superclass - even the `private` fields it can't access.

You will not have a separate object created for the subclass and the
superclass.

In the Eclipse debugger, we can see that `DataAnalyst` has the `Employee` fields, even though it can't access them directly.

![private fields](images/gettersAndSetters2.png)

Note: even though the `private` superclass fields exist in memory for the object, they are **not** inherited by the subclass, because the subclass _cannot access them directly_.

<br >

### Drill
`Inheritance/com.example.inheritance.drills.Employee`
* Add getters and setters to the `Employee` class.

`Inheritance/com.example.inheritance.drills.DataAnalyst`

(If you did not finish `DataAnalyst`, use the class from the `...solutions` package)
* Fix `DataAnalyst` to use the `Employee` getters in its `getInfo()` method to output salary and title.
* Add a six-arg constructor that uses setters to assign each of the fields in `Person`, `Employee`, and `DataAnalyst`.
* Remove the one-arg `DataAnalyst` constructor.
* Create a `DataAnalyst` in `EmployeeApp` and output its information.
(Solution: _Employee4.java_, _DataAnalyst2.java_, _EmployeeApp3.java_)

<hr>

[Prev](visibility.md) -- [Up](README.md) -- [Next](getters-setters-labs.md)

