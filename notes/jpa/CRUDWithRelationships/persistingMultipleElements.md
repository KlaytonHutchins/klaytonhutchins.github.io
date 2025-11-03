## Persisting Multiple Entities

Persisting nested entities requires some additional effort.

1. First you must create both the parent and the child entity.

1. Second, add the child to the parent (using a setter method).

1. Third, persist the parent entity.

   * This will create the entity in your database and assign it a generated Primary Key. Without the Primary Key, the child entity would not be able to assign a value as a Foreign Key, and the association in the database would be impossible.

1. Finally, persist the child entity.

   * Now, when the row is created in the corresponding table, the parent entity's primary key can be assigned to the foreign key column of the child.


### Example
The following example illustrates the mechanics of this process in JPA.

If you wish to add a new _Rental_ to the database you will need to build and persist both a *Rental* and a *Payment* entity:

```java
public class PersistMultipleExample {
	private static EntityManagerFactory emf 
		= Persistence.createEntityManagerFactory("VideoStore");

	public static void main(String[] args) {
		EntityManager em = emf.createEntityManager();
		
		// 1: Create an instance of a Rental entity.
		Rental r = new Rental();

		// 2: Call the various setter methods on your new entity to populate its fields.
		r.setStaff(em.find(Staff.class, 1));
		r.setCustomer(em.find(Customer.class, 1));
		r.setInventoryItem(em.find(InventoryItem.class, 1));
		r.setRentalDate(LocalDateTime.now());
		r.setReturnDate(LocalDateTime.now());

		// 3: Create an instance of a *Payment* entity.
		Payment p = new Payment();

		// 4: Call the setter methods on the *Payment* entity.
		p.setAmount(0.99);
		p.setPaymentDate(LocalDateTime.now());

		// 5: Add the *Payment* to the *Rental* by calling the `addPayment()` method.
		r.addPayment(p);

		// 6: Persist the *Rental*, then the *Payment* using *EntityManager*’s
		// `persist()` method.
		em.getTransaction().begin();
		em.persist(r);
		em.persist(p);
		em.getTransaction().commit();
	}
}
```

<hr>

[Prev](persistingWithForeignKeys.md) | [Up](README.md) | [Next](cascading.md)

