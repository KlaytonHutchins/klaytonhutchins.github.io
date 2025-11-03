---
layout: default
title: Lab
---

## Labs

1. Create a class `CRUDClient` in your `com.example.jpavideostore.client` package.

1. You will be writing JPQL queries to manipulate data and will need to set up an `EntityManagerFactory` as well as an `EntityManger`.

1. Create a method `updateNullEmails`
   * In a terminal write a SQL query to display all customers that have null or empty string emails.
   * This method should find all of the _Customer_ records who have no email addresses (empty string or null values) and update them with a new email whose format is _firstname.lastname@sdcustomer.org_.
   * In a `main`, call this method.
   * Check the database to make sure the changes were made.

1. Create a method `addNewAddress`
   * This method should create a new `Address` object, and set its values to your personal information (`street`, `city`, `state`, `postalCode`, `phone`).
   * Persist your `Address` object.
   * Print out the object.
   * In a `main`, comment out the call to `updateNullEmails` and run this method.
   * Check to make sure the new _Address_ was added to the database.

1. Create a method called `deleteAddress`
   * This method should take a address's `id` as a parameter.
   * Write the logic to delete a _Address_ from the database based on its `id`.
   * In a `main`, comment out the call to `addNewAddress` and run your method, passing in the `id` value of the _Address_ you created previously.
   * Check the database to make sure the _Address_ was deleted.

<hr>

[Prev](delete.md) -- [Up](README.md)

