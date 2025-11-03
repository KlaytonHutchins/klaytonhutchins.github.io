## Aggregates
As we learned in SQL, _aggregate functions_ can be used to distill a result set into in a single value.

These keywords still exist when using _JPQL_.

* `COUNT`: returns a _long_ representing the number of elements selected.
    ```java
    String query = "SELECT COUNT(f) FROM Film f WHERE f.id < 10";

    long count = em.createQuery(query, Long.class).getSingleResult();
    ```
    * We have traditionally used the `.getResultList()` method when aggregating a result set. Due to the fact that we know our query is going to return a single `long` value, we execute the statement with `getSingleResult()`.

* `SUM`: returns the sum of the numeric values as a double.
    ```java
    String query = "SELECT SUM(f.rentalRate) FROM Film f WHERE f.id < 10";

    double total = em.createQuery(query, Double.class).getSingleResult();
    ```
* `AVG`: returns the average of the numeric values returned.
    ```java
    String query = "SELECT AVG(f.rentalRate) FROM Film f WHERE f.id < 10";

    double average = em.createQuery(query, Double.class).getSingleResult();
    ```
* `MIN`: returns the minimum of the returned values.
    ```java
    String query = "SELECT MIN(f.rentalRate) FROM Film f WHERE f.id < 10";

    double minRate = em.createQuery(query, Double.class).getSingleResult();
    ```
* `MAX`: returns the maximum of the returned values.
    ```java
    String query = "SELECT MAX(f.rentalRate) FROM Film f WHERE f.id < 10";

    double maxRate = em.createQuery(query, Double.class).getSingleResult();
    ```


If you would like to execute multiple aggregates in a single query, you can change the return type of the `createQuery` to an `Object[]`.

```java
String query = "SELECT MIN(f.rentalRate), MAX(f.rentalRate), AVG(f.rentalRate) FROM Film f WHERE f.id < 10";

Object[] results= em.createQuery(query, Object[].class).getSingleResult();
```
The returned `Object[]` would have the _min_ stored in index 0, _max_ in index 1 and _avg_ stored in index 2.


### Drill
> 1. Open your `IntermediateJPQLClient` class.
> 1. In the `main` method write a query to calculate the total number of `Film`s in the database.

<hr>

[Prev](order.md) -- [Up](README.md) -- [Next](group.md)

