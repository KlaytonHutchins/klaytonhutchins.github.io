---
layout: default
title: Lab
---


1. Create a new entity and JUnit test for the _category_ table.

    ```
    +-------+----------------------+------+-----+---------+----------------+
    | Field | Type                 | Null | Key | Default | Extra          |
    +-------+----------------------+------+-----+---------+----------------+
    | id    | smallint(5) unsigned | NO   | PRI | NULL    | auto_increment |
    | name  | varchar(25)          | NO   |     | NULL    |                |
    +-------+----------------------+------+-----+---------+----------------+
    ```

1. Add a bi-directional, many-to-many relationship between *Film* and *Category*. Use *film_category* as the join table. Be sure to write the get/set/add/remove methods.

1. Update your test cases for *Category* and *Film* to exercise the new relationship.


<hr>

[Prev](eagerAndLazy.md) -- [Up](README.md)

