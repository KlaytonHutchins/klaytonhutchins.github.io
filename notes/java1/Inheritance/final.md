---
layout: default
title: `final` Classe
---


We can use the keyword `final` on a class so that other classes will not be able to extend it.

```java
public final class FinalClass {
  //...
}
```

```java
public class FinalSubclass extends FinalClass {  // ERROR, does not compile
  //...
}
```

### Practice Exercise
> The visibility modifier and `final` can also be in the order `final public`. This compiles successfully.
> ```java
> final public class FinalPublicClass {
>   //...
> }
> ```

<br >

### Drill
> `Inheritance/com.example.inheritance.drills`
> * Create a class `TestClass`. It does not need a `main` method.
>   * Try to make `TestClass` extend `System` by adding `extends System`.
>   * Try to make `TestClass` extend `String`.
>   * Try to make `TestClass` extend `StringBuilder`.
>   * Try to make `TestClass` extend `Integer`.
> * It didn't work. Make `TestClass` extend `Object`.

<hr>

[Prev](extends.md) -- [Up](README.md) -- [Next](uml.md)

