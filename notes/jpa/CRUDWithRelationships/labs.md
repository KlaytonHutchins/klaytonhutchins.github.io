## Labs

1. Create a class `RelationshipCRUDClient` in the `com.example.jpavideostore.client` package.

1. Write a method `public void addNewActorToFilm()` that
   * Creates a new _Actor_ object with `firstName` and `lastName` values.
   * Sets up a relationship such that the new _Actor_ is in the movie **LADYBUGS ARMAGEDDON** (film with id  507).
   * Persists the actor to the database.

1. Create a `main` method in your `RelationshipCRUDClient` class. Have it invoke your `addNewActorToFilm` method.
   * Check your SQL database to see if the new Actor was created, and that the appropriate relationship was added to the `film_actor` table.

1. Write a method `public void newCustomerAndAddress()` that
   * Creates a new _Address_ with the following values set:
     * `street`
     * `city`
     * `state`
     * `phone`
   * Creates a new _Customer_ object with the following values set:
     * `firstName`
     * `lastName`
     * `store` (use the store with id 1)
     * `email`
     * `createdAt` (use `new Date()` to get todays date)
     * `address` (use the address you just created)
   * Add a `CascadeType.Persist` to the `@OneToOne` annotation on the *Customer*'s `address` field.
   * Persists the _Customer_ to the database.

1. Comment out the call to `addNewActorToFilm` and invoke your `newCustomerAndAddress` method in `RelationshipCRUDClient`'s `main` method.
   * Check your SQL database to see if the new _Address_ and _Customer_ objects were created.

<hr>

[Prev](cascading.md) -- [Up](README.md)

