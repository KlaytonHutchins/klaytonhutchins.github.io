---
layout: default
title: `Vector`
---


The predecessor to `ArrayList` is `Vector`.
* `ArrayList` is "roughly equivalent" to `Vector`.<sup>[1]</sup>
* Like `ArrayList`, `Vector` also has a growable array of objects.
* Unlike `ArrayList`, `Vector` is _thread-safe_.

> #### thread-safe
> A program can have multiple sub-programs that run at (essentially) the same time.
>
> If a sub-program, called a "thread," changes an object's data when another sub-program does not expect it to, unexpected results can occur.
>
> `Vector`'s methods keep this thread-related problem from happening, so it is considered "thread-safe".


`Vector`'s thread-safety makes it slower than `ArrayList`.
* Only use `Vector` if you really need thread safety.


### Practice Exercise
> You will almost never use `Vector`. It is a legacy class that has been around since the beginning of Java.

[1] https://docs.oracle.com/javase/8/docs/api/java/util/ArrayList.html

<hr>

[Prev](linkedlist.md) -- [Up](README.md) -- [Next](list-and-class.md)

