## The `Set` Interface

`Set` is an interface in the `java.util` package.

The most important aspect of `Set` is: **`Set`s do not contain duplicate elements.**
  * No two elements in a `Set` can be `equals()` to each other.
  * At most, one `null` element may be placed in a `Set`.
    * Some implementations may disallow `null`.

`Set` is unordered.
  * Subinterfaces may guarantee an order, but `Set` does not.


### `Set<E>` Is Generic
Like `List`, we tell `Set` what type of elements it will contain.
```java
Set<String> strSet;  // Set of String objects
```

### `Set` Methods
Many methods of `Set` are the same as `List`.
* `int size()` - get the number of elements in the `Set`.
* `boolean isEmpty()` - returns `true` if this `Set` contains no elements.
* `boolean contains(Object o)` - returns `true` if the object is in the `Set` (such that `o.equals(element)` is `true`).
* `boolean remove(Object o)` - returns `true` and removes the object if it was in the `Set`.


### `Set` vs. `List`
`Set` is different than `List`, both in its concept and its methods.

  * `boolean add(E)`

    This method returns `true` if adding to the set succeeded.
    * Since a `Set` does not contain duplicates, `add` only succeeds when the new element is not `.equals()` to an element already in the `Set`.
    * If a `.equals()` element was already in the `Set`, this returns `false`.

  * `Set` does not maintain an order, so there is no `get(index)` or `set(index, E)`.

  * `get()` does not exist at all.
    * Reading objects from a `Set` requires an `Iterator` object to step through the `Set`'s elements.
  * `iterator()` - returns an `Iterator<E>` reference for accessing a `Set`'s elements.

### `Iterator<E>`
`Set` provides an `Iterator` object, which allows us to step through the elements in the `Set`.
  * `boolean hasNext()` determines if there are more elements in a collection.
  * `E next()` gets the next element.

```java
￼Iterator<String> it = strSet.iterator();

while (it.hasNext()) {
  String element = it.next();
  System.out.println(element);
}
```

<hr>

[Prev](README.md) -- [Up](README.md) -- [Next](hashset-linkedhashset.md)

