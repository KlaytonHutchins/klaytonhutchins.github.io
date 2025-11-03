## HATEOAS - Hypertext As The Engine Of Application State

So far, our REST APIs return resource representations directly - JSON strings.

In our client side code, we will hard-code our request URLs based on our pre-existing knowledge of the server's API.

`GET http://localhost:8084/api/todos/1`

* Response body:
  ```json
  {
      "id": 1,
      "task": "Go round Mum's",
      "description": null,
      "completed": true,
      "dueDate": null,
      "completeDate": null,
      "createdAt": "2018-11-28T23:02:32.000+0000",
      "updatedAt": "2018-11-28T23:02:32.000+0000"
  }
  ```

`POST http://localhost:8084/api/todos`

```json
{
  "task": "Head to the Winchester"
}
```

* Response: 
  * Status: **201 Created**
  * Response header: `Location`: `http://localhost:8084/api/todos/12`
  * Response body:
    ```json
    {
      "id": 12,
      "task": "Head to the Winchester",
      "description": null,
      "completed": null,
      "dueDate": null,
      "completeDate": null,
      "createdAt": "2018-12-18T17:28:36.355+0000",
      "updatedAt": "2018-12-18T17:28:36.356+0000"
    } 
    ```

### HATEOAS

Roy Fielding who originated the REST architecture, insists this is not RESTful - that instead, the server should return _hypertext_ that contains not only resource representations, but further descriptions of the API.

Client software would then be able to discover and navigate the rest of the API based on this hypertext.

`GET http://localhost:8084/api`
* Response body:
  ```json
  {
      "_links": {
          "todos": {
              "href": "http://localhost:8084/api/todos{?page,size,sort}",
              "templated": true
          },
          "profile": {
              "href": "http://localhost:8084/api/profile"
          }
      }
  }
  ```

The client code could then look under `"_links"`, and use the `"href"` value from `"todos"`:

`GET http://localhost:8084/api/todos`
* Response body:
  ```javascript
  {
      "_embedded": {
          "todos": [
              {
                  "task": "Go round Mum's",
                  //...
                  "user": {
                      "username": "shaun",
                      //...
                      "_links": {
                          "todos": [
                              {
                                  "href": "http://localhost:8084/todos/1"
                              },
                              //...
                          ]
                      }
                  },
                  "_links": {
                      "self": {
                          "href": "http://localhost:8084/todos/1"
                      },
                      "todo": {
                          "href": "http://localhost:8084/todos/1"
                      }
                  }
              },
              //...
          ]
      },
      "_links": {
          "self": {
              "href": "http://localhost:8084/todos{?page,size,sort}",
              "templated": true
          },
          "profile": {
              "href": "http://localhost:8084/profile/todos"
          },
          "search": {
              "href": "http://localhost:8084/todos/search"
          }
      },
      "page": {
          "size": 20,
          "totalElements": 14,
          "totalPages": 1,
          "number": 0
      }
  }
  ```

The client could then make various link hrefs available to the user, who could choose one to continue accessing the API.

`GET http://localhost:8084/api/todos/1`
* Response:
* Response body:

  ```javascript
  {
      "task": "Go round Mum's",
      //...
      "_links": {
          "self": {
              "href": "http://localhost:8084/api/todos/1"
          },
          "todo": {
              "href": "http://localhost:8084/api/todos/1"
          },
          "user": {
              "href": "http://localhost:8084/api/todos/1/user"
          }
      }
  }
  ```

`POST http://localhost:8084/api/todos`

```javascript
{
  "task": "Head to the Winchester"
}
```
* Response:
  * Status: **201 Created**
  * Response header: `Location`: `http://localhost:8084/api/todos/12`
  * Response body:

    ```javascript
    {
        "task": "Head to the Winchester",
        "description": null,
        //...
        "_links": {
            "self": {
                "href": "http://localhost:8084/api/todos/13"
            },
            "todo": {
                "href": "http://localhost:8084/api/todos/13"
            }
        }
    }
    ```
### Practice Exercise
These examples use _HAL_ - Hypertext Application Language - a draft standard for API description.

Using this hypertext to drive the application, client-side software could start with nothing but the root URL of the server.

* As the API evolves the client-side software doesn't need to be refactored, since it rediscovers the API structure with every access.

This use of Hypertext As The Engine Of Application State is necessary to achieve the idealized "Glory of REST" in the _Richardson Maturity Model_.

[Roy Fielding: REST APIs must be hypertext-driven](http://roy.gbiv.com/untangled/2008/rest-apis-must-be-hypertext-driven)

### Practice Exercise
Note that using HATEOAS completely changes the nature of client-side development.  Instead of simply consuming resources provided by a known API, it becomes much more dynamic and complicated.  Our projects will not use HATEOAS.

<hr>

[Prev](README.md) | [Up](README.md) | [Next](richardsonMaturityModel.md)

