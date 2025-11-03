## REST Semantics

When we implement REST over HTTP, we use the combination of resource URIs, HTTP verbs, response codes, request and response headers, and entity bodies to implement REST semantics.

Most of this we'll implement in our controller endpoint methods.

API: `/api/v1/books`

#### _List/Collection_ Endpoint
* `GET /api/v1/books`
* Response status: **200 Ok**
* Response body: JSON array of _book_ representations.
  * This can be an empty list, `[]`, if there are none.

#### _Retrieve_ Endpoint
* `GET /api/v1/books/17`
* Book exists:
  * Response status: **200 Ok**
  * Response body: JSON representation of _book_ 17.
* Book does not exist:
  * Response status: **404 Not found**
  * Response body: Empty, or human-readable text describing the result.

#### _Create_ Endpoint
* `POST /api/v1/books`
  * Request Body: JSON representation of a new _book_.
* Book created:
  * Response status: **201 Created**
  * Response header: `Location` `http://localhost:8080/api/v1/books/93`
    * The client can use this to retrieve the new resource.
  * Response body:
    * Empty, in which case use **204 No content** instead.
    * JSON representation of the new book.
    * Description of the result of the operation; this is not standardized.
      ```json
      {
        "status": "success",
        "message": "Book created",
        "link": "http://localhost:8080/api/v1/books/93"
      }
      ```
* Book not created:
  * Response status:
    * **400 Bad Request** if request body invalid.
    * **409 Conflict** if update would result in invalid data (resource already exists.)

#### _Replace_ Endpoint
* `PUT /api/v1/books/17`
  * Request Body: JSON representation of the desired new state of _book_ 17.
* Book replaced:
  * Response status: **200 Ok**
  * Response body: 
    * Empty, in which case use **204 No content** instead.
    * JSON representation of the updated book.
* Book not replaced:
  * Response status:
    * **404 Not found** if resource id invalid
    * **400 Bad Request** if request body invalid.

#### _Delete_ Endpoint
* `DELETE /api/v1/books/93`
* Book deleted:
  * Response status: **204 No content**
  * Response body: 
    * Empty.
* Book not deleted:
  * Response status:
    * **404 Not found** if resource id invalid
    * **409 Conflict** if update would result in invalid data - for example, would orphan child resources.

[REST Tutorial - HTTP Methods](https://www.restapitutorial.com/lessons/httpmethods.html)

<hr>

[Prev](httpServlet.md) | [Up](README.md)

