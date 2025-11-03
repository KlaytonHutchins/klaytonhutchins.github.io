## Querying for Properties

In JPQL executing a statement like `SELECT s FROM Staff s` would retrieve the entire Staff entity with its properties.

What if we want to query for just one specific property instead?

To do this we can alter the SELECT portion of the JPQL statement and use `.` notation to grab a single property.

```java
    String queryString = "SELECT s.firstName FROM Staff s";

    List<String> results = em.createQuery(queryString, String.class)
                             .getResultList();
```
### Practice Exercise
Notice that the second argument to `createQuery` is now `String.class` and the collection is typed as `List<String>`. Why would this be necessary?


### Drill
> 1. In your _JPQLClient_ class, write a JPQL statement to retrieve the last name of any staff member whose id is less than 10. What would be the type of the returned collection?
> 1. Iterate over the returned collection and print off the results.

<hr>

[Prev](basicQueries.md) | [Up](README.md) | [Next](retrieveMultipleProperties.md)

