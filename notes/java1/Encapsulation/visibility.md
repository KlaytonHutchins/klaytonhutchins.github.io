---
layout: default
title: Visibility and Access Modifier
---

## Visibility and Access Modifiers

> #### visibility
> Which classes can access a class, or the fields and methods of a class.

We can change our field and method (and even class) definitions to only allow certain classes to use them.

We do so with _access modifiers_.

* So far we have placed the access modifier `public` before our methods and fields.

### Access Modifiers

| Modifier | Access |
| -------- | ------ |
| public | Methods of any class anywhere have access. |
| protected | Methods of subclasses<sup>$</sup> and of any class in the same package have access. |
| _(default)_ | Methods of classes in the same package (directory) have access |
| private | Only methods defined in the same class have access. |

<sub>$ - we will explain subclasses in a later chapter</sub>

If a class tries to use something it can't access, the result is a compiler error.

#### (default) Access
We write or say "default" because this is the access a field or method has when you _do not_ add an access modifier: it is Java's "default" access.

The method below has no access modifier, so it is only available to classes in the same package.

```java
static void defaultAccessMethod() {

}
```

### Practice Exercise
> Classes can have only `public` or default visibility. This would not compile:
> ```java
> protected class ProtectedClass {
>
> }
> ```
> This would compile:
> ```java
> class DefaultClass {
>
> }
> ```

<br >

### Drill
> `Encapsulation/com.example.encapsulation.drills.BankApp`
>
> `Encapsulation/com.example.encapsulation.drills.Account`
> * Run the `BankApp` program. Notice that the class accesses the `Account` fields directly.
> * Change the fields in `Account` to have `private` visibility. What happens to `BankApp`? Leave it and we will fix it soon.
>
> (Solution: _Account1.java_, _BankApp1.java_)

<hr>

[Prev](instance-fields.md) -- [Up](README.md) -- [Next](encapsulation.md)

