---
layout: default
title: Keys and `hashCode`
---


A _key_/_value_ entry in a `Map` establishes a meaningful relation between the key object and the value object.

* The key can be of any object type, but is often a `String`.

A `HashMap` is known for providing efficient retrieval of a value using a key, no matter how many entries it stores.

* You can explain this by understanding hash codes and array indexes.

### Practice Exercise
> Why explain how a hash map works?  Because this is a very common question in technical interviews for candidate developers.

### `hashCode`

Every Java object's `hashCode` method returns an integer which is usually based on the object's content, or _state_.

* A `String` hash code is based on the actual characters in the string.

  ```java
  String aa = "aa";
  String ab = "ab";
  System.out.println(aa + ": " + aa.hashCode());
  System.out.println(ab + ": " + ab.hashCode());
  ```
  ```
  aa: 3104
  ab: 3105
  ```

* An `Integer` hash code is its numeric value.

  ```java
  Integer awesomePrime = 17;
  Integer ultimateAnswer = 42;
  System.out.println(awesomePrime + ": " + awesomePrime.hashCode());
  System.out.println(ultimateAnswer + ": " + ultimateAnswer.hashCode());
  ```
  ```
  17: 17
  42: 42
  ```

* Two objects that are "dot-equals" (`.equals`) have the same hash code.

* As much as possible, objects with different state should produce different hash codes.

Data structures like `HashMap` use the `hashCode` method of _key_ objects in their operation.

* In fact, this is the primary purpose of the `hashCode` method.

<hr>

[Prev](README.md) -- [Up](README.md) -- [Next](buckets.md)

