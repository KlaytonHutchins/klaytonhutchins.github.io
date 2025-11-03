---
layout: default
title: Uni directional `@ManyToOne`
---

## Uni directional `@ManyToOne`

Use the `@ManyToOne` annotation in conjunction with `@JoinColumn` to describe a many-to-one relationship.

Annotate the defining field in the owning entity to specify mapping details.

* For a many-to-one, the **many** side of the relationship will always be the **owner**.

* This is the entity for the table containing the foreign key column.

Like before, use the `@JoinColumn` annotation to specify the foreign key _column name_.

```java
@Entity
public class Address {
     // ...
     @ManyToOne
     @JoinColumn(name="country_code")
     private Country country;
     // ...
}
```

For uni-directional, the non-owning side of the relationship remains unchanged.

### Drill
> 1. Create a new *Country* entity for the _country_ table.
>
>    * Add a field called *countryCode* and annotate it as an `@Id` mapped to the *country_code* column.
>      * Note this id is NOT a generated value.
>
>    * Also create a field called *name* mapped to the *country* column.
>
>    The _country_ table looks like this:
>
>    ```bash
>    +--------------+-------------+------+-----+---------+-------+
>    | Field        | Type        | Null | Key | Default | Extra |
>    +--------------+-------------+------+-----+---------+-------+
>    | country_code | char(2)     | NO   | PRI | NULL    |       |
>    | country      | varchar(50) | NO   |     | NULL    |       |
>    | formal_name  | varchar(60) | YES  |     | NULL    |       |
>    | sovereignty  | varchar(30) | YES  |     | NULL    |       |
>    | capital      | varchar(80) | YES  |     | NULL    |       |
>    | iso3_code    | char(3)     | YES  |     | NULL    |       |
>    | tld          | char(3)     | YES  |     | NULL    |       |
>    +--------------+-------------+------+-----+---------+-------+
>    ```
>
>    * Generate a no-arg constructor, gets/sets and the `toString()` method.
>
> 1. Create a JUnit test, `CountryTest`, to confirm JPA can retrieve the country `France` using the country code `FR`.
> 
>
> 1. Create a uni-directional, many-to-one relationship between your *Address* and *Country* entities.
>
>    * Modify *Address*, add a field of type *Country* annotated with `@ManyToOne` and `@JoinColumn`.
>
>    * Also, generate get/set methods.
>
> 1. Update your *AddressTest*, adding a test named `test_Address_Country_ManyToOne_relationship_mapping` which checks that the appropriate *Country* entity is loaded for the *Address*.
>
>    * The *Address* object with id = 1 has `CA` (Canada) as a country_code.
>

<hr>

[Prev](README.md) -- [Up](README.md) -- [Next](biDirectionalManyToOne.md)

