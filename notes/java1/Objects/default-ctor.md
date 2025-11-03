## The Default Constructor

You may have noticed that our original `Sphere3` class did not have constructors defined, but we were able to call `Sphere3 sphere = new Sphere3();`.

When we do not provide _any_ constructors, Java will provide a no-argument constructor that we can call.

This constructor is called the _default constructor_.

* It is "default" because Java created it.

It's as if Java added this to our `Sphere3` class.

```java
public Sphere3(){

}
```

If we define a constructor in a class, Java will no longer provide a default constructor.

#### This is important:
If we provided a one-arg constructor to `Sphere3`, like below...

```java
public Sphere3(double r){
  radius = r;
}
```
...we would no longer be able to call `Sphere3 sphere = new Sphere3();` _because there is no longer a no-arg constructor_.

### Practice Exercise
> The _default constructor_ is not the same as the _no-arg constructor_. They both have no arguments, but **Java** defines the default constructor. **We** define no-arg constructors.

<hr>

[Prev](constructor.md) | [Up](README.md) | [Next](heap.md)

