## Controller Configuration

Spring Boot finds your controller by component-scanning the application's base package. It will autowire any dependencies, such as a DAO, provided it can find a satisfactory bean.

1. Inject your DAO in your controller using an `@Autowired` annotation, so you can access it from within your `@RequestMapping` methods.

   ```java
   @Controller
   public class FilmController {
     @Autowired
     private FilmDAO filmDAO;
   }
   ```

1. When you retrieve a JPA entity from a DAO, the returned entity is unmanaged.

   * Any changes you make to the entity will have no effect on the database, unless you merge it back into the persistence context. 

   ```java
   @Controller
   public class FilmController {
     @Autowired
     private FilmDAO filmDAO;

     @RequestMapping(path = "getFilm.do", method = RequestMethod.GET)
     public ModelAndView getFilm(@RequestParam("fid") int fid) {
       ModelAndView mv = new ModelAndView();

       Film film = filmDAO.findById(fid);     
       // film is unmanaged after it is outside of the transaction that exists in the DAO

       mv.addObject("film", film);
       mv.setViewName("WEB-INF/film/show.jsp");
       return mv;
     }
   }
   ```

### Drill
> 1. Create a JSP file called *index.jsp* in your `src/main/webapp/WEB-INF` directory.
>
>    * Create a new directory inside of `src/main/webapp/WEB-INF` named `film`.
>
>    * Create a JSP file called *show.jsp* in that directory.
>
>    ```
>    src/main/webapp/
>    ├── WEB-INF
>        ├── film
>        │   └── show.jsp
>        └── index.jsp
>    ```
>
> 1. In the *com.example.bootmvc.controllers* package:
>    * Add a class called *FilmController* to that package. Use the `@Autowired` annotation to inject your DAO.
>    * In *FilmController*, create a request handling method that returns the name of your _index.jsp_.
>    * Map this method to the request paths `/` and `index.do` with the method `GET`.
>      ```java
>      @RequestMapping(path={"/","index.do"})
>      public String index() {
>        return "WEB-INF/index.jsp";
>        // return "index"; // if using a ViewResolver.
>      }
>      ```
>
> 1. Create a route (or RequestMapping) in _FilmController_ mapped to `getFilm.do`.
>    * The method will take a single parameter `fid` as a `@RequestParam`.
>    * Use the _DAO_ `findById` method to find a film by the provided id and add it to the model.
>    * Return the view `WEB-INF/film/show.jsp`.
>
> 1. Modify your `index.jsp` file to invoke your controller's `getFilm.do` route
>    ```HTML
>    <form action="getFilm.do" method="GET">
>      Film ID: <input type="text" name="fid" />
>      <input type="submit" value="Show Film" />
>    </form>
>    ```
>
> 1. Modify your `show.jsp` file to display the film that will be attached to the model.
>    ```HTML
>    <div>
>      <h5>${film.title} (${film.releaseYear})</h5>
>      <p>${film.description}</p>
>    </div>
>    ```

<hr>

[Prev](springBootAndJPA.md) | [Up](README.md) | [Next](applicationProperties.md)

