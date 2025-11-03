---
layout: default
title: Configuring the Data Access Object to Utilize Spring
---

## Configuring the Data Access Object to Utilize Spring

We configure our DAOs with annotations so that _Spring Boot_ will manage them and their dependencies.

1. Mark the Impl class as `javax.transaction.Transactional` to have Spring automatically start a transaction for each _DAO_ method and commit the transaction at the end of the method.

   ```java
   @Transactional
   public class ActorDAOImpl implements ActorDAO {
     // ...
   }
   ```
   * An unchecked (runtime) exception will trigger a rollback.

1. Also above the class definition, add the `@Service` annotation.

   * Adding `@Service` will allow Spring Boot to create the _DAO_ bean (found through component scanning) and inject it into the _Controller_ using `@Autowired`.

   ```java
   @Transactional
   @Service
   public class ActorDAOImpl implements ActorDAO {
     // ...
   }
   ```

1. Inject an *EntityManager* into a field using the `@PersistenceContext` annotation.

   ```java
   @Transactional
   @Service
   public class ActorDAOImpl implements ActorDAO {

     @PersistenceContext
     private EntityManager em;
     // ...
   }
   ```

   * You can now use this `em` field in your _DAO_ methods to call `find()`, `persist()`, etc.

   * This is a container-managed *EntityManager*, so you should **NEVER** call `close()` on it.

### Drill
> 1. In *com.example.bootmvc.data* create an interface called *FilmDAO* that exposes a single method: `Film findById(int id);`.
>
> 1. Next create a class that implements the interface called *FilmDAOJpaImpl*.
>
>    * Follow the steps listed above to configure the DAO implementation.
>      * Instead of retrieving the *EntityManager* from the *Persistence*, declare an *EntityManager* as a field and annotate it with `@PersistenceContext`
>    * Be sure to mark your *FilmDAOJpaImpl* with both `@Transactional` and `@Service`.
>    * Add code into `findById` to retrieve a *Film* using the *EntityManager* `find` method.

<hr>

[Prev](multiProject.md) -- [Up](README.md) -- [Next](springBootAndJPA.md)

