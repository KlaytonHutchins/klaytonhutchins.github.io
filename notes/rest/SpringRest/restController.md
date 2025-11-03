---
layout: default
title: REST Controller
---

## REST Controllers

Our Spring MVC controllers dealt with `GET` requests for views, as well as `POST` requests from forms.

```java
@RequestMapping(path = "films.do", method = RequestMethod.GET)
public ModelAndView index() {
  ModelAndView mv = new ModelAndView("index.jsp");
  mv.addObject("films", filmDAO.index());
  return mv;
}
```

* Spring provides shortcuts for `@RequestMapping`:

  ```java
  @GetMapping(path = "films.do") // or just @GetMapping("films.do")
  public ModelAndView index() { ...
  ```

Because REST controllers deal with the full variety of HTTP verbs, these shortcuts are more convenient.

```java
@Controller
public class BookController {
  @GetMapping("api/books")
  @ResponseBody
  public List<Book> allBooks() { ... }

  @PostMapping("api/books")
  @ResponseBody
  public Book addBook(@RequestBody Book book) { ... }

  @PutMapping("api/books/{bookId}")
  @ResponseBody
  public Book replaceBook(@PathVariable Integer bookId, @RequestBody Book book) { ... }

  @DeleteMapping("api/books/{bookId}")
  @ResponseBody
  public void removeBook(@PathVariable("bookId") Integer id) { ... }

  // ...
}
```

You can put both `@RequestMapping` and `@ResponseBody` above a controller class declaration to precede every endpoint method with these annotations.
```java
@RequestMapping("api")
@ResponseBody
@Controller
public class BookController {
  @GetMapping("books")
  public List<Book> allBooks() { ... }

  @PostMapping("books")
  public Book addBook(@RequestBody Book book) { ... }
}
```

* The `allBooks` method will be automatically mapped to `"api/books"`.

`@RestController` implies both `@Controller` and `@ResponseBody`:

```java
@RequestMapping("api")
@RestController
public class BookController {
  @GetMapping("books")
  public List<Book> allBooks() { ... }
```

### Practice Exercise
Never use `Controller` or `RestController` as a class name, e.g. `public class RestController` or `public class Controller`. Creating classes with these names would override the Spring implementations and you would lose access to their respective annotations.

<hr>

[Prev](testing.md) -- [Up](README.md) -- [Next](mappingRequests.md)

