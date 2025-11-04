---
layout: default
title: Presidents Site with DAO
---


This project, `DAOPatternPresidents`, uses a `PresidentDAO` that connects to a database.

You will be adding code to an existing servlet, and manually testing the site with a mock DAO (no JUnit tests).

### Setup

1. Download [DAOPatternPresidents.zip](resources/DAOPatternPresidents.zip) and import it into Eclipse

2. Load the database.

   `DAOPatternPresidents/DBSETUP.txt`
   * Follow the instructions in this file to load the `historydb` database.


### Existing Functionality

This `PresidentDAO` has four methods:
* `List<President> getPresidents()`
* `President getPresidentByTermNumber(int number)`
* `List<President> findByParty(String string)`
* `List<President> findByLastName(String string)`

The `index.html` page contains two forms and one link. All requests go to `/presidentInfo`, but the servlet will return different information, depending on the request parameters.


### Lab

You will be adding code to `com.example.servlets.PresidentServlet`, and first testing it with a mock DAO.

1. Servlet functionality:
   * If `party` is present in the request and not empty, display an unordered list of the full names of presidents of that party.
   * If `lastName` is present in the request and not empty, display an unordered list of the full names of presidents with that last name.
   * If `termNumber` is present in the request and not empty, display that president's full data. (Only display the president's full data when `termNumber` is requested.)
   * If all request parameters are `null` or an empty string, display all presidents' full names as an unordered list.

1. Additionally, each full name displayed via `party`, `lastName`, or no request parameters must be an HTML link to `presidentInfo?termNumber=TERM_NUMBER`, where `TERM_NUMBER` is that president's term number.

1. In `com.example.data.president`, create a `MockPresidentDAO` with three `President` objects stored in a `List<President>` instance field.
   * These `President` objects should satisfy test criteria, such as two having the same last name, two having the same party, and all having a different term number.
     * Methods, such as `getPresidentByTermNumber`, will use the instance field to find the requested `President`.
   * Set your servlet to use an instance of this class in the `init()` method.
   * Test your application's functionality.

1. Now change the servlet to use `JDBCPresidentDAOImpl` and retest the application.

<hr>

[Up](../README.md)
