## Constructors

We have been creating objects using the `new` operator and the class name with `()`.

```java
Sphere3 sphere = new Sphere3();
```

The `()` make this look like a method, and it almost is: `Sphere3()` is an example of a _constructor_.

> #### constructor
> A special method we use with `new` to create instances. It has the same name as the class of which it is a member.

### Constructor Parameters

A constructor can take parameters and be overloaded.

We often use parameters to initialize fields.

The class below has two constructors, one of which initializes the `radius` field to the argument passed to the constructor.

```java
public class Sphere4 {
  public static double PI = 3.14159;

  public double radius;

  public Sphere4() {          //NO-ARG CONSTRUCTOR
  }

  public Sphere4(double r) {  //OVERLOADED CONSTRUCTOR
    radius = r;
  }

  public double getVolume() {
    double vol = 4.0 / 3.0 * PI  * radius * radius * radius;
    return vol;
  }

  public static double calculateCircumference(double r) {
    return PI * 2 * r;
  }
}

```
A constructor with no parameters defined is sometimes called a _no-arg_ constructor for the class.

### Practice Exercise
> A constructor **cannot** have a return type. This class appears to define a one-argument constructor, but really just has a method with the same name as the class. This is legal, but don't do it.
> ```java
> public class Item2 {
>   public double cost;
>   
>   public void Item2(double c) {
>     cost = c;
>   }
> }
> ```


### Practice Exercise
> When writing the word _constructor_, we may use the abbreviation _ctor_.

<br />

### Drill
> `Objects/com.example.objs.drills.Dog`
> * Add a constructor with parameters to initialize `breed` and `weight`.
> * Add a constructor with parameters to initialize `name`, `breed`, and `weight`.
> * Create three dog instances and call the `displayDogInfo` method on each `Dog` object.
>
> Do not add a no-arg constructor.

<hr>

[Prev](intro.md) -- [Up](README.md) -- [Next](default-ctor.md)

