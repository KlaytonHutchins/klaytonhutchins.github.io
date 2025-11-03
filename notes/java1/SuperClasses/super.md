---
layout: default
title: Using a Superclass's Methods and Field
---

## Using a Superclass's Methods and Fields
Recall that a class can use the `this` keyword to access its own methods and fields.
```java
public DataAnalyst2(String securityClearance) {
  this.securityClearance = securityClearance;
}
```

`this` is an object's reference to itself.

### The `super` Keyword
Every object has a reference to its parent class's fields and methods: `super`.

To access a superclass's visible methods and fields, we can use `super.`.

`SuperClass` has `public` and `protected` members that subclasses can see.
```java
public class SuperClass {
  protected String protectedField;  // Available to children
  private String privateField;      // Only visible with getters/setters

  public void setPrivateField(String privateField) {
    this.privateField = privateField;
  }

  public String getFields() {
    return protectedField + " " + privateField;
  }
}
```

`SubClass` accesses the `SuperClass` field and method using `super.field` or `super.method()`.

```java
public class SubClass extends SuperClass {
  private String subField;

  public SubClass(String protField, String privField, String subField) {
    super.protectedField = protField;   // refer to parent's field with reference
    super.setPrivateField(privField);   // call parent's method with reference
    this.subField = subField;
  }
  // ...

}
```

### Calling Superclass Methods with the Same Signature
`super` is especially useful if we have a method in the subclass with the same signature (name and parameter list) as a method in the superclass.
* If we want the subclass to use the superclass's functionality, we need `super.`.

`SubClass` calls the `SuperClass` `getFields()` method inside its own `getFields()` method using `super.getFields()`.
```java
public class SuperClass {
  // ...

  public String getFields() {
    return protectedField + " " + privateField;
  }
}

public class SubClass extends SuperClass {
  private String subField;
  // ...

  // Same signature as parent
  public String getFields() {
    return super.getFields() + " " + subField;  // Tell Java to use the parent method here
  }
}
```

`SubClass` defines its own `getFields()` method, but also inherits a `getFields()` method from `SuperClass`.
* Using `super.` declares that `SubClass` is going to use the `SuperClass` version of the method, rather than its own.

![SubClass calling SuperClass method](images/super.png)

### Practice Exercise
A class can only access its parent class's methods with `super.`. It can't access its grandparent class's methods by doing something like `super.super.method()`.

Note: "grandparent class" is not a phrase we use in programming, it's here to illustrate a relationship.

### `super` Cannot Be Used in `static` Methods
`super`, like `this`, refers to an instance of a class.
* `static` methods are part of a class, not an instance, so calling `super` in a `static` method results in a compiler error.

Resource: https://docs.oracle.com/javase/specs/jls/se8/html/jls-15.html#jls-15.11.2


### Drill
`SuperClasses/com.example.inheritance.drills.Employee`
>
> `Employee`'s `getInfo()` method is duplicating the functionality in `Person`'s `getInfo()` method.
>
> ![Employee duplicates Person getInfo](images/super2.png)
>
> We will fix this to avoid duplicating work.
> * Change `Employee`'s `getInfo()` method to call `Person`'s `getInfo()` method, and add `Employee` fields.
> * Change `DataAnalyst` to call `Employee`'s `getInfo()` method and add `securityClearance`.
> * Run `EmployeeApp` to make sure the change works. Now you are not duplicating work in a subclass.
>
> (Solution: _Employee5.java_, _DataAnalyst3.java_, _EmployeeApp4.java_)

<hr>

[Prev](README.md) -- [Up](README.md) -- [Next](super-ctor.md)

