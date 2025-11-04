---
layout: default
title: Lab
---


APIs respond with JSON representations of data.

Including the Jackson jars, which we discussed earlier, automatically maps returned Java objects to json or primitive types to a string representation.

1. Open the project we configured with ping/pong, `MyFirstRestProject`.

1. Create a package called `com.example.rest.data`.  
   * Create a `User` class.
   * A `User` should have a _name_, _username_, _email_, and _password_.
   * Create all the appropriate getters and setters for these fields.
   * Create a constructor that takes these 4 values, as well as a no-arg.
   * Generate a `toString`.

   * The Jackson Library uses these gets and sets to generate the json, so if they aren't included, your program will fail.

1. In the controller create another method `getUser()`. Assign the URL `/users` path to this method using `@RequestMapping`. Inside of the methods, instantiate a new instance of a `User` and return the created object. (Your instance will use hardcoded data, like the example below.)

   ```Java
   @GetMapping("api/users/1")
   public User getUser(){
     return new User("Julia Cousins", "JCousins", "JC@gmail.com", "wombat1");
   }
   ```

1. Using Postman, hit the URL `http://localhost:8080/api/users/1`. You should get the json representation of the `User` object as a response. If you are getting errors make sure you have properly included all gets and sets in the `User` class.

   ```json
   {
     "name":"Julia Cousins",
     "username" : "JCousins",
     "email":"JC@gmail.com",
     "password":"wombat1"
   }
   ```

1. Add a post method in the controller:

   ```Java
   @PostMapping("api/users")
   public String addUser(@RequestBody String userParam){
     System.out.println(userParam);
     return userParam;
   }
   ```

1. Create a test request in Postman with the method POST, URL `http://localhost:8080/api/users`, and a **Body* with type `raw` and `application/json`.  Enter a JSON request body:

   ```javascript
   {
     "name": "Froderick Fronkensteen",
     "username": "froderick",
     "email": "FF@gmail.com",
     "password": "tapdance"
   }
   ```
   
   Send the request, and observe the response in Postman as well as the console output from Spring.

1. Change the parameter type and the return type from `String` to `User`:

   ```Java
   @PostMapping("api/users")
   public User addUser(@RequestBody User userParam){
     System.out.println(userParam);
     return userParam;
   }
   ```

   Send the request, and observe the response in Postman as well as the console output from Spring.

<hr>

[Prev](recursiveJson.md) -- [Up](README.md)

