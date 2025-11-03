## Labs

1. Create a bi-directional, many-to-one relationship between *Rental* and *InventoryItem*.

1. Update the test cases for *InventoryItem* and *Rental* to ensure the associations are working correctly.

1. Create a *Payment* entity mapped to the `payment` table with properties `id`, `amount`, and `paymentDate`.  The `payment` table looks like this:

   ```
   +--------------+------------------+------+-----+---------+----------------+
   | Field        | Type             | Null | Key | Default | Extra          |
   +--------------+------------------+------+-----+---------+----------------+
   | id           | int(10) unsigned | NO   | PRI | NULL    | auto_increment |
   | rental_id    | int(11)          | YES  | MUL | NULL    |                |
   | amount       | decimal(5,2)     | NO   |     | NULL    |                |
   | payment_date | datetime         | NO   |     | NULL    |                |
   +--------------+------------------+------+-----+---------+----------------+
   ```
   * Create a JUnit test to test the *Payment* entity.

1. Create a bi-directional, many-to-one relationship from *Payment* to *Rental*.  Update the unit tests for both entities to validate each side of the relationship.

1. In *Rental*, create *addPayment* and *removePayment* methods.

<hr>

[Prev](mappingOptions.md) -- [Up](README.md)

