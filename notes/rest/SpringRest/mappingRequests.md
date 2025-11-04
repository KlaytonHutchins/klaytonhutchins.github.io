---
layout: default
title: Request Mapping with Spring REST
---


### CRUD with REST

CRUD stands for Create/Read/Update/Delete regarding data storage and manipulation.

* On a blog, you **Create** a post, a user **Reads** a post, you can **Update** a post, and you can **Delete** a post.

Over the primary communications protocol of the web, HTTP, we use request methods that have meaning to the server:

| CRUD Op. | HTTP Verb | URI                  | Request Body | Response Body |
|----------|-----------|----------------------|--------------|---------------|
| Read     | GET       | `/api/v1/books`      |              | Collection of representations of all _book_ resources |
| Read     | GET       | `/api/v1/books/17`   |              | Representation of _book_ `17` |
| Create   | POST      | `/api/v1/books`      | Representation of a new _book_ resource | Description the result of the operation |
| Update   | PUT       | `/api/v1/books/17`   | Representation of a new version of _book_ `17` | |
| Update   | PATCH     | `/api/v1/books/17`   | Description of changes to make to _book_ `17` | |
| Delete   | DELETE    | `/api/v1/books/17`   |              | |

### `@PathVariable`, Why It's Important for REST

The presence of `{}` in a controller method's `@RequestMapping` always signifies the presence of a _path variable_.

* We use these to access a specific resource in an API.

The `@PathVariable` annotation accesses the variable from a request.

```java
@RequestMapping("api/v1")
@RestController
public class BookController {
  @PutMapping("books/{bookId}")
  public Book replaceBook(@PathVariable Integer bookId, @RequestBody Book book) { ... }
```

Will pull a parameter value from a URL Path such as:
```
http://localhost:8080/api/v1/books/17
```

If the curly-braced path element doesn't match your parameter name, specify it in `@PathVariable`:

```java
  @DeleteMapping("books/{bookId}")
  public void removeBook(@PathVariable("bookId") Integer id) { ... }
```

##### Implementation

In the controller route below we have created a method `getEmployee` mapped to `api/employees/{id}`.

```java
@GetMapping("api/employees/{id}")
@ResponseBody
public Employee getEmployee(@PathVariable int id){
  return dao.findEmployeeById(id);
}
```
* This method will return a single `Employee` object, serialized as JSON.
* Included in the route `api/employees/{id}` is a `@PathVariable` (`id`) represented by the `{id}` in the URL.
* To access this value we annotate a method parameter with `@PathVariable` and give the variable the same name as indicated in the `{}`s
* Path variables are `String` values.
  * Spring will attempt to convert the `String` value to the type of the annotated parameter.
  * If it cannot convert the value properly, it will throw an exception.
* When a `@PathVariable` is present, this controller method **cannot** be called without the value provided in the URL.

### Multilevel Resources

In the above example we only concerned ourselves with CRUD for the products themselves, but resources can have multiple levels of access to them.

If we create a _BookReviewController_, each _review_ corresponds to a specific book.

| Action  | HTTP Method |  Url Template |
|---------|-------------|---------------|
| LIST    | GET         | `/api/v1/books/{bookId}/reviews` |
| READ    | GET         | `/api/v1/books/{bookId}/reviews/{reviewId}` |
| CREATE  | POST        | `/api/v1/books/{bookId}/reviews` |
| REPLACE | PUT         | `/api/v1/books/{bookId}/reviews/{reviewId}` |
| UPDATE  | PATCH       | `/api/v1/books/{bookId}/reviews/{reviewId}` |
| DESTROY | DELETE      | `/api/v1/books/{bookId}/reviews/{reviewId}` |


```java
@RequestMapping("api/v1")
@RestController
public class BookReviewController {
  @GetMapping("books/{bookId}/reviews/{reviewId}")
  public Review getReviewForBook(@PathVariable("bookId") Integer id,
                                 @PathVariable("reviewId") Integer rid) { ... }
```

### `@RequestParam`

You can still use `@RequestParam` in a REST API, which retrieves named parameters from the request URL.
```
http://localhost:8080/api/v1/books?sortBy=author
```
We use `@PathVariable` to specify options and behaviors for our request.

* Don't use them to identify resources.


<hr>

[Prev](restController.md) -- [Up](README.md) -- [Next](labs.md)

