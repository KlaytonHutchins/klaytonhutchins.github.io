---
layout: default
title: Inheriting Field
---


Inheritance gives a child fields of the parent class.
* The parent class's fields are _passed down_ to the child; the child _inherits_ them from the parent class.
  * This is one of the main reasons to use inheritance, as it keeps us from duplicating code in other classes.

We can imagine our `Employee extends Person` class diagram looking like

![Employee gets Person's fields](images/fields.png)

The `Employee` class has all the `Person` fields, but the fields and methods only exist in `Person`.

### Drill
> `Inheritance/com.example.inheritance.drills.Employee`
> * Add a no-arg constructor to `Employee`.
> * Add a constructor to `Employee` with parameters for `firstName`, `lastName`, `age`, `title`, and `salary`.
>   * Set the fields `firstName`, `lastName`, and `age` the same way as `title` and `salary` - using the `.` operator.
> * Add a method to `Employee` called `public String getInfo()`
>   * Return a `String` containing the object's information in the format `firstName  lastName  age title salary`.
>
> `Inheritance/com.example.inheritance.drills.EmployeeApp`
>
> * Follow the instructions to create `Person` and `Employee` instances, and call methods for each.
> * (Solution: _Employee2.java_, _EmployeeApp.java_)

<hr>

[Prev](uml.md) -- [Up](README.md) -- [Next](methods.md)

