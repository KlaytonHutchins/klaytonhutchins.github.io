---
layout: default
title: Sending POST and Other Request Methods
---

You can user XHR to send any of the HTTP request methods.

```javascript
let xhr = new XMLHttpRequest();
xhr.open('POST', 'api/users', true);
```

Recall that POST and PUT requests include a request body, and return a response body.

When you use `XMLHttpRequest`, you pass your request body to the `send` method.

* _It is critical that you specify the type of request body you are sending_, by setting the `Content-type` HTTP header.

  ```javascript
  xhr.setRequestHeader("Content-type", "application/json"); // Specify JSON request body
  ```

* Use `JSON.stringify` to convert a JavaScript object to a JSON string.

```javascript
let xhr = new XMLHttpRequest();
xhr.open('POST', 'api/users', true);

xhr.setRequestHeader("Content-type", "application/json"); // Specify JSON request body

xhr.onreadystatechange = function() {
  if (xhr.readyState === 4 ) {
    if ( xhr.status == 200 || xhr.status == 201 ) { // Ok or Created
      let data = JSON.parse(xhr.responseText);
      console.log(data);
    }
    else {
      console.error("POST request failed.");
      console.error(xhr.status + ': ' + xhr.responseText);
    }
  }
};

// JavaScript data (object)
let userObject = {
  name: 'J. R. "Bob" Dobbs',
  username: 'bdobbs',
  email: 'bdobbs@example.com'
};

let userObjectJson = JSON.stringify(userObject); // Convert JS object to JSON string

// Pass JSON as request body
xhr.send(userObjectJson);
```


<hr>

[Prev](responseText.md) -- [Up](README.md) -- [Next](labs.md)

