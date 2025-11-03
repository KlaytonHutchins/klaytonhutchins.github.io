---
layout: default
title: Constant Fields and Variable
---

## Constant Fields and Variables

We can ensure a field or variable does not change by declaring it with the keyword `final`.

### `final` Variables

We can use `final` before a local variable to make sure it doesn't get assigned a different value.

```java
public void method() {
  final int constantVar = 15;
  final int declaredFinal;
  // ...
  declaredFinal = 42;
}
```

Once it has been assigned, attempting to reassign the `final` variable results in a compiler error.

```java
public void notCompilingMethod() {
  final int constantVar = 15;
  constantVar = 99;  // COMPILER ERROR
}
```

We can mark method parameters as `final` (since they're just local variables).

```java
public void paramsFinal(final int id, final String name) {
  // ...
}
```

### `final` Fields

We can mark `static` and instance fields as `final` - again, this means they cannot be reassigned new values.

```java
public class AccountFinal {
  public static final int ROUTING_NUMBER = 123456789;
  private double balance;
  private final String accountId;

  AccountFinal(String accountId){
    this.accountId = accountId;
  }

  //...
}
```

There are three key things to remember about `final` fields.

* `final` fields do not get default values, like `null` or `0.0`: you must explicitly initialize them in the class.
* `static` fields must be initialized by the time the class is done initializing.
  * Each `final` field must be given a value at its declaration, or in a static initializer block.

    ```java
    public class ClassWithFinal {
      private static final String[] arrayOfNames;

      static {
        arrayOfNames = new String[100];
      }
    }
    ```
* Instance fields must be initialized by the time the constructor has finished.

  * This means the field must be given a value at declaration, in an initializer block, or in each constructor.

### Drill
> Look at the class below and decide which statements cause compiler errors. How would you fix them? See the solution for answers.
> ```java
> public class BrokenFinalClass {
>  private String name;
>  private final int uniqueId;
>    
>  private static final int MAX_NUMBER;
>    
>  MAX_NUMBER = 10000;
>    
>  public BrokenFinalClass(int uniqueId, String name){
>    this.uniqueId = uniqueId;
>    this.name = name;
>  }
>    
>  public BrokenFinalClass(String name) {
>    this.name = name;
>  }
>
>  public void setUniqueId(int id) {
>    uniqueId = id;
>  }
> }
> ```
> (Solution: _ObjectInitialization/com.example.objs2.solutions.BrokenFinalClass_)

<br >

### Practice Exercise
> `final` `static` fields are named using capital letters and snake case, like `MAX_NUMBER`. This is a convention developers use to denote constant values.

### `final` and References

A `final` reference cannot be reassigned.

However, this does not mean that the data inside the referenced object cannot change, just that the reference cannot be changed to point to a different object.

```java
public class ClassWithFinalReference {
  private final String[] finalArr;

  // initialize and set some elements
  {
    finalArr = new String[5];
    finalArr[0] = "Zero";
    finalArr[1] = "One";
  }

  public void changeData(int index, String data) {
    // reassign element
    finalArr[index] = data;    // COMPILES AND WORKS
    // reassign reference
//  finalArr = new String[10]; // WILL NOT COMPILE

  }
}
```
We can change the elements of `finalArr`, but we cannot make the field `finalArr` point to a different object.

<hr>

[Prev](order-of-init.md) -- [Up](README.md) -- [Next](private-methods.md)

