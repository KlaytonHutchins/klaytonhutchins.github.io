## The `finalize` method

If an object has a `finalize()` method, the JVM will invoke it just before the object is garbage collected.

```java
protected void finalize() {
  System.out.println("finalize called");
}
```

Since garbage collection may never run, don't count on `finalize` to free resources you need back, like open files or database connections.

* Calling `finalize` does _not_ cause an object to be garbage-collected.

  * Its purpose is to give an object a last chance to prepare itself before being garbage-collected, which in fact may never happen.

If the garbage collector calls `finalize` on an object but fails to garbage collect that object, it will not call `finalize` again.

### Practice Exercise
> You won't use `finalize` much in real projects. Some programmers follow the convention of creating a `dispose()` method, which they call explicitly when they're done with an object.

<hr>

[Prev](gc-strategies.md) | [Up](README.md) | [Next](understanding-gc.md)

