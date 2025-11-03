## Rules for Overriding

The compiler will perform checks to make sure our overrides are legal.

1. The method must have the **same signature** (name and parameter types, in order) as the method in the parent class.
2. The method must be **at least as visible** or more visible than the parent class's method.
3. If the method returns a value, the **return type must be the same as or a subclass of** the return type of the method in the parent class (known as _covariant return types_).

(Note: We do not have to use `@Override` for the compiler to check these.)

### Practice Exercise
These rules all have to do with polymorphism and using superclass references with subclass objects.
>
> 1. _same signature_ - this is the definition of an override, so it is necessary.
> 2. _at least as visible_ - superclass references are the issue here. Imagine this code.
>   ```java
>   public class Employee extends Person {
>     public void executeJob(String data) {
>       System.out.println("Executing job " + data);
>     }
>   }
>
>   public class VicePresident extends Employee {
>     @Override
>     private void executeJob(String data) {
>       // PRIVATE visibility will not compile    
>     }
>   }
>   ```
>
>   ```java
>   // In another class...
>   Employee e = new VicePresident();
>   e.executeJob("Orders");
>   ```
>   Dynamic binding means the `VicePresident` `executeJob(String)` method is chosen to run, but the method is `private` so it should not be visible outside the class - it's `private` so that no method outside the `VicePresident` class can call it. Java can't let the method run, so the compiler prevents us from getting ourselves in this situation by not allowing us to reduce visibility.
>   
>   The compiler error is: "Cannot reduce the visibility of the inherited method from Employee"
>
> 3. _covariant returns_ - imagine the method
>    ```java
>    public class Organization {
>      public Employee getEmployee() { /* ... */ }
>    }
>    ```
>    and the subclass with an overriding method returning a subclass of `Employee`.
>   ```java
>   public class Department extends Organization {
>     @Override
>     public DataAnalyst getEmployee() { /* ... */ }
>   }
>   ```
>    A caller using an `Organization` reference must be able to depend on `getEmployee()` returning an object that is-a `Employee`.
>   ```java
>   Organization o = new Department();
>   Employee e = o.getEmployee(); // Get an Employee from Organzation "o"
>   ```
>   
>   `Department`'s `getEmployee()` returns a `DataAnalyst` object, and `DataAnalyst` is-a `Employee`, so the code will compile and run.

### `private` Methods Cannot Be Overridden
There is no such thing as overriding a `private` method.
* The subclass cannot see the superclass's `private` method, so it doesn't know there is a method to override.

`Organization` has a `private` method `lookupEmployee`.
```java
public class Organization {
  // ...
  // private method
  private Employee lookupEmployee(int id) { /* ... */ }
}
```

It is legal for `Department` to _redeclare_ this method with the same signature.
* However, using `@Override` would result in a compiler error.

```java
public class Department extends Organization {
  // ...
  //@Override - NO
  public Employee lookupEmployee(int id) { /* ... */ }

}
```

### `static` Methods Cannot Be Overridden
`static` methods are not overridden, because `static` methods do not require dynamic binding.
* Dynamic binding is when a type is determined at _runtime_.
* `static` methods belong to a class, and the class being used with a `static` method call can be determined at _compile-time_.

Reference: https://docs.oracle.com/javase/tutorial/java/IandI/override.html

### Drill
`Polymorphism/com.example.polymorphism.drills.ValidOverrides`
>
> `ValidOverrides` contains commented-out methods that attempt to override `ValidOverridesBaseClass` methods.
>
> For each method in `ValidOverrides`
> * Determine if the method is a valid override, based on the rules for overriding, and add your reasoning in the `Comments:` section.
> * Uncomment the method (and `@Override` if included) to see if you are correct.
> * Look in `solutions.ValidOverrides` for explanations.
>   * The solution methods are spaced far apart, so you can look at each method's solution individually.

<hr>

[Prev](override-annotation.md) -- [Up](README.md) -- [Next](override-labs.md)

