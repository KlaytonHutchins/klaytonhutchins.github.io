---
layout: default
title: Temporal Data
---


Databases support temporal data types such as `DATE` (calendar date), `TIME` (clock time), and `DATETIME` (combined date and time).

### Practice Exercise
> MySQL also has `TIMESTAMP`, which is Unix Epoch time (seconds since 01/01/1970).  `DATETIME` is by far the better choice.

Map these to the appropriate `java.time` classes such as `LocalDate`, `LocalTime`, and `LocalDateTime`.

```java
  @Column(name="create_date")
  private LocalDateTime createDate; 
```

### Practice Exercise
> JPA 2.1 was released before Java 8, so it didn’t support `java.time.LocalTime` or `java.time.LocalDate`.
>
> The spec for JPA 2.2 was released August 2017 and included support for the Java8 time API.  Hibernate 5.3 included full integration of JPA 2.2. 
>
> Prior to this, all database temporal data had to be mapped to `java.util.Date` or its subclass `java.sql.Date`, `java.util.Calendar`, etc. and required you annotate `java.util.Date` or `java.util.Calendar` fields with the `@Temporal` annotation, and specify a value from the `TemporalType` enumeration.
> 
> * The value can be `TIMESTAMP`, `TIME` or `DATE`.
> 
> ```java
> @Entity
> @Table(name="CustomerTable")
> public class Customer {
>   @Id
>   @GeneratedValue(strategy = GenerationType.IDENTITY)
>   private int id;
> 
>   @Column(name="create_date")
>   @Temporal(TemporalType.DATE)
>   private Date createDate;
> 
>   // ...
> }
> ```
> While you may see this in legacy code, all new entities can use `java.time` classes without further annotations.

### Testing Temporal Values

The `java.time` classes have getters you can use to test their content.

```java
  @Test
  void test_Rental_temporal_mapping() {
    assertNotNull(rental);
    assertNotNull(rental.getRentalDate());
    assertEquals(2014, rental.getRentalDate().getYear());
    assertEquals(9, rental.getRentalDate().getMonthValue());
    assertEquals(24, rental.getRentalDate().getDayOfMonth());
  }
```

* `getMonth()` returns a special enumeration type `Month`, while `getMonthValue()` returns a 1 to 12 month number.

* Note that, while a month number might be displayed as `09`, it's just the number `9`; in Java a literal with a leading `0` is considered to be octal, for which the values `08` and `09` are invalid.

This far more reliable than testing with the `toString()` value:
```java
    assertEquals("2014-09-24T22:04:30.0", rental.getRentalDate());
```

### Practice Exercise
> When using `LocalDateTime`, teammates in different time zones may run into "off-by-a-day" errors for times near midnight.

### Drill
>
>1. Add a new field called `createdAt` of type `java.time.LocalDateTime` to your `Customer` entity.
>
>    Here is the _Customer_ for reference:  
>
>    ```
>    +-------------+----------------------+------+-----+-------------------+-----------------------------+
>    | Field       | Type                 | Null | Key | Default           | Extra                       |
>    +-------------+----------------------+------+-----+-------------------+-----------------------------+
>    | id          | int(10) unsigned     | NO   | PRI | NULL              | auto_increment              |
>    | store_id    | smallint(5) unsigned | NO   | MUL | NULL              |                             |
>    | first_name  | varchar(45)          | NO   |     | NULL              |                             |
>    | last_name   | varchar(45)          | NO   | MUL | NULL              |                             |
>    | email       | varchar(50)          | YES  |     | NULL              |                             |
>    | address_id  | int(10) unsigned     | NO   | MUL | NULL              |                             |
>    | active      | tinyint(1)           | NO   |     | 1                 |                             |
>    | create_date | datetime             | NO   |     | NULL              |                             |
>    | last_update | timestamp            | NO   |     | CURRENT_TIMESTAMP | on update CURRENT_TIMESTAMP |
>    +-------------+----------------------+------+-----+-------------------+-----------------------------+
>    ```
>
>    * Don’t forget to add get/set methods.
>
> 1. Write a test for the *createdAt* mapping.
>
> 1. Look at your `CustomerTest` class. In each of your tests you are likely using the method `em.find` to retrieve a *Customer* entity - and likely the same *Customer* entity each time. This isn't very DRY... how could you refactor your test class to fix this?
>
>    * Look at how you are retrieving/assigning the *EntityManagerFactory* and *EntityManager* as fields at the class level... could you do something similar with the *Customer* entity?

<hr>

[Prev](generatedValue.md) -- [Up](README.md) -- [Next](enumerated.md)

