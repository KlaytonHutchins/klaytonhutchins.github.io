## Getters and Setters

A `get` method provides access to a field.

```java
public double getBalance() {
  return balance;
}
```
* We call this a _getter_ because it gets data from an object.

A `set` method modifies the value of a field.

```java
public void setBalance(double bal) {
  balance = bal;
}
```

We add these to objects as we see fit.

* Maybe we do not want a user to set the `balance` directly; we will not create a setter method in our class.

* If data is very sensitive, like a password, we will not supply a getter or setter.

### Conventions

Getter and setter methods have conventions for how we define them.

* The method names are always <code>get<i>PropertyName</i></code> and <code>set<i>PropertyName</i></code>.

  * _`PropertyName`_ is capitalized with camel case.

  _`PropertyName`_ is usually the name of a field, but it doesn't have to be.

* Getters do not take parameters, and return a property value.

  ```java
  public double getBalance() {
    return balance;
  }
  ```

  * For properties of type `boolean` the convention for a getter is to use `isPropertyName` instead of `getPropertyName`.

    ```java
    private boolean overdrawn;

    public boolean isOverdrawn() {
      return overdrawn;
    }
    ```

* Setters have a return type of `void`, take one argument, and set the value of a property.

  ```java
  public void setBalance(double bal) {
    balance = bal;
  }
  ```

### Practice Exercise
>
> A "property" of an object is how an object can determine another object's state. What part of a class would a property be?
>
> If a field is `private`, other classes can't see it, so the field can't be the property.
>
> But if all classes follow the getter and setter convention, the "property" would be _`PropertyName`_ after `get` or `set`, regardless of the field name.
>
> So getters and setters define the "properties" of an object's field.

<hr>

[Prev](encapsulation.md) | [Up](README.md) | [Next](this.md)

