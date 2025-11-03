## Defining an `equals()` Method

It's up to each class to decide what makes one object of a class "equal to" another object.

You'll usually follow some common practices when defining an `equals` method for your class.

* Remember: `equals` should return `false` unless the passed reference meets your criteria for equality to the current object.

### Basic Sanity Checks

#### Check if the passed reference refers to this object.

If the passed reference is a reference to the current object, then of course we are equal.

* This is called the _reflexive_ property of `equals`: an object is always equal to itself.

```java
public boolean equals(Object obj) {
  if ( obj == this ) { return true; }
  return false;
}
```

#### Check for `null`

No existing object can be equal to `null`.

```java
public boolean equals(Object obj) {
  if ( obj == this ) { return true; }
  if ( obj == null ) { return false; }
  return false;
}
```

#### Check the passed object's class

If the current object is a `Giraffe`, there's little chance it is "equal to" a referenced `Automobile` or `Employee` or `String` or even `Animal` object - to be equal to this object the other object needs to specifically be another `Giraffe`.

* Use the `getClass` method (defined in `Object` and inherited by all classes) to determine the passed object's class.

```java
public boolean equals(Object obj) {
  if ( obj == this ) { return true; }
  if ( obj == null ) { return false; }
  if ( obj.getClass() != this.getClass() ) { return false; }
  return false;
}
```

### Compare Object State

Once you know you are comparing another object of the same class, the primary purpose of `equals` is to compare the objects' _state_.

> #### object state
> The identifying properties of an object, and their values.

In simple terms, an object's state consists of the values of the instance fields that define the object.

* Remember that the parameter passed to `equals` is of type `Object`, so you'll need to cast the reference to the current class in order to compare fields.

```java
public boolean equals(Object obj) {
  if ( obj == this ) { return true; }
  if ( obj == null ) { return false; }
  if ( obj.getClass() != this.getClass() ) { return false; }
  MyClass other = (MyClass) obj;
  // Now we can compare fields of "this" and "other" to determine equality.
  return false;
}
```

### Drill
> `EqualsAndHashcode/com.example.equalsandhashcode.drills.TestNamedObject`
> * Look at the `NamedObject` class and the `TestNamedObject` class.  What will be printed when you run `TestNamedObject`?
> * In `NamedObject`, create an `equals` method that (as shown above) first determines if the passed parameter is a reference to another `NamedObject`, and if so compares its `name` field to the current object's `name`.
>
> (Solution: _NamedObject.java_)

<hr>

[Prev](objectEquals.md) | [Up](README.md) | [Next](determiningEquality.md)

