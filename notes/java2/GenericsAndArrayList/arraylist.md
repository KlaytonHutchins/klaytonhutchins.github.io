---
layout: default
title: The `ArrayList` Cla
---


The `java.util.ArrayList` class is a resizable array.
* It uses zero-based positional indexes.
* It is ordered, just like an array.
* It can grow and shrink as elements are added or removed.

### Creating an `ArrayList`

`ArrayList` is part of the `java.util` package, so it is best to import the class and refer to it by its class name.

```java
import java.util.ArrayList;
```

`ArrayList` is a class, so we can declare a variable and call a constructor - like any other class.
* Note: `ArrayList` DOES NOT use `[]`.

```java
ArrayList list = new ArrayList();  // An ArrayList to hold Objects
```

We can _add_ any type of `Object` to this `ArrayList`, but this is dangerous when it comes time to get an `Object` from the list.

We must either check the type of `Object` at each index using `instanceof`, or hope and assume that the `ArrayList` contains what we expect.

* If the `ArrayList` has a `String`, but we expect an `Integer`, we will get a `ClassCastException`.

  ```java
  package com.example.generics.examples;

  import java.util.ArrayList;

  public class DangerousArrayList {

    public static void main(String[] args) {
      ArrayList listOfInts = new ArrayList();
      listOfInts.add(2);
      listOfInts.add(4);
      listOfInts.add(6);
      listOfInts.add(8);
      listOfInts.add("Who do we appreciate?");
      sumList(listOfInts);
    }

    public static int sumList(ArrayList list) {
      int sum = 0;
      for (int i=0; i < list.size(); i++) {
        // Cast to Integer because that's what the method expects
        Integer value = (Integer) list.get(i);
      }

      return sum;
    }
  }
  ```

  ```
  java.lang.ClassCastException: java.lang.String cannot be cast to java.lang.Integer
  ```

We fix this by declaring the `ArrayList` with a _type argument_ `< >`.

### `<Type>` to Declare an `ArrayList`'s Contents
When we declare the `ArrayList`, we tell Java what type of `Object` it can hold by including that type of `Object` in `< >`.

```java
ArrayList<String> strList;  // An ArrayList to hold Strings
```
* This tells the compiler to keep us from adding anything but a `String` to `strList`.
* The compiler will also ensure we only try to get `String`s out of this list.

To instantiate the `ArrayList`, we use `new` with the constructor, as usual, but also add the `<>`.
* We can repeat the type in `<>`, or just use the `<>` itself.
```java
ArrayList<String> strList;

strList = new ArrayList<String>();
// or...
strList = new ArrayList<>();
```

### Practice Exercise
> Imagine the `< >` like the `( )` in a method call.
>
> When we declare that the type of a variable is `ArrayList`, we also pass what type of objects it can hold in `< >`.
> ```java
> ArrayList<String> strList;
> ```
>
> When we call the constructor, we use `<>` before any data passed to the constructor in `()`.
> ```java
> strList = new ArrayList<>();
> ```
>

<br >

### Drill
> `GenericsAndArrayList/com.example.generics.drills.ArrayListExample`
>
> (Note: make sure to import `ArrayList` from the `java.util` package.)
> * Declare and instantiate an `ArrayList` to hold `String`s. Use the _type argument_ `<String>` in the constructor call.
> * Declare and instantiate an `ArrayList` to hold `Double` objects. This time use the `<>` shortcut in the constructor call.
> * Try to declare an `ArrayList` to hold `double` primitives (not `Double` objects). What happens?
> * Now try declaring an `ArrayList` _without_ type arguments. What is the warning Eclipse gives you?
> * What combinations of `<>` and `<String>` can you put on either side of the `=`, and still have the code compile?
>   * `ArrayList<String> list1 = new ArrayList();`?    
>   * `ArrayList list2 = new ArrayList<>();`?
>   * `ArrayList<> list3 = new ArrayList();`?

<br >

### Practice Exercise
> Type arguments were added in Java 5 to make your programs safer, so it is best to use them. However, as you saw in the previous drill, the code will still compile if you don't use them.

<hr>

[Prev](arrays.md) -- [Up](README.md) -- [Next](parameterized-types.md)

