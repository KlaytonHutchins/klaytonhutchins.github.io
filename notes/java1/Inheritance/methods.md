## Inheriting Methods

Not only does a subclass inherit the superclass's _fields_, it also inherits the superclass's _methods_.
* The methods exist in the superclass, but the subclass can call them.

We can imagine our `Employee extends Person` class diagram looking like

![Employee can call Person's fields](images/methods.png)

The `Employee` class has all the `Person` fields and methods, but the fields and methods only exist in `Person`.

### Practice Exercise
> It is important to note that constructors are **not** inherited.

<br >

### Drill
> `Inheritance/com.example.inheritance.drills.Employee`
>
> `Employee`'s `getInfo()` method uses `firstName` and `lastName` references to print `Employee` information.
> ```java
> public String getInfo() {
>   return firstName + " " + lastName + " " + age + " " + title + " " + salary;
> }
> ```
> * Change this method to call `getName()`, which is inherited from `Person`, instead of using the `firstName` and `lastName` references.
> * Run `EmployeeApp` to make sure the change works. Now your `Employee` subclass is calling an inherited superclass method.
>
> (Solution: _Employee3.java_, _EmployeeApp2.java_)

Reference: https://docs.oracle.com/javase/tutorial/java/IandI/subclasses.html

<hr>

[Prev](fields.md) -- [Up](README.md) -- [Next](fields-and-methods-labs.md)

