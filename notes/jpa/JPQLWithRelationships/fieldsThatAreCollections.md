## Queries with Nested Collections
In the `@OneToMany` side of a relationship or either side of a `@ManyToMany`, our entity will contain a collection of objects.

We are going to use the `Film` and `Actor` classes in our examples for this chapter.

```java
@Entity
public class Film {
  @Id
  @GeneratedValue(strategy = GenerationType.IDENTITY)
  private int id;

  private String title;

  private String description;

  // ...

  @ManyToMany(mappedBy="films")
  private List<Actor> actors;

  @ManyToMany(mappedBy="films")
  private List<Category> categories;

  @ManyToMany(mappedBy="films")
  private List<Store> stores;

  // ...
}
```

```java
@Entity
public class Actor {
  @Id
  @GeneratedValue(strategy=GenerationType.IDENTITY)
  private int id;

  @Column(name="first_name")
  private String firstName;

  @Column(name="last_name")
  private String lastName;

  @ManyToMany()
  @JoinTable(name="film_actor",
      joinColumns = @JoinColumn(name="actor_id"),
      inverseJoinColumns = @JoinColumn(name="film_id")
  )
  private List<Film> films;

  // ...
}
```

### WHERE Clause with Nested Objects
We can search through a collection to see if another entity is already a `MEMBER OF` that collection.

```java
Actor penelopeGuiness = em.find(Actor.class, 1);

String query = "SELECT f FROM Film f WHERE :actor MEMBER OF f.actors";

List<Film> results= em.createQuery(query, Film.class)
      .setParameter("actor", penelopeGuiness)
      .getResultList();
```

### Collections in the SELECT List
Collections are also just properties of our entity objects. We can query directly for them if we just want to get that subset of data.

For example lets say we want to SELECT all the actors for the film with title "ACADEMY DINOSAUR".

```java
String query = "SELECT f.actors FROM Film f where f.title='ACADEMY DINOSAUR'";
List<Object> results= em.createQuery(query, Object.class)
      .getResultList();

List<Actor> actors = new ArrayList<>();

results.stream().forEach(x->actors.add((Actor)x));
```

**Notice:** The additional logic to cast `Object`s to `Actor`s. The query is going to return a list of lists. In order to end up with a `List<Actor>`, we need to create a second array and manually cast each `Object` returned from the query.

### How to Query Lazily Loaded Collections

To optimize performance you will want to predominantly use `LAZY` loading. However, there are plenty of instances where you will want access to the collection when it is queried.

* If these collections are lazily loaded, you will get an exception. For instance, the following method will generate a lazy loading exception:

  ```java
  public List<Actor> getActorsForFilmWithTitle(String title) {
    EntityManagerFactory emf
                = Persistence.createEntityManagerFactory("VideoStore");
    EntityManager em = emf.createEntityManager();
    String queryString = "SELECT f FROM Film f WHERE f.title = :title";
    Film film = em.createQuery(queryString, Film.class)
                  .setParameter("title", title)
                  .getResultList()
                  .get(0); 
    em.close();
    
    // EntityManager is closed, so can't fetch lazy-loaded collection
    List<Actor> actors = film.getActors();
    // Exception in thread "main" org.hibernate.LazyInitializationException: failed to lazily initialize a collection of role: com.example.jpavideostore.entities.Film.actors, could not initialize proxy - no Session
    
    return actors;
  }
  ```

Lazy collections are loaded by default by JPA upon first access, which means calling any method on the collection will cause JPA to re-query the database for the appropriate records, _provided the entity manager still has access to the database_.

* A common solution is to access the collection field in some way, such as calling its `.size()`, before closing the entity manager.

  ```java
    Film film = em.createQuery(queryString, Film.class)
                  .setParameter("title", title)
                  .getResultList()
                  .get(0); 
    film.getActors().size(); // Access collection size() to force fetch
    em.close();
  ```

A better way to query *LAZY* loaded collections is to use a `JOIN FETCH` on the property inside of a typed query.

`JOIN FETCH` retrieves both the parent entity and its lazily loaded collection in one query, ensuring that the collection will be available along with the entity even after the entity manager is closed.

The syntax is the same as queries we have seen previously, with the exception of the addition of `JOIN FETCH`. Consider the following method:

```java
public List<Actor> getActorsForFilmWithTitle(String title) {
  EntityManagerFactory emf
              = Persistence.createEntityManagerFactory("VideoStore");
  EntityManager em = emf.createEntityManager();
  String queryString = "SELECT f FROM Film f JOIN FETCH f.actors WHERE f.title = :title";
  Film film = em.createQuery(queryString, Film.class)
                .setParameter("title", title)
                .getResultList()
                .get(0); 
  em.close();
    
  // Actors were retrieved while em was still open.
  List<Actor> actors = film.getActors();
    
  return actors;
}
```

This query would result in you having a `Film` object with all of its scalar types populated, as well as it having the `actors` collection populated.

### Practice Exercise
> **N+1**
>
> The N+1 query issue happens when you forget to fetch an association and then you need to access it. The original query for the encompassing Object results in 1 SQL query being run. To aggregate the collections associated with each one of the returned objects we would have to perform another N queries. This results in a total of N+1 queries being executed.  
>
> ```java
> "SELECT c FROM Customer c" // 1 query executed to get all the Customer objects in the db without there corresponding rentals collection populated.
>
> "SELECT r FROM Rental r WHERE r.customer.id = :customerId" // N queries executed to get every rental for each customer returned from the initial query.
> ```

<hr>

[Prev](fieldsThatAreObjects.md) | [Up](README.md) | [Next](labs.md)

