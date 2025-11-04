---
layout: default
title: Delete operation
---


Call *EntityManager*'s `remove` on a managed entity to `DELETE` the corresponding row in the database on the next commit.

  * The entity becomes detached after the remove and remains available until it is garbage collected.

```java
Actor a = em.find(Actor.class, 1);
em.getTransaction().begin();

em.remove(a); // performs the delete on the managed entity

em.getTransaction().commit();

a.getFirstName();
// a is now a detached entity and does not correspond to a row in the db...
// ... however, it is still an object and can be used as such
```

Due to the obvious risk of a `DELETE`, Hibernate can sometimes rollback a transaction behind the scenes. If your `em.remove` call isn't being committed to the database you can always write a JPQL `DELETE` statement.

### Practice Exercise
In almost all cases you **DO NOT** want to delete any data from your database. Data is $ in today's world and deleting some would be throwing away valuable information. When Facebook 'deletes' your account, they are actually just deactivating it. All of your info is still permanently stored on there servers.

### Drill

1. In your *ActorDAO* create the following abstract method: `public boolean destroy(int id);`
> 1. Implement the `destroy` method in your *ActorDAOImpl*:
>
>    * Use the provided `id` to retrieve a managed *Actor* entity.
>
>    * Use `em.remove` to delete the managed entity.
>
>    * On `commit` the managed entity will be deleted.
>
>    * Presuming there is no error and the entity was found, return `true`, otherwise, return `false`.
>    
1. To test that your `destroy` is working, modify *ActorDAOTest* by commenting out your `update`, remove the entity you created and modified in the previous two Drills. Check MySQL; the entity should no longer be present in your database.

<hr>

[Prev](update.md) -- [Up](README.md) -- [Next](labs.md)

