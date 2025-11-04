---
layout: default
title: Demo: Film List Route
---


Lets try to add a route to retrieve a collection of films from out database.  

1. Create `FilmDAO`, `FilmDAOJpaImpl`, and `FilmController` files.  

1. Configure them the same way we did for the _Address_ files.

1. Create a method in your _DAO_ that selects all the films in your database and `JOIN FETCH`es the collection of actors.
    ```java
    public List<Film> findAll(){
      String query = "Select f from Film f JOIN FETCH f.actors";
      return em.createQuery(query, Film.class).getResultList();
    }
    ```

1. Create a controller method called `index` that has the mapping of `/api/films`, and calls the filmDAO `findAll` method.
    ```java
    @RequestMapping(path="api/films", method=RequestMethod.GET)
    public List<Film> index(){
      return filmDAO.findAll();
    }
    ```

1. If you hit the route your program will hang. This is because Films have a collection of Actors, which have a collection of Films... We have recursive json and need to annotate these two entities using `@JsonBackReference` and `	@JsonManagedReference` or `@JsonIgnore`.  

   In order to do this you will need to import the library of these annotations into your JPA project. Add this Gradle dependency to your `build.gradle` and perform a gradle refresh.
   ```groovy
   implementation group: 'com.fasterxml.jackson.core', name: 'jackson-annotations', version: '2.13.3'
   ```

1. In your Actor class add a `@JsonIgnore` to the field `private List<Film> films`. This will cause the Jackson library to skip the serialization of that field.

    We would have to manage loading all of the other lazy loaded collections in the _Film_ class as well. For the sake of time, put an `@JsonIgnore` on the other relationships.

    When you are finished the _Film_ class should have a single relationship that is not ignored, the list of actors.

1. Run the program and hit the route `http://localhost:8080/api/films`. You should get an array of json _Film_ objects each with their own array of _Actor_ objects.

### Practice Exercise
The reason we had to `JOIN FETCH` the list of actors is due to the fact that `@ManyToMany` relationships are lazily loaded by default.

If a lazy-loaded collection is passed to the Jackson Library we would see a `failed to lazily initialize a collection of role: entities.Language.films` exception thrown.

This will be true for any field that is lazily loaded by default.

<hr>

[Prev](addressCreateRoute.md) -- [Up](README.md)

