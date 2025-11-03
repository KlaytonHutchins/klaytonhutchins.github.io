## Retrieving Multiple Properties

If you would like to retrieve more than one property, but still not the entire object, you can comma-separate the requested properties within a SELECT statement.

```java
    String queryString = "SELECT s.firstName, s.lastName FROM Staff s";

    List<Object[]> results = em.createQuery(queryString, Object[].class)
                               .getResultList();
```

### Practice Exercise
Notice that the second argument to `createQuery` is now `Object[].class` and the collection is typed as `List<Object[]>`. Each row that returns from the query is placed into its own `Object[]`. In our case index 0 would hold the `firstName` value and index 1 would hold the `lastName` value. If we wanted to print off the result list we could access the data as follows:
> ```java
> String queryString = "SELECT s.firstName, s.lastName FROM Staff s";
>
> List<Object[]> results = em.createQuery(queryString, Object[].class)
>                           .getResultList();
> for(Object[] arr : results){
>   System.out.println("First name: " + arr[0] + " Last name: " + arr[1]);
> }
> ```


### Drill
> 1. In your _JPQLClient_ class, write a JPQL statement to retrieve the `firstName` and `lastName` of any staff member whose id is less than 10.
> 1. Iterate over the returned collection and print off the results.

<hr>

[Prev](queryingForProperties.md) | [Up](README.md) | [Next](queryParams.md)

