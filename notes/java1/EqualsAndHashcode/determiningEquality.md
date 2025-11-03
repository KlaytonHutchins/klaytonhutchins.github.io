## Determining Equality

It's up to each class's designer to determine what it means for an instance to be "equal to" another object, by coding the comparisons used in the class's `equals` method.

Often this consists of comparing the values of all the instance fields of the two objects.

* `==` equality for primitive integer-type and boolean instance fields.

  * `float` and `double` usually should not be compared for exact equality with `==`, since two "equal" values as far as your class is concerned might have slightly different fractional values due to roundoff error.

    * One trick is to compare two floats to see if they're "close enough":

      ```java
      double d1 = 3.1415926535897932384626433;
      double d2 = 3.14159;
      System.out.println(d1 == d2);                     // false
      System.out.println( Math.abs(d1 - d2) < .00001 ); // true
      ```

* `.equals()` equality for reference instance fields.

  * If both objects have a `null` for a given reference field they might still be considered equal.

* `static` fields are not considered part of an object's state.

The `equals` method is important throughout Java, and when writing yours you are expected to follow a contract:

### Practice Exercise
> The equals method implements an equivalence relation on non-null object references:
>  
> * It is _reflexive_: for any non-null reference value `x`, `x.equals(x)` should return `true`.
> * It is _symmetric_: for any non-null reference values `x` and `y`, `x.equals(y)` should return `true` if and only if `y.equals(x)` returns `true`.
> * It is _transitive_: for any non-null reference values `x`, `y`, and `z`, if `x.equals(y)` returns `true` and `y.equals(z)` returns `true`, then `x.equals(z)` should return `true`.
> * It is _consistent_: for any non-null reference values `x` and `y`, multiple invocations of `x.equals(y)` consistently return `true` or consistently return `false`, provided no information used in `equals` comparisons on the objects is modified.
> * For any non-null reference value `x`, `x.equals(null)` should return `false`.<sup>1</sup>

### `equals` and Inheritance

A subclass doesn't have access to private fields of a superclass, so a subclass `equals` should call `super.equals()` to perform comparison of private superclass fields.

```java
public class Product {
  private int id;
  String name;
  public boolean equals(Object obj) {
    if (this == obj) return true;
    if (obj == null) return false;
    if (this.getClass() != obj.getClass()) return false;
    Product other = (Product) obj;
    if (this.id != other.id) return false;
    if (this.name == null) {
      if (other.name != null)
        return false;
    }
    else if (!this.name.equals(other.name))
      return false;
    return true;
  }
  // ...
}
```

```java
public class RatedProduct extends Product {
  private int rating;
  public boolean equals(Object obj) {
    if (this == obj) return true;
    if (!super.equals(obj)) return false; // Compare private superclass fields
    if (this.getClass() != obj.getClass()) return false;
    RatedProduct other = (RatedProduct) obj;
    if (this.rating != other.rating) return false;
    return true;
  }
  //...
}
```

### Choose Fields to Compare

You don't necessarily have to include all instance fields in your `equals` method.

* For example, you application may have a `User` class where each user is identified by their unique email address, but also has a name, screen name, creation date, and other properties.

  * In this case, you might decide it makes sense to only compare the email field in `equals`, or maybe email and creation date.

### Practice Exercise
> In Java, _serialization_ is when an object is converted to a stream of data that can be written out and saved, to be read in again later and converted back into an object.  This isn't very common, and there are specific declarations and requirements for setting up a class for serialization.
>
> In a serializable object, an instance field that isn't considered part of an object's state (such as an instance field only used in internal calculations, or that is derived from other instance fields) can be declared with the keyword `transient` to indicate its value should not be included in the serialization output.  The author of the class would also leave these fields out of its `equals`.

[1] https://docs.oracle.com/javase/8/docs/api/java/lang/Object.html#equals

<hr>

[Prev](definingEquals.md) | [Up](README.md) | [Next](hashCode.md)

