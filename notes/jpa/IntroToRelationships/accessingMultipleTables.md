---
layout: default
title: Accessing data from multiple table
---


### SQL JOINs
![Customer SQL Table](images/customerSQL.png)

Looking at the `Customer` table we can see that we have multiple foreign keys present: `address_id` and `store_id`.

The presence of these foreign keys means there is a relationship between `Customer` and `Address` as well as `Customer` and `Store`.

For example we could _JOIN_ `Customer` and `Address` as follows:
```SQL
Select c.first_name, c.last_name, a.address, a.city, a.state_province
FROM Customer c JOIN Address a
ON c.address_id = a.id
WHERE c.id =1;
```
### JPA Foreign Keys
Foreign key columns could be mapped the exact same way as we have handled any primitive data types in JPA, using the `@Column` annotation.

Again looking at our `Customer` table we can see that it has a column `address_id` of type `int`. This in turn would correspond to a field in the `Customer` class.

```java
@Column(name="address_id")
private int addressId;
```

We can use this column to `find` the `Address` for a `Customer`.

### Drill
> Lets build this relationship.
> 1. In your `Customer` entity add a field `addressId` and annotate it properly.
>    * Add the appropriate gets and sets.
> 1. Create a class `CustomerRelationshipClient` in `com.example.jpavideostore.client`.
> 1. In a main, find the Customer that has `id` 1.
>    * Print out its `toString` as well as `getAddressId`.
> 1. Refactor your code and add a second `em.find` for an `Address` object using the value provided by `getAddressId`.
> 1. Print out the returned `Address`.

While this method properly retrieves a `Customer` and `Address` entity, it is inefficient. We are running two _SELECT_ statements as opposed to a _JOIN_.

We are also not leveraging Object-Oriented principals. Instead of `Customer` having a field field of type `int`,
```java
private int addressId;
```
we would expect it to have a field of type `Address`
```java
private Address address;
```

This is what we will explore next.

<hr>

[Prev](relationships.md) -- [Up](README.md)

