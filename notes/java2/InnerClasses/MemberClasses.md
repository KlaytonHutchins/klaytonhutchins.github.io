## Member Classes

```java
public class TopLevel {
  // Member class
  class Inner {

  }
}
```

> #### member class
> A class defined within an enclosing class.


Member classes are defined at the same level as other fields and methods (i.e. _members_) of the class.

### Enclosing Class Access
A method in the member class can use its own data *and* the data in the enclosing instance (including `private` fields), implicitly, without any special syntax.
* This is a great reason to use any inner class - `private` data access.

```java
public class OuterWithMember {

  private String field;

  private class MemberClass {
    public void method() {
      System.out.println(field);  // Accessing enclosing class's field
      //...
    }
  }
}
```

Every instance of the (non-`static`) member class has an internal reference to the enclosing object, `Outer.this`.
* Member class methods can use this reference to explicitly refer to the outer class's fields.

```java
public class OuterWithMember {

  private String field;

  private class MemberClass {
    public void method() {
      System.out.println(field);  // Accessing enclosing class's field

      System.out.println(OuterWithMember.this.field); // Explicit access
    }
  }
}

```
This syntax is only necessary for explicit access to shadowed fields or methods.

### Creating a Member Class Instance Outside the Enclosing Class
You must specify an enclosing instance when creating a member instance from another class.

```java
Outer out = new Outer();
Outer.Inner in = out.new Inner();
          //variable.new
```
This only works if the member class is visible outside the enclosing class.


### Examples

The `Outer` class has an inner class `Inner`, which has a `toString` accessing both the outer and inner class fields.

```java
// Member Inner Class
public class Outer {
  private int outerField;

  public void aMethod() {
    Inner in = new Inner();
    System.out.println(in.toString());
  }

  protected class Inner {
    private int innerField;
    public String toString() {
      // explicit access to outerField
      //return "o: " + Outer.this.outerField + " i: "+ innerField;
      // implicit access to outerField
      return "o: " + outerField + " i: " + innerField;
    }
  }
}
```

```java
public class OuterUsage {
  public static void main(String[] args) {
    Outer out = new Outer();
    out.aMethod();
  }
}
```

This example shows using the `protected`
member inner class.
```java
// Use a Member Inner Class
public class TestInner {
  public static void main(String[] args) {
    Outer out = new Outer();
    Outer.Inner in = out.new Inner();
    System.out.println(in);
  }
}
```

### Practice Exercise
> We can declare member classes with the `static` keyword. This makes them top-level classes.
>
> Like `static` methods, a `static` member class cannot access instance members of its outer class.
>
> According to Oracle, "In effect, a static nested class is behaviorally a top-level class that has been nested in another top-level class for packaging convenience."
>
> https://docs.oracle.com/javase/tutorial/java/javaOO/nested.html

<br >

### Drill
> `InnerClasses/com.example.innerclasses.drills.Outer`
>
> * Change the visibility of the member class `Inner` to `private`. What happens? Why?
> * Change visibility back to `protected`.

<hr>

[Prev](InnerClasses.md) -- [Up](README.md) -- [Next](LocalClasses.md)

