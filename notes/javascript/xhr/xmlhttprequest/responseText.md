---
layout: default
title: Capture Returned Data with `XMLHttpRequest.responseText`
---

The `XMLHttpRequest.responseText` property contains the response to the request as text, or null if the request was unsuccessful or has not yet been sent.

In asynchronous XMLHttpRequests, the response data from the server can be captured with the `XMLHttpRequest.responseText` property in the callback function:


```javascript
  let xhr = new XMLHttpRequest();

  xhr.open('GET', 'api/users', true);

  xhr.onreadystatechange = function() {
    if (xhr.readyState === 4) {
      if (xhr.status === 200) {
        console.log(xhr.responseText);
        /*
        [
          {"id":1,"username":"barbd","name":"Barb Dobbs","email":"barbd@example.com"},
          {"id":2,"username":"freddo","name":"Freddy Frog","email":"fred.frog@example.com"},
          {"id":3,"username":"aaronaa","name":"Aaron Aardvark","email":"aarona@example.com"},
        ]
        */
      }
      else if (xhr.status === 404) {
        console.error('api/users not found.');
      }
      else {
        console.error('Unknown error: ' + xhr.status + ': ' + xhr.responseText);
      }
    }
  };

  xhr.send();
```

## Convert `responseText` from JSON to JavaScript Data

The `XMLHttpRequest.responseText` property returns a `DOMString` representation of the returned data. 

In order to use it as JavaScript data and access its properties we will parse the `responseText` .

The global `JSON` object contains methods for parsing JavaScript Object Notation (JSON) and converting values to JavaScript objects, as well as converting JavaScript data to JSON text. 

It can't be called or constructed, and aside from its two methods it has no interesting functionality of its own.

Converting the `DOMString` in the `XMLHttpRequest.responseText` property to JSON requires the JSON object's `JSON.parse()` method.

```javascript
  let xhr = new XMLHttpRequest();

  xhr.open('GET', 'api/users', true);

  xhr.onreadystatechange = function() {
    if (xhr.readyState === 4) {
      if (xhr.status === 200) {
        console.log(xhr.responseText);
        /*
        [
          {"id":1,"username":"barbd","name":"Barb Dobbs","email":"barbd@example.com"},
          {"id":2,"username":"freddo","name":"Freddy Frog","email":"fred.frog@example.com"},
          {"id":3,"username":"aaronaa","name":"Aaron Aardvark","email":"aarona@example.com"},
        ]
        */
        let users = JSON.parse(xhr.responseText);
        // users is now a JavaScript array of user objects
        // which we can iterate over, creating HTML elements and inserting
        // them into the DOM.
      }
      else if (xhr.status === 404) {
        console.error('api/users not found.');
      }
      else {
        console.error('Unknown error: ' + xhr.status + ': ' + xhr.responseText);
      }
    }
  };

  xhr.send();
```

With the JSON parsed, it can be manipulated as standard JS objects.

<hr>

[Prev](status.md) -- [Up](README.md) -- [Next](post.md)

