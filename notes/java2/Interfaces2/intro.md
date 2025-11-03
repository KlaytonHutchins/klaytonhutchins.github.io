## Smart Home - Part 2

An interface declares the methods a _concrete class_ (one which we can use to create a `new` object) must have.

Recall the Smart Home, which had several interfaces and implementation classes. For example:

```java
interface Switchable {
  public void turnOn();
  public void turnOff();
  public boolean isOn();
}

public interface Fillable {
  void fill(int amount);
}

public class CoffeeMaker extends KitchenAppliance implements Switchable, Fillable {
  //... Switchable behavior ...

  // Fillable behavior
  private int percentFull;
  public void fill(int amount) {
    percentFull = amount;
  }
}

public class Fan implements Switchable { /*...*/ }

public class GasFireplace implements Switchable { /*...*/ }
```

An `interface` also provides a _type_ for a class. This is useful for collecting objects that share the same behavior (as defined by a common `interface`).

```java
Switchable[] gear = new Switchable[3];
gear[0] = new CoffeeMaker();
gear[1] = new Fan();
gear[2] = new GasFireplace();

for (int i = 0; i < gear.length; i++) {
  // Note: because the reference type is Switchable, only Switchable
  //       methods can be called.
  gear[i].turnOn();
  System.out.println(gear[i] + " turned on.");
}
```

<hr>

[Prev](README.md) | [Up](README.md) | [Next](fields.md)

