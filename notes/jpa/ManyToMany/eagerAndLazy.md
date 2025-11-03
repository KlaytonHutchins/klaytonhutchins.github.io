## Eager and Lazy Loading

When you call find() to retrieve an entity, JPA will _eagerly_ (immediately) load data into scalar types, but defer loading data into collection types until the data is needed.

  * Called _lazy loading_, this deferred loading is enabled by default for performance and memory conservation.

By default one-to-one and many-to-one relationships are eagerly loaded and one-to-many and many-to-many are lazily loaded.

  * Override the default behavior by adding `fetch=FetchType.EAGER` or `LAZY` to your cardinality annotation.

```java
  @ManyToMany(mappedBy="films", fetch=FetchType.EAGER)
  private List<Actor> actors;
```

### Overriding Loading Strategy
Be careful when overriding the default loading strategy since it may affect performance.

If all of your entities are set to eagerly load their associations, and you query a list of all of the entities of a given type, the number of entities loaded could be immense depending on the size of your data. As a result, it is better for performance to set the `FetchType` to `LAZY` in most circumstances.

Later we will see that you can override the loading strategy on an individual query, which may be more appropriate.

<hr>

[Prev](addAndRemove.md) -- [Up](README.md) -- [Next](labs.md)

