---
layout: default
title: Cascading
---

Manually persisting multiple related entities is cumbersome. Thankfully, the JPA has a means of simplifying this process.

By default an *EntityManager* operation will not be applied to related entities.

To propagate *EntityManager* operations to a related entity, include the `cascade` element in the relationship annotation.

  * Specify an array of operations to be cascaded.

  * The values, defined in the `CascadeType` enum, are `PERSIST`, `MERGE`, `REFRESH`, `REMOVE`, `DETACH`, or `ALL`.

```java
@Entity
public class Rental {
// ...
  @OneToMany(cascade=CascadeType.PERSIST)
  @JoinColumn(name = "rental_id")
  private List<Payment> payments;
// ...
}
```

### Practice Exercise
> Cascade only propagates the persist, merge, etc. actions. It does not cascade the actual data changes that will be saved by a persist or merge. You still need to set data on both sides of a bi-directional link so that persists will save the correct data in each entity.


### Drill
>
> To get some experience with `cascade` we will create a method to add a new film to a newly discovered actor's filmography (for the sake of this example, lets assume that our application has functionality to both create a new actor and film simultaneously).
>
> 1. Add the `cascade` element to the `@ManyToMany` relationship in *Actor* (the association to *Film*).
>
>    * Assign `cascade` an array, and the `PERSIST` and `REMOVE` types.
>
> 1. In *ActorDAO* add the following method stub `public Actor createActorAndFilm(Actor actor, Film film);`.
>
> 1. In *ActorDAOImpl* implement the `createActorAndFilm` method.
>    * Set the film object's language to a managed entity (use `em.find(Language.class, 1)`). This is a NOT NULL foreign key so it has to be set before we can persist the object.
>
>    * Add the provided film to the *Actor*'s list of films using the `addFilm` method we implemented.
>
>    * Persist the *Actor* entity within a transaction.
>
> 1. In *ActorDAOTest* use your `createActorAndFilm` method to create both objects.
>
>    * Create a Film and Actor Object
>      * Give the Film:
>        * a title
>        * a rental rate
>        * a replacement cost
>      * Give the Actor:
>        * a first name
>        * a last name
>
>    * Print out the *Actor*'s `toString` as well as the *Film*'s `toString`. You can retrieve the film by using the *Actor*'s `getFilms().get(0)`.
>
> 1. If you want to remove these entries from your database, you can use the `destroy` method in *ActorDAOImpl* we set up earlier.

<hr>

[Prev](persistingMultipleElements.md) -- [Up](README.md) -- [Next](labs.md)

