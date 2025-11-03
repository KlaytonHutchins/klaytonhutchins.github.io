---
layout: default
title: Lab
---

## Labs

These labs require drawing references to objects on the heap.

1. After which line is the object created at line `4` eligible for garbage collection?
```java
1: public class GCObj {
2:   public static void main(String[] args) {
3:     GCObj one = new GCObj();
4:     GCObj two = new GCObj();
5:     GCObj three = one;
6:     one = null;
7:     GCObj four = one;
8:     three = null;
9:     two = null;
10:    two = new GCObj();
11:  }
12:}
```
   [Lab 1 Solution](lab1-solution.md)

2. After which line is the object at line `6` eligible for garbage collection.
```java
1: public class RefObj {
2:
3:   private RefObj ref;
4:   
5:   public static void main(String[] args) {
6:      RefObj a = new RefObj();
7:      RefObj b = new RefObj();
8:      b.ref = a;
9:      a = null;
10:     RefObj c = a;
11:     b = null;
12:   }
13: }
```
   [Lab 2 Solution](lab2-solution.md)

<hr>

[Prev](understanding-gc.md) -- [Up](README.md) -- [Next](lab1-solution.md)

