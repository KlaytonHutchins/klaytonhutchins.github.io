## JPQL Review

We saw that JPA has its own language for writing queries to the database. The major difference between SQL and JPQL is that JPQL is concerned with entities and their properties, not tables and their columns.

### SELECT Query
Selecting all films from the database. The returned collection would be a `List` of `Film` objects.

```java
String query = "SELECT f FROM Film f";
List<Film> results =
  em.createQuery(query, Film.class)
    .getResultList();
```
### SELECT Query for Properties
Selecting all film titles from the database. The returned collection would be a `List` of `String` objects.

```java
String query = "SELECT f.title FROM Film f";
List<String> results =
  em.createQuery(query, String.class)
    .getResultList();
```
### SELECT Query for Multiple Properties
Selecting all film titles and descriptions from the database. The returned collection would be a `List` of `Object[]` objects.

```java
String query = "SELECT f.title, f.description FROM Film f";
List<Object[]> results =
  em.createQuery(query, Object[].class)
    .getResultList();
```

### SELECT with Query Parameters
Selecting a single film whose title is *ACADEMY DINOSAUR*. The returned collection would be a `List` of `Film` objects, presumably of length 1.

```java
String query =
  "SELECT f FROM Film f WHERE f.title = :title";

List<Film> results =
  em.createQuery(queryString, Film.class)
  .setParameter("title", "ACADEMY DINOSAUR")
  .getResultList();
```

<hr>

[Prev](README.md) -- [Up](README.md) -- [Next](fieldsThatAreObjects.md)

