## Dealing with Recursive JSON

We can get into situations where our objects have other objects nested within them.

When the Jackson serialization library translates these objects to json it will include every property of the entity.

This can lead to nested json objects that continuously reference each other, causing _recursion_.

> #### recursion  
> When a procedure calls itself one or more times. Without an exit condition, it will continue infinitely (or until the call stack overflows).

```java
public class User {
  private int id;
  private String firstName;
  private String lastName;
  private List<Account> accounts;;
  // ...
}

public class Account {
  private int id;
  private String type;
  private double balance;
  private User owner;
  // ...
}
```

In this example our `User` will have a list of `Account`s, which in turn have a `User` within them... which in turn have a list of `Account`s.

It never ends and will cause your program to hang with a stack overflow error.


Serializing `User`:
```json
{
    "id": 3,
    "firstName": "Kristen",
    "lastName": "Johnson",
    "accounts": [
        {
            "id": 1,
            "type": "Savings",
            "balance": 22345.45,
            "owner": {
                "id": 3,
                "firstName": "Kristen",
                "lastName": "Johnson",
                "accounts": [
                    {
                        "id": 1,
                        "type": "Savings",
                        "owner": { ...
```

Serializing `Account`:

```json
{
    "id": 1,
    "type": "Savings",
    "balance": 22345.45,
    "owner": {
        "id": 3,
        "firstName": "Kristen",
        "lastName": "Johnson",
        "accounts": [
            {
                "id": 1,
                "type": "Savings",
                "balance": 22345.45,
                "owner": {
                    "id": 3,
                    "firstName": "Kristen",
                    "lastName": "Johnson",
                    "accounts": [ ...
```

We can configure our Java classes with a few annotations so that the Java can be mapped to json properly.

### Dependencies (again)

While our Spring Boot app already has the Jackson libraries, if our entity classes are defined in a non-Spring project, we need to add the Jackson annotations dependency.

```java
implementation group: 'com.fasterxml.jackson.core', name: 'jackson-annotations', version: '2.13.3'
```

* _Make sure_ the version matches the corresponding Jackson version pulled into the Boot project.

### `@JsonIgnore`

The simplest way to negate this behavior is to ignore the field that defines the relationship.

* You only need this on one side of the relationship to cut off the recursion.

Ignoring the field will tell the Jackson Library not to include this field in the resulting json.


```java
public class User {
  private int id;
  private String firstName;
  private String lastName;

  @JsonIgnore
  public List<Account> accounts;

  // ...
}
```

Serializing `User`:
```json
{
    "id": 3,
    "firstName": "Kristen",
    "lastName": "Johnson"
}
```

Serializing `Account`:
```json
{
    "id": 1,
    "type": "Savings",
    "balance": 22345.45,
    "owner": {
        "id": 3,
        "firstName": "Kristen",
        "lastName": "Johnson"
    }
}
```

Note that the choice of which side of the relationship to put the `JsonIgnore` is up to you.

* Often it will be on the "One" side of a `OneToMany` - on the collection property.

This can also be used to hide information that you do not want to leave your secure backend as json (such as  password).

### Practice Exercise
Note that ignoring a field like `password` could prevent users from registering or updating their password.
To allow such a field to be sent, but not returned, you can control access to the property:
```java
@JsonProperty(access = Access.WRITE_ONLY)
private String password;
```
This tells jackson to only deserialize, not serialize, this field.

### `@JsonIgnoreProperties`

If we do want the relationship field to be serialized into our json we can utilize `@JsonIgnoreProperties`

```java
public class User {
  private int id;
  private String firstName;
  private String lastName;

  @JsonIgnoreProperties({"owner"})
  private List<Account> accounts;
  //...
```

This tells the JSON serializer to include the nested entity in the JSON, but ignore certain of its properties.

Serializing `User`:
```json
{
    "id": 3,
    "firstName": "Kristen",
    "lastName": "Johnson",
    "accounts": [
        {
            "id": 1,
            "type": "Savings",
            "balance": 22345.45
        }
    ]
}
```

Serializing `Account`:
```json
{
    "id": 1,
    "type": "Savings",
    "balance": 22345.45,
    "owner": {
        "id": 3,
        "firstName": "Kristen",
        "lastName": "Johnson",
        "accounts": [
            {
                "id": 1,
                "type": "Savings",
                "balance": 22345.45
            }
        ]
    }
}
```

### Practice Exercise
Whenever we have a bi-directional relationship set up with our JPA mappings, we are going to need to take steps to avoid recursive json.

<hr>

[Prev](javaAndJson.md) -- [Up](README.md) -- [Next](labs.md)

