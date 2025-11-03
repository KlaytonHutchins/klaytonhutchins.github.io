## Queries with Nested Objects

We are going to use the `Customer` and `Address` classes in our examples for this chapter. Up to this point we have a number of fields configured in our entities, including a few relationships.

```java
@Entity
public class Customer {
	@Id
	@GeneratedValue(strategy= GenerationType.IDENTITY)
	private int id;

	@Column(name="first_name")
	private String firstName;

	@Column(name="last_name")
	private String lastName;

	private String email;

	@Column(name="create_date")
	@Temporal(TemporalType.DATE)
	private Date createDate;

	@OneToOne
	@JoinColumn(name="address_id")
	private Address address;

  // ...
}
```

```java
@Entity
public class Address {
	@Id
	@GeneratedValue(strategy= GenerationType.IDENTITY)
	private int id;

	@Column(name="address")
	private String street;

	@Column(name="address2")
	private String street2;

	@Column(name="state_province")
	private String state;

	private String city;

	@Column(name="postal_code")
	private String postalCode;

	private String phone;

	@ManyToOne
	@JoinColumn(name="country_code")
	private Country country;

  // ...
}
```

### WHERE Clause with Nested Objects
We know that if we wanted to write a query to select the `Customer`s with the first name "Leslie", we could utilize the `.firstName` property.

```java
String query = "SELECT c FROM Customer c where c.firstName= 'Leslie'";
```

Nested objects are no different. We can use `.` notation to dig as deep into an object as we desire. For example, if we wanted to select all the `Customer`s that have a `state` of `Illinois` we could use the path `.address.state` to access that value.

```java
String query = "SELECT c FROM Customer c where c.address.state= 'Illinois'";
```

### Objects in the SELECT List
We know that if we wanted to write a query to select the `firstName` of the `Customer` with `id` 5 we could:

```java
String query = "SELECT c.firstName FROM Customer c where c.id= 5";
List<String> results =
  em.createQuery(query, String.class)
    .getResultList();
```

  * The return value of this query is a `List<String>` due to the fact that we are not returning the entire `Customer` object, just one of its properties that happens to be a `String`.

What if we wanted to query for the address of `Customer` with id 5?

```java
String query = "SELECT c.address FROM Customer c where c.id=5";
List<Address> results =
  em.createQuery(query, Address.class)
    .getResultList();
```
  * **Notice:** The return value of this query is a `List<Address>` due to the fact that we are not returning the entire `Customer` object. Instead we are returning one of its properties that happens to be an `Address` object. The type of the collection that is returned from a query is determined by the property in the select list.

We could continue drilling down and return just the `state` of the address for `Customer` with id 5:

```java
String query = "SELECT c.address.state FROM Customer c where c.id=5";
List<String> results =
  em.createQuery(query, String.class)
    .getResultList();
```
  * **Notice:** We are chaining through the `Customer` -> `Address` -> `state` to grab just the specific property that we want to return from this query. Due to the fact that we are returning `c.address.state`, the returned collection would be typed `List<String>`.

<hr>

[Prev](review.md) | [Up](README.md) | [Next](fieldsThatAreCollections.md)

