## Create and Open the Request

As its name implies, `XMLHttpRequest` is a JavaScript object, and the first step in using it is to create a new instance of it:

```javascript
let xhr = new XMLHttpRequest();
```

With a new instance created, we can use the `.open(method[String],url[String],async[Boolean])` method to initialize the request.

  * `method`: is a string that corresponds to one HTTP method ('GET', 'POST', 'PUT', or 'DELETE')

  * `url`: is a string of the URL to send the request to.

  * `async`: an optional boolean (defaults to `true`) indicating whether or not to perform the XMLHttpRequest asynchronously.

```javascript
let xhr = new XMLHttpRequest();

// Asynchronous request (defaults to true)
xhr.open('GET', 'http://someUrl.com/resource', true);

// Synchronous request
xhr.open('GET', 'http://someUrl.com/resource', false);
```

> ### ![Logo](http://skilldistillery.com/downloads/sd_logo.jpg) Skill++
> We will never send XHR requests synchronously, which would freeze our browser until the request completes.
> Instead we will usually just omit the third argument to `open`, letting it default to `true` for an asynchronous request.

<hr>

[Prev](xhrObject.md) | [Up](README.md) | [Next](send.md)

