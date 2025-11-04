---
layout: default
title: Lab
---


1. Create a class in the `com.example.jpavideostore.client` package named `JPQLLab` (this is where you will complete the following steps).

1. Create a method that uses JPQL to retrieve all Customers in the
database whose id is between 100 and 110. Output their first name, last
name, and email. (Hint: You can use the `BETWEEN` reserved word in JPQL
just like SQL.)

1. Modify your previous solution, using parameters to set the minimum
and maximum ids instead of hard-coding them into the query String.

1. Refactor your program into a method in the _JPQLLab_ class named `getRangeOfCustomers`.

   * the method should take two arguments (minId, maxId), both ints

   * return the correct list of *Customer*s given these inputs

   * Create a new class in the *test* src folder named _JPQLTest_

     * Write a test to ensure that `getRangeOfCustomers` retrieves *Customer* objects within the correct range

1. Write a method in the *JPQLLab* class named `getCustomerEmailByName`.

   * the method takes two Strings as an argument (fname, lname)

   * return either a single String, or `null`

   * write a test to ensure that a *Customer* can be retrieved (choose a customer that exists to test)

1. Write a method in the *JPQLLab* class named `getFilmByTitle`.
   * the method takes one String as an argument (filmTitle)

   * return either a single Film object, or `null`

   * write a test to ensure that a *Film* can be retrieved.

1. Write a method in the *JPQLLab* class named `getFilmsTitlesByReleaseYear`.
   * the method takes one int as an argument (year)

   * return the correct list of film titles (`List<String>`).

   * write a test to ensure that the correct _Film_ objects were retrieved.

<hr>

[Prev](queryParams.md) -- [Up](README.md)

