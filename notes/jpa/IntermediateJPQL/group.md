---
layout: default
title: Grouping
---


### `GROUP BY`
We can group aggregate results using the `GROUP BY` keyword. This changes the default behavior of an aggregate returning a single result to instead return multiple results.

The aggregate function, `COUNT` in this case, will be evaluated for each group, `f.rating`, and will return an `Object[]` composed of the rating and the corresponding count numeric.

```java
String query = "SELECT f.rating, COUNT(f) FROM Film f GROUP BY f.rating";

List<Object[]> results = em.createQuery(query, Object[].class).getResultList();
```

### `HAVING`
We can continue to filter our aggregates by adding a `HAVING` clause to our `GROUP BY` results.

* `HAVING` statement is used to eliminate groups based on the resulting aggregate value.

```java
String query = "SELECT f.rating, COUNT(f) FROM Film f GROUP BY f.rating HAVING COUNT(f) > 1";

List<Object[]> results = em.createQuery(query, Object[].class).getResultList();
```

### Drill
> 1. Open your `IntermediateJPQLClient` class.
> 1. In the `main` method write a query that counts Employees grouped by their `firstName`.
> 1. Add a `HAVING` clause to exclude any names that only have 1 instance.

<hr>

[Prev](aggregates.md) -- [Up](README.md) -- [Next](labs.md)

