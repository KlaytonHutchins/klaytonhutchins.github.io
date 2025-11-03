## Declaring an Interface

Like a class, an interface is declared in a `.java` file whose name matches the interface name.

An interface is inherently `abstract`.

* It can have `public` or default (package) visibility, not `protected` or `private`.

An interface's methods are inherently `public` and `abstract`.

* The point of an interface is to define publicly-accessible behavior in the form of method signatures.

* The `public` and `abstract` keywords are optional.

  ```java
  public abstract interface Switchable {
    public abstract void turnOn();
    abstract public void turnOff();
    public abstract boolean isOn();
  }
  ```
  ... can be written as:

  ```java
  public interface Switchable {
    void turnOn();
    void turnOff();
    boolean isOn();
  }
  ```

### Interface Fields

In interface can also declare fields.

```java
public interface Fillable {
  void fill(int amount);
  double GALLONS_PER_LITER = 0.2641720524;
}
```

Interface fields are implicitly `public`, `static`, and `final`.

```java
// Equivalent interface declaration:
public interface Fillable {
  public abstract void fill(int amount);
  public static final double GALLONS_PER_LITER = 0.2641720524;
}
```

Because interface fields are `final`, they must be initialized in their declaration, and their values cannot be changed by implementing classes.

They are typically used to publish constants or options related to the interface an implementing class might find useful.

### Practice Exercise
>
> Class and interface names should be capitalized and use camel case where needed.  Class names should be nouns, but there's no formal convention for naming interfaces.  In practice interface names are often adjectives describing what an implementing class _IS_: `Switchable`, `AutoCloseable`, `Runnable`.  But interface names can also be nouns: `CharSequence`, `List`, `Map`.
>
> In either case, implementing an interface defines an _IS-A_ relationship between the implementing class and the interface.

<hr>

[Prev](interfaces.md) -- [Up](README.md) -- [Next](usingInterfaces.md)

