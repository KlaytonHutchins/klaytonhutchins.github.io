## Objects in Memory

We know that declaring and assigning a primitive variable stores 0's and 1's in memory.

```java
char c = 'A'; //00000000 01000001 in memory
```

But what about objects?

```java
Sphere3 sphere = new Sphere3(); // What are the 0's and 1's in memory?
```

### Objects Are Stored on the Heap

When we create an object using `new`, memory is reserved, or _allocated_, on a section of memory called the _heap_.

> #### heap
> A place in Java's memory for class instances and arrays.

Each object is stored on the heap and given a unique address in memory (like the address on a building).

A reference variable holds the address of the object on the heap.

```java
Sphere3 sphere = new Sphere3(); // sphere is the location of the Sphere3 object on the heap
```

### About the Heap

The heap is created when the Java Virtual Machine starts up.

As each object is created, space is allocated for it from the free space within the heap.

Our reference variables hold locations of objects on the heap.

Java manages the heap, so we never have to delete objects.

<hr>

[Prev](default-ctor.md) -- [Up](README.md) -- [Next](heap-image.md)

