## Data Serialization

### Dependencies
Spring Boot's `Web` dependency pack includes the Jackson Library jar files.

These classes handle the translation of Java objects to JSON and vice versa.

```groovy
compile group: 'com.fasterxml.jackson.core', name: 'jackson-core', version: '2.9.6'
compile group: 'com.fasterxml.jackson.core', name: 'jackson-databind', version: '2.9.6'
```

### JSON

What makes Web Services so effective is the transfer of data from the server to the client.

In the paradigm of Client(Browser) / Server you will typically transfer your data in the form of JSON (Javascript Object Notation).

JSON is directly convertible to a JavaScript object, and because of this, it lends itself to use on the client side.

Spring MVC combined with the Jackson (`com.fasterxml.jackson.core`) libraries allow us to directly convert a POJO (Plain Old Java Object) to a JSON representation for use on the client side.

* We can also go back to a POJO from JSON by using the `ObjectMapper` class provided by the Jackson Library.

### What is JSON?

JSON is short for 'JavaScript Object Notation'.

JSON is a String representation of data that can be transferred via HTTP.

* Its structure mimics Javascript objects and can be used on the client.

Objects created in Java can be converted to JSON using the Jackson jars and sent to the client in the *response* body.

For example say we have a class `User` like the one seen below.
```java
public class User{
  private String fname;
  private String lname;
  private int age;

  public getFname(){
    return this.fname;
  }
  public setFname(String fname){
    this.fname= fname;
  }

  // ...other gets/sets
}
```

* If we were to instantiate an instance of this class in Java:

```java
User u = new User("Donte", "Justice", 34);
```

* Our user could then be represented in JSON as follows:

```json
{
  "fname": "Donte",
  "lname": "Justice",
  "age": 34
}
```

Web pages often use `XMLHTTPRequest`/`AJAX` to asynchronously request resources from the server, which returns a response with the JSON representation of the data.

Once we learn JavaScript and `XMLHTTPRequest`/`AJAX`, our web apps will no longer use `ModelAndViews` to display `JSP` pages or to access data.

Instead, they will consume RESTful API's.

<hr>

[Prev](README.md) | [Up](README.md) | [Next](javaAndJson.md)

