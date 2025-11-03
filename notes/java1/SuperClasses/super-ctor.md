---
layout: default
title: Constructors and Inheritance
---

## Constructors and Inheritance
Recall that a class can call its own constructors using `this()`.

```java
public Car(String make, String model, String color, int numberOfWheels, double purchasePrice) {
  this.make = make;
  this.model = model;
  this.color = color;
  this.numberOfWheels = numberOfWheels;
  this.purchasePrice = purchasePrice;
}

public Car(String make, String model, String color, int numberOfWheels) {
  this(make, model, color, numberOfWheels, 0.0);
}
```

A subclass can call a superclass's constructors using `super()`.

```java
public class SuperClass {
  private String field;

  public SuperClass(String field) {
    this.field = field;
  }
}
```

```java
public class SubClass extends SuperClass {
  public SubClass(String field) {
    super(field);
  }
}
```

`SubClass` calls `SuperClass`'s one-arg constructor, and passes `field`.

![super() constructor call](images/super-ctor.png)

This is a special method call, just like `this()`, which allows us to pass data when an object is being created.

### Drill
`DataAnalyst` and `Employee` use field access or setters to set superclass fields.
> ```java
> public Employee5(String firstName, String lastName, int age,
>       String title, double salary) {
>   this.firstName = firstName;
>   this.lastName = lastName;
>   this.age = age;
>   this.title = title;
>   this.salary = salary;
> }
>
> public DataAnalyst3(String securityClearance, String firstName, String lastName, int age, String title, double salary) {
>   this.setSecurityClearance(securityClearance);
>   this.setFirstName(firstName);
>   this.setLastName(lastName);
>   this.setAge(age);
>   this.setTitle(title);
>   this.setSalary(salary);
>  }
> ```
> * Change each of your classes to set their parent class's fields by passing arguments to their parent class's constructor using `super()`.
>
> (Solution: _Employee6.java_, _DataAnalyst4.java_, _EmployeeApp5.java_)

<hr>

[Prev](super.md) -- [Up](README.md) -- [Next](super-rules.md)

