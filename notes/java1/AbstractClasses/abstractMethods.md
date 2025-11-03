## Abstract Methods

An `abstract` method has no body or implementation code.

```java
public abstract void changeBulb();    // Abstract method
public void changeBulb();             // ILLEGAL: This method requires a body instead of a semicolon
public abstract void changeBulb() { } // ILLEGAL: abstract methods do not specify a body
```

Concrete subclasses must implement all inherited `abstract` methods of their superclass.

* A subclass that fails to do so must itself be declared `abstract`.

  ```java
  public abstract class LEDLight extends AbstractLight {
  }
  ```

An `abstract` class can define non-`abstract`, or _concrete_, methods.

```java
public abstract class AbstractLight {
  public abstract void changeBulb();  // Abstract method

  private int lumens;
  public int getLumens() {            // Concrete method
    return lumens;
  }
  public void setLumens(int lumens) { // Concrete method
    this.lumens = lumens;
  }
}
```
* Subclasses can override these (unless they are declared `final` or `private`), but are not required to.

### Practice Exercise
> The numeric wrapper classes extend the `abstract` class `Number`, which defines both `abstract` and concrete methods:
> ```java
> public abstract class Number implements java.io.Serializable {
>     public abstract int intValue();
>     public abstract long longValue();
>     public abstract float floatValue();
>     public abstract double doubleValue();
>     public byte byteValue() {
>         return (byte)intValue();
>     }
>     public short shortValue() {
>         return (short)intValue();
>     }
>   //...
> }
> ```

An `abstract` class is not required to declare any `abstract` methods.

* It can be subclassed, but not instantiated.

<hr>

[Prev](abstractClasses.md) -- [Up](README.md) -- [Next](usingAbstractClasses.md)

