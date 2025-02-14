## Revealing Modules

JavaScript *Closures* can provide simulated encapsulation.

> "...these functions 'remember' the environment in which they were created" - Mozilla Developer Network

As you know, JavaScript does not have equivalent access modifiers (public, private, etc) to Java.

In order to encapsulate data and control access to an object's properties through methods, we have to use a *Closure* and only expose methods we deem necessary.

There is a common JavaScript design pattern known as the _Revealing Module Pattern_ which can be utilized for this task.

### Creating a *Closure*

A *Closure* is the *state* of scope created by a function when it is invoked.

At runtime, the values within the scope of a function are preserved (saved in memory) and can be referenced by a returned object. This is not limited to the properties of the object itself, but also local variables within the scope of the function.

* Example:

```js
var Person = function(name) {
  var obj = {};

  obj.getName = function() {
    return name;
  }

  return obj;
};

var grace = Person('Grace Hopper');
grace.getName(); // 'Grace Hopper'
grace.name; // undefined
```

In this way you can accomplish two things:

  1. The modularization of code into logical components with a separation of concerns (not dissimilar to Java classes).

  2. Encapsulate data and create something akin to a `private` access modifier.

The only accessible methods/variables from a module are those that you expose in the returned object.

Essentially, we have created a `Person` constructor.

This is useful in that the `Person` module becomes reusable.

We can even add gets/sets, and a display method that will make the object behave similarly to Java.

```js
let Person = function(id, name) {
  var id = id;
  var name = name;

  var obj = {};

  obj.getName = function() {
    return name;
  }

  obj.setName = function(n) {
    name = n;
  }

  obj.display = function() {
    return "id: " + id + ", name: " + name;
  };

  return obj;
}

let p = Person(1, "Jeff");
p.name; // => undefined
p.getName(); // => "Jeff"
```

### Using IIFEs to Create Closures

You do not always need to create reusable objects. Sometimes you simply need to create a closure to decrease the number of variables in the global scope. (Remember, anything outside of a function is in the global scope).

To create a modularized closure you can use an *Immediately Invoked Function Expression (IIFE)*.

```js
let applicationRunner = (function(){
  // code
})()
```

  * the parentheses surrounding the function (`(function(){})`) force the JS interpreter to evaluate the function immediately

  * the parentheses following the function (`(function(){})()`) invoke it (just like you would if you were calling it by name)

  * You can pass arguments to the function in the same way as you would another function:

```js
let bandBuilder = (function(bandMembers){
  // code
})(['David Bowie', 'Slash', 'Missy Elliott']);
```

This will allow you to create modules with private worker methods, exposing a simple API publicly:

```js
let applicationRunner = (function(){
  var module = {};

  var displayMenu = function() {
    console.log("1: List Fleet");
    console.log("2: Show Fastest Jet");
    console.log("3: Display Farthest Flying Jet");
  };

  var configureInput = function(email, password) {
    console.log("configuring connection...");
    console.log("herding llamas...");
    console.log("submitting credentials email:*****, password:*****");
  };

  var adminPassword = '123CAT';

  var adminEmail = 'admin@admin.com';

  module.run = function() {
    configureInput(adminEmail, adminPassword);
    displayMenu();
  };

  return module;
})()

// run the application
applicationRunner.run();

applicationRunner.adminPassword // undefined
```

> ### ![Logo](http://skilldistillery.com/downloads/sd_logo.jpg) Skill Drill
> 1. Create a `movieFactory` function expression which takes three parameters, `title`, `year`, `runtime`.  
>
> 1. Create setters, getters, and a display function.  
>
> 1. Expose the setters, getters, and the display function in the returned object.  
>
> 1. Create 4 movies using the factory. Call display on each of them.  
>
> 1. Use the setters on one of the objects to change the `title`, `year`, and `runtime`. Call the display function again.  

<hr>

[Prev](this.md) | [Up](README.md) | [Next](mage-labs.md)

