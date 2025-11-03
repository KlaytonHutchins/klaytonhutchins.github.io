## Labs
1. Create a file *JPQLRelationshipsLab* in the `com.example.jpavideostore.client` package.

1. Create a file *JPQLRelationshipsTests* in the `test` src folder, and configure it as a JUnit test file.

1. Write a method in the *JPQLRelationshipsLab* class named
   `public List<Store> getStoresByState(String state)`.

   * The method takes a single String as an argument (state).

   * Return a list of stores.

   * Write a test in your `JPQLRelationshipsTests` to ensure that your method is working.
      * Query for the state of "Washington".

1. Write a method
   `public List<Rental> getRentalsForCustomerWithCustomerId(int id)`.

   * The method takes a single int as an argument (id).

   * Return a list of rentals associated with the customer of the provided id.

   * NOTE: The list of rentals is lazily initialized by default, instead of eagerly fetching the list, so use a `JOIN FETCH`.

   * Write a test to ensure that the rentals are retrieved (and that the correct number of rentals are retrieved).

1. Write a method
   `public List<Film> getFilmsForActorWithId(int id)`.

    * Return the list of films associated with that actor.

    * Write a test to ensure your new method is working.

    * ***NOTE***: The list of films is lazily initialized by default, instead of eagerly fetching the list, so use a `JOIN FETCH`.

1. Write a method
   `public int getNumberOfFilmsForCategoryWithName(String name)`.

   * The method should return how many *Film*s are in a certain *Category*.

   * ***Note:*** You can call `.size()` on the result from the query to solve this. Don't bother using a `COUNT`. This is giving you additional experience with `JOIN FETCH` in JPQL, rather than writing SQL aggregate queries.

   * Write a test to ensure your new method is working. Call your method using the `Comedy` category name.

<hr>

[Prev](fieldsThatAreCollections.md) | [Up](README.md)

