## Create operations

Up to now we have only been executing READ operations against out database. We have leveraged the `em.find` and `em.createQuery` methods provided to us by the _EntityManager_ to perform these operations.

JPA also provides us with methods to execute INSERT, UPDATE, and DELETE functionality.

To create an INSERT statement we can call `em.persist` and pass it a valid _entity_.

When you create a new entity instance in Java, it is initially untracked by our _EntityManager_ (meaning it has not been inserted into our database).

  * Call `em.persist` to make it tracked by the _EntityManager_.

  * On the next _commit_ it will be `INSERT`ed to the database.

* When working in a Java SE application, use `em.getTransaction` to get an _EntityTransaction_ object.

  * Use `em.begin` to start a new transaction.

  * Use `commit` to _commit_ or `rollback` to _rollback_ the transaction.


### Transactions and JPA
Similar to _Java Database Connectivity (JDBC)_, writing to the database through the Java Persistence API requires a _Transaction_ provided by the _EntityManager_.

### Practice Exercise
Quick refresher on database transactions.
>  
> A database provides a single source of truth (unless you have multiple database instances - but that is out of scope for us). As a result, it is critical to preserve data integrity in the database.
>
> Operations involving _reading_ from the database (e.g. `SELECT * FROM payment;` in SQL or `em.find(Payment.class, 1);` in JPA) do not require transactions/commits as they are merely accessing information.
>
> Conversely, _writing_ to the database involves altering/creating/deleting data, so it is critical that these processes complete uninterrupted to preserve data integrity.
> * Suppose an `INSERT` operation failed to complete because of an error. This could leave your database in an error state, or the data being written may be incomplete or compromised in some other way. For this reason it is critical to wrap _write_ operations in transactions so that there is a saved rollback point, and no other operations can interrupt the process.

Surround JPA write operations with *Transactions* retrieved from the _EntityManager_.

  * The following example illustrates how a new _Customer_ object could be persisted using a _Transaction_ within a DAO.

```java
public class CustomerDAOImpl implements CustomerDAO {

  public Customer create(Customer customer) {
    EntityManagerFactory emf =
        Persistence.createEntityManagerFactory("VideoStore");
    EntityManager em = emf.createEntityManager();

    // start the transaction
    em.getTransaction().begin();
    // write the customer to the database
    em.persist(customer);
    // update the "local" Customer object
    em.flush();
    // commit the changes (actually perform the operation)
    em.getTransaction().commit();

    // return the Customer object
    return customer;
  }

}
```

### Drill
1. Create a new entity called Actor with fields for:
>    * id
>    * firstName
>    * lastName
>    ```
>    -- actor
>    +------------+------------------+------+-----+---------+----------------+
>    | Field      | Type             | Null | Key | Default | Extra          |
>    +------------+------------------+------+-----+---------+----------------+
>    | id         | int(10) unsigned | NO   | PRI | NULL    | auto_increment |
>    | first_name | varchar(45)      | NO   |     | NULL    |                |
>    | last_name  | varchar(45)      | NO   | MUL | NULL    |                |
>    +------------+------------------+------+-----+---------+----------------+
>    ```
>    * Create get/set methods
>    * Don't forget to add the Entity to your _persistence.xml_
> 1. Create an _ActorTest_ file and write JUnit tests for the newly mapped entity.
1. Create a new package in the *src* directory named *com.example.jpavideostore.data*.

   * Create two files inside of the *data* package

     * an interface *ActorDAO*

     * a class *ActorDAOImpl*

1. In *ActorDAO* create a method stub:

   * `public Actor create(Actor actor);`

1. Implement the `create` method in your *ActorDAOImpl*.

   * Use a transaction to persist the entity passed into the method.

   * Be sure to commit the transaction.

1. Make sure that the `create` method is actually doing it's job.

   * In the *com.example.jpavideostore.client* package, create a *ActorDAOTest* file with a `main` method.
>
>    * Instantiate an instance of *ActorDAOImpl* and use your `create` method to persist a new *Actor* entity.
>
>    * Print out the *Actor*'s `toString` (if you don't have one, create one).
>
>    * Open MySQL in terminal and query the _actor_ table for your new actor.

<hr>

[Prev](README.md) | [Up](README.md) | [Next](update.md)

