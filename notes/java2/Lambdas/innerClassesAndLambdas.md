---
layout: default
title: Lambda Expression
---


Java 8 introduced _lambda expressions_ to simplify programs.

> #### lambda expression
> An anonymous function that you can store in a variable or pass as an argument to a method.

A lambda's purpose is to implement the one method an inner class would implement, without the overhead of writing an entire inner class.

```java
// Inner class
Comparator<Planet> comp = new Comparator<Planet>() {
  @Override
  public int compare(Planet a, Planet b) {
    return a.getOrbit() > b.getOrbit() ? 1 : -1;
  }
};
```

```java
// Lambda
Comparator<Planet> compLambda = (Planet a, Planet b) -> {
  return a.getOrbit() > b.getOrbit() ? 1 : -1;
};
```


A lambda is not a class, but it can replace certain inner classes.

### Practice Exercise
> Lambdas are a shift toward _functional programming_ instead of _object-oriented programming_.
>
> Functional Programming avoids changing-state and mutable (changeable) data.
>
> Inputs are given to a function, it determines an output, and returns the output - but it does not change the input. The function simply calculates an output.

<hr>

[Prev](innerClassesReview.md) -- [Up](README.md) -- [Next](lambdaTranslation.md)

