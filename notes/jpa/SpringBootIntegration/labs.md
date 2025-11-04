---
layout: default
title: Lab
---


You are going to be writing a number of request handlers in the `FilmController`, as well as adding some supporting methods in the `FilmDAO`. The goal is to have functional read operations for the *Film* entity so that a user can view a list of films (a master list) and, after selecting a film, see a detailed view of that film.

1. Add a  `List<Film> findAll()` method to your FilmDAO. Implement the method in your FilmDAOJpaImpl class using a JPQL query. This method should find all the films in the database and return them as a _List_ .

1. In your `/` route's method, inject the `Model` by adding it as a parameter; retrieve the film list from the DAO and add it to the model.

   ```java
   @RequestMapping(path = "/", method = RequestMethod.GET)
   public String index(Model model) {
     // TODO : Retrieve film list, add it to the model.

     return "/WEB-INF/index.jsp";
   }
   ```

1. In your `index.jsp`, hyperlink each title such that clicking on a film's title will direct through the `show` route and display that film's detail page.
   * Use the `getFilm.do` route we set up in an earlier _Skill Drill_.
   * You will need to add the `core` tag library. `<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c"%>`
   * ***NOTE***: An example of a hyperlink to the first film might be:

   ```html
   <a href="getFilm.do?fid=1">ACADEMY DINOSAUR</a>
   ```

   * You will need to dynamically add the film's `id` to the query parameter with expression language with the parameter name `fid`. (They are hardcoded above.)
   * You may want to set the database logging level to `WARN` in `application.properties`.  

1. When a film's title is clicked on, the user should be sent to the detail view (`show.jsp`) which displays the:

   * title
   * release year
   * description
   * length

<hr>

[Prev](applicationProperties.md) -- [Up](README.md)

