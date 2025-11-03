## REST Endpoints

The combination of a specific resource URI and an HTTP request method defines an _endpoint_ in a RESTful API.

* The URI is sometimes called a _route_; the same route can have multiple endpoints accessed with different HTTP verbs.

The resource name is part of the URI.

| HTTP Verb | URI                  | Request Body | Response Body | Purpose |
|-----------|----------------------|--------------|---------------|---------|
| GET       | `/api/v1/books`      |              | Collection of representations of all _book_ resources | **List** or **collection** endpoint |
| GET       | `/api/v1/books/17`   |              | Representation of _book_ `17` | **Retrieve** endpoint |
| POST      | `/api/v1/books`      | Representation of a new _book_ resource | Description of the result of the operation | **Create** endpoint |
| PUT       | `/api/v1/books/17`   | Representation of a new version of _book_ `17` | | **Replace** endpoint |
| PATCH     | `/api/v1/books/17`   | Description of changes to make to _book_ `17` | | **Update** endpoint |
| DELETE    | `/api/v1/books/17`   |              | | **Delete** route |
| GET       | `/api/v1`            |              | Description of the API and its endpoints | **Index** endpoint |

### Practice Exercise

That last route (**Index**) might retrieve information describing the other endpoints, with embedded links to them.  This _hypertext_ could then be used by client software to navigate the API.  When fully implemented, this approach is referred to as _HATEOAS_ - _Hypertext As The Engine Of Application State_.

You are not required to implement HATEOAS when creating a REST API.


<hr>

[Prev](introToREST.md) -- [Up](README.md) -- [Next](representations.md)

