## Tuning `HashMap`

### Capacity and Load Factor

A `HashMap`'s _capacity_ is its number of buckets - that is, the `length` of the hash table array.

As entries are added, a `HashMap` will automatically grow its hash table array.

* Rather than wait until all buckets have entries, the `HashMap` resizes when the number of entries, relative to the capacity, reaches its _load factor_.

The default load factor is .75: when the number of stored entries reaches three quarters of its capacity, the `HashMap` will automatically _rehash_:

1. Create a new hash table array twice the size of the current one.
2. Re-compute the bucket number for each current key.
3. Assign each entry's reference to the correct bucket of the new hash table.

### `HashMap` Optimization

For ideal retrieval performance each entry would have its own bucket.

* Multiple entries in a bucket slow down retrieval as well as inserts and deletes.

* As a `HashMap` grows, the rehash operations interrupt execution and take additional computation time.

If you know approximately how many entries your `HashMap` will need to hold, you can construct it with an _initial capacity_ that allows for your keys.

```java
//    50 state entries, so 50 keys.
//    Load factor is .75, so map will rehash at 50 * .75, or about 37 entries.
//    To allow all keys without rehash, allocate initial capacity of 50/.75, or 67.
    Map<String, USState> states = new HashMap<>(67);
```

* Note that this doesn't guarantee each entry will have its own bucket - two keys can still coincidentally hash to the same bucket number.

`HashMap` has another constructor that takes both an initial capacity and a load factor.

```java
// We don't expect more than 50 entries, so decrease the capacity to save space,
// and increase the load factor to reduce rehashing.
Map<String, USState> states = new HashMap<>(53, .95F);
```

Note: Whatever initial capacity you provide, `HashMap` will use the next highest power of 2.

### Practice Exercise
> From the `HashMap` JavaDoc<sup>1</sup>:
> > As a general rule, the default load factor (.75) offers a good tradeoff between time and space costs. Higher values decrease the space overhead but increase the lookup cost (reflected in most of the operations of the HashMap class, including get and put). The expected number of entries in the map and its load factor should be taken into account when setting its initial capacity, so as to minimize the number of rehash operations. If the initial capacity is greater than the maximum number of entries divided by the load factor, no rehash operations will ever occur.
>
> You shouldn't feel obligated to optimize capacity and load factor for every `HashMap` you create.  If you do anticipate large numbers of entries, setting the initial capacity is a quick optimization.

[1] https://docs.oracle.com/javase/8/docs/api/java/util/HashMap.html

<hr>

[Prev](mapEntry.md) -- [Up](README.md) -- [Next](labs.md)

