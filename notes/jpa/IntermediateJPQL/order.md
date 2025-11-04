---
layout: default
title: ORDER and DISTINCT
---


### `DISTINCT`
The `DISTINCT` keyword can be used to filter a result set for only unique values.

There are situations when we are using `JOIN`s or projection where duplicate copies of the same row can end up in our result set. The `DISTINCT` keyword will eliminate these dupes from the result set.

```java
String query = "SELECT DISTINCT f FROM Film f WHERE f.id < 10";

List<Film> results = em.createQuery(query, Film.class).getResultList();
```

### `ORDER BY`
Select statements can be modified with an `ORDER BY` clause. `ORDER BY` is the only way to enforce a sequence with our result sets.

```java
String query = "SELECT f FROM Film f ORDER BY f.title";

List<Film> results = em.createQuery(query, Film.class).getResultList();
```

We can apply `ASC` or `DESC` to the columns in the `ORDER BY` clause to order them in ascending or descending order.

```java
String query = "SELECT f FROM Film f ORDER BY f.title DESC";

List<Film> results = em.createQuery(query, Film.class).getResultList();
```

### Drill
1. Create a new class `IntermediateJPQLClient` in your `com.example.jpavideostore.client` package.
> 1. In a `main`, retrieve a list of `Staff` members sorted in alphabetical order by `lastName`.

<hr>

[Prev](README.md) -- [Up](README.md) -- [Next](aggregates.md)

