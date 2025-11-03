## `Map` Implementation Class - `HashMap`

To create a `Map`, we need an implementation class.

![Map<-HashMap](images/hashmap.png)


`HashMap` is the general-purpose implementation of the `Map` interface.

```java
 Map<Integer, String> map = new HashMap<>();
```


![new HashMap<>()](images/hashmap1.png)


### Using the `Map`

We use `put(Integer, String)` to add data to the `HashMap`.

```java
map.put(42, "Robinson");
```

![map.put(42, "Robinson")](images/hashmap2.png)


Use `get(Integer)` to get `String`s from the `Map`.

```java
String value = map.get(42);
```

![map.get(42)](images/hashmap3.png)


If there is no mapping for a key, `get(Integer)` will return `null`.

![map.get(14)](images/hashmap4.png)


### Key and Value Methods
`boolean containsKey(Object)` - returns `true` if the key is in the `Map`. Takes any `Object`.

![map.containsKey(42)](images/hashmap5.png)

`boolean containsValue(Object)` - returns `true` if the value is in the `Map`. Takes any `Object`.

![map.containsValue("Doby")](images/hashmap6.png)


### Iterating Through a `Map`'s Keys or Values

`Map` does not define an `iterator()` method.
  * `Set<K> keySet()` retrieves a `Set` of keys that you can then iterate on.

    ```java
    Set<Integer> s = map.keySet();      // Set of Integer keys
    Iterator<Integer> it = s.iterator();

    while (it.hasNext()) {
      Integer key = it.next();
      System.out.print("Key: " + key);
      System.out.println(" Value: " + map.get(key));
    }
    ```

  * `Collection<V> values()` retrieves a `Collection` of values you could iterate on.

Remember:
  * We `put` into a `Map`; we `add` to a `Set` or `List`.
  * `keySet()` returns a `Set`; `values()` returns a `Collection`.


### Practice Exercise
> Why the name _hash_ map?
>
> `HashMap` calls the `hashCode()` method of each key to evenly distribute key-value pairs in the underlying data structure (which is an array).

<br >

### Drill
> `MapInterface/com.example.mapinterface.drills.UsingHashMap`
>
> This drill has you declaring a `Map`, putting some data into it, and retrieving the data.
> * Follow instructions in the class.
> * Note the order of the key-value pairs when you iterate through the `Map`.

<hr>

[Prev](map.md) | [Up](README.md) | [Next](map-classes.md)

