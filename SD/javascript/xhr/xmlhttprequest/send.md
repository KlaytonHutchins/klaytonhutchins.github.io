## Using `send()`: To Dispatch a XMLHttpRequest

To dispatch an XMLHttpRequest to a server, use the `.send()` method.

The `XMLHttpRequest.send()` method sends the request. 

If the request is asynchronous (which is the default), this method returns as soon as the request is sent. 

* If the request is synchronous, this method doesn't return until the response has arrived. 

* Again, we will never perform synchronous requests.

`send()` accepts an optional argument for the request body, for POST or PUT requests. 

For other request methods such as GET or HEAD, the argument is ignored and request body is set to `null`.

```javascript
let xhr = new XMLHttpRequest();
xhr.open('GET', 'http://someURL.com');

// send the request (defaults to null argument)
xhr.send();
```

<hr>

[Prev](createAndOpenRequest.md) | [Up](README.md) | [Next](get-labs.md)

