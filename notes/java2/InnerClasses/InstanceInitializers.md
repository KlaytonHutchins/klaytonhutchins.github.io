---
layout: default
title: Instance Initializer
---

## Instance Initializers

You would typically initialize data members of a class with a constructor.
  * An anonymous class cannot provide constructors, since it has no class name.

Instance initializers allow an anonymous object to be properly initialized.

### Refresher - Instance Initializers
* Any class can contain an instance initializer.
* A stand-alone code block inside a class definition is an instance initializer.
  ```java
  // A top-level class
  public class InstanceInitializerExample {
    private String id;

    // instance initializer
    {
      id = "DEFAULT";
    }

    // ...
  }
  ```
* Multiple instance initializers are allowed; they are run from top to bottom.
  * They run after the superclass constructor, and before the current class's constructor (if it isn't anonymous).

* The initialization of a data member can be performed immediately after the declaration of the variable.
  * This is helpful if a simple assignment won't accomplish the task.

### Examples

```java
// Anonymous Inner Class with instance initializer
public class Outer4 {
  private int outerField;

  public void aMethod() {
    final int localVar = 0;

    Object in = new Object() {
      private int innerField;

      // instance initializer
      {
        innerField = 12;
      }

      public String toString() {
        return "o: " + outerField + " i: " + innerField
            + " l: " + localVar;
      }
    };

    System.out.println(in);
  }

  public static void main(String[] args) {
    Outer4 out = new Outer4();
    out.aMethod();
  }
}
```

The `Runnable` anonymous instance below records the time it was created, and prints the time between creation and the call to `run()`.

```java
Runnable rTimed = new Runnable() {
  private LocalDateTime time;

  // instance initializer
  {
    time = LocalDateTime.now(); // Gets the current moment in time
    System.out.println("Instance created at " + time);
  }

  public void run() {
    // Calculate time between
    Duration d = Duration.between(time, LocalDateTime.now());
    System.out.println("Running " + d + " later...");
  }
};
```


### Drill
> `InnerClasses/com.example.innerclasses.drills.InstanceInitalizerDrill`
>
> * Paste the anonymous `Runnable` instantiation above into `main`.
> * Call `run` on the instance to see what `LocalDateTime` and `Duration` print.
>   * Note: these classes are in the `java.time` package.

<hr>

[Prev](anonymousAndInterfaces.md) -- [Up](README.md) -- [Next](compiling.md)

