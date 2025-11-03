---
layout: default
title: Visibility
---

## Visibility

A `.java` file can have at most one class that is declared `public`.

* If present, this class must have the same name as the file.

A `.java` file can contain additional, non-`public` classes.

* This is generally considered a bad practice, however.


### Drill
> `com.example.objs.drills`
>
> Create a new class named just `A`.  In `A.java`, add the following _outside_ the body of `class A`.
> ```java
> class B { }
> ```
> * What happens if you remove `public` from the definition of `class A`?
> * What happens if you add `public` to the declaration of `class B`?


### Practice Exercise
> Later you will learn how to use _inner classes_: classes defined _inside_ the body of another class.

### `public`

A class, field, or method that is declared `public` can be seen and used by any other Java class.

Without `public`, a class can be seen and used only by other classes in the same package.

* These are the only two options for a class.

Fields, methods, and constructors can be declared with additional _visibility modifiers_ which determine which other classes, if any, can access them.

| Modifier | Access |
| -------- | ------ |
| public | Methods of any class anywhere have access. |
| protected | Methods of subclasses and of any class in the same package have access. |
| _(default)_ | Methods of classes in the same package (directory) have access |
| private | Only methods defined in the same class have access. |

* We will cover visibility in more detail later.

### Drill
> `Objects/com.example.objs.drills.BankApp`
> 
> Open and examine `BankApp`, whose `run` method declares and instantiates two `Account` objects.
> Now open `Account`.  Change its two-argument constructor declaration from `public` to `private`.  What happens when you save?
>
> Change the constructor declaration back to `public`.

<hr>

[Prev](heap-image.md) -- [Up](README.md)

