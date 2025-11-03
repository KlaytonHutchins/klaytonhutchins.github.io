## `Exception`s and Inheritance

### Catching Exceptions in a Hierarchy

When an exception occurs in a `try` block, control jumps to the first `catch` block that matches the exception's type.

```java
private static void mayCrash() throws FileNotFoundException { /*...*/ }
```
* `FileNotFoundException` extends `IOException`, which extends `Exception`.

  ```java
  try {
    mayCrash();
  }
  catch (IOException e) {
  }
  ```
  * A `FileNotFoundException` IS-A `IOException`, so this `catch` matches the exception type and will catch the exception.

`catch` blocks for exceptions in the same hierarchy must appear in order from the most specific to the least.

```java
try {
  mayCrash();
}
catch (FileNotFoundException e) {
  System.err.println("File was not found.");
}
catch (IOException e) {
  System.err.println("An I/O exception occurred.");
}
catch (Exception e) {
  System.err.println("Some non-I/O exception occurred.");
}
```

* A `catch` for a subclass appearing _after_ a `catch` for one of its superclasses would be unreachable, and will not compile.

  ```java
  try {
    mayCrash();
  }
  catch (IOException e) {
    System.err.println("An I/O exception occurred.");
  }
  catch (FileNotFoundException e) { // WILL NOT COMPILE
    //  Unreachable catch block for FileNotFoundException.
    //  It is already handled by the catch block for IOException
    System.err.println("File was not found.");
  }
  catch (Exception e) {
    System.err.println("Some non-I/O exception occurred.");
  }
  ```

* `catch` blocks for exceptions in different inheritance hierarchies can appear in any order.

### Exceptions and Method Overriding

Recall that a method _overrides_ a superclass method if:

1. The method has the **same signature** - method name, and number, type, and order of parameters - as the superclass method.
2. The method has **at least the same visibility** - `public`, `protected`, etc. - as the superclass method.
3. If the method returns a value, its **return type is the same, or a subclass** of the superclass method's return type.

   An additional rule for method overriding involves exceptions:

4. The subclass method declares **no new or more general checked** exceptions than the superclass method.

```java
public class SuperClass {
  public float someMethod(int i, String s) { /*...*/ }
}
```
```java
public class SubClass extends SuperClass{
  @Override
  public float someMethod(int i, String s) throws IOException { // WILL NOT COMPILE
    // Exception IOException is not compatible with throws clause in SuperClass.someMethod(int, String)
    /*...*/
  }
}
```

This is because code using a superclass reference to call the overridden method would have to deal with an unexpected exception.

```java
SuperClass subObj = new SubClass();
methodTakingSuperClassRef(subObj);
```
```java
private static void methodTakingSuperClassRef(SuperClass obj) {
  obj.someMethod(42, "Hello"); // Dynamic (polymorphic) - calls the SubClass method.
}
```

A subclass can declare the same, or a more specific (descendant) exception as the superclass method.

```java
public class SuperClass {
  public void otherMethod(double d) throws IOException { /*...*/ }
  //...
}
```
```java
public class SubClass extends SuperClass{
  @Override
  public void otherMethod(double d) throws FileNotFoundException { /*...*/ }
  //...
}
```

If the subclass doesn't throw a checked exception, it can declare no exceptions at all.

```java
public class SubClass2 extends SuperClass{
  @Override
  public void otherMethod(double d) { /*...*/ }
  //...
}
```

<hr>

[Prev](throw.md) -- [Up](README.md) -- [Next](finally.md)

