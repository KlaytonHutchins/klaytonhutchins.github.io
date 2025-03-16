---
layout: default
title: Labs 
---

1. Open your `VideoStore` workspace and go into the `VideoStoreREST` project.

1. In `VideoStoreREST` create a Folder (_not_ a Source Folder) named `src/main/webapp/`, and in it create the file `index.html` with the following content:

   ```html
   <!DOCTYPE html>
   <html>
   <head>
   <meta charset="UTF-8">
   <title>REST Video Store</title>
   <script type="text/javascript" src="js/filmFunctions.js"></script>
   </head>
   <body>
     <h1>Welcome to REST Video Store</h1>
   
     <form name="filmForm">
       <input type="number" name="filmId">
       <button name="lookup">Get Film by Id</button>
     </form>
     <div id="output">
       <div id="filmData"></div>
       <div id="actorData"></div>
     </div>
   
   </body>
   </html>
   ```

1. Under `src/main/webapp/`, create a subdirectory named `js/`.  In `src/main/webapp/js/` create `filmFunctions.js` with the following content:

   ```javascript
   window.addEventListener('load', function(e) {
     console.log('document loaded');
     init();
   });
   
   function init() {
     document.filmForm.lookup.addEventListener('click', function(event) {
       event.preventDefault();
       let filmId = document.filmForm.filmId.value;
       if (!isNaN(filmId) && filmId > 0) {
         getFilm(filmId);
       }
     })
   }
   
   function getFilm(filmId) {
     // TODO:
     // * Use XMLHttpRequest to perform a GET request to "api/films/"
     //   with the filmId appended.
     // * On success, if a response was received parse the film data
     //   and pass the film object to displayFilm().
     // * On failure, or if no response text was received, put "Film not found" 
     //   in the filmData div.
   }
   
   function displayFilm(film) {
     let dataDiv = document.getElementById('filmData');
     dataDiv.textContent = '';
     // TODO:
     // * Create and append elements to the data div to display:
     // * Film title (h1) and description (blockquote).
     // * Rating, release year, and length as an unordered list.
   }
   ```

1. In `getFilm`, use `XMLHttpRequest` to query your REST api to retrieve a single film by id.  Create an `onreadystatechange` function to display the response text in the filmData div.

1. If the request fails, display "Film not found." in the filmData div.

1. Change your `onreadystatechange` code to convert the responseText to JSON, parse the response data to create a film object.  Pass the film to `displayFilm`.

1. Implement `displayFilm` to add elements to the filmData div displaying the fil title as a header, description as a blockquote, and rating, release year, and length as an unordered list.

### Add and Consume a New API Route

1. In your `repositories` package create a new `ActorRepository`, with a query method that takes an `Integer` film id and returns `List<Actor>`.

   ```java
   public interface ActorRepository extends JpaRepository<Actor, Integer> {
     List<Actor> findByFilms_Id(int filmId);
   }
   ```

1. Add a method in `FilmService` to call the new repository method, passing a film id and returning the list of actors.

1. In `FilmController` add a new method mapped to `api/films/{id}/actors` that takes a film id and returns `List<Actor>`, by calling your new service method.  Test this route with Postman.

1. Modify `filmFunctions.js`.  When a film has been successfully retrieved, pass its id to a new function that uses `XMLHttpRequest` to retrieve the list of actors for the film.  Display the actors as an unordered list in the actorData div.

### Sending a POST Request

1. In `src/main/webapp/index.html`, add a new form below the output div.  Give it fields for film title, description, release year, rating, and length.  Give it a button with a unique name.

1. In `filmFunctions.js` write a method that constructs a JavaScript object with film properties whose values come from the form field values.  Use XHR to send this object as JSON to your `api/films` POST route.

1. If the POST requests succeeds, parse the returned response body and pass it to `displayFilm`.

1. In `init`, add an event listener to your new form's button, which calls this method.

1. Confirm you can use your form to add a film.

<hr>

[Prev](post.md) -- [Up](README.md)

