## Request and Response

Recall that clients send requests to servers, and the data is translated using protocols.

![Client and server](images/http.png)

The HTTP protocol specifies how a browser and other web clients request resources from web servers.


### Request
A request for a resource consists of `REQUEST RESOURCE_URI PROTOCOL_VERSION`.

```
GET /content/somepage.html HTTP/1.0
```

* The client can optionally send request headers.

  ```
  GET /content/somepage.html HTTP/1.1
  Host: www.example.com
  Connection: Keep-Alive
  ```
  * A blank line after the last header indicates the end of the request.
  * The `RESOURCE_URI` string must not contain spaces - that is, exactly two spaces are allowed in the request.

### Response

A response to a client begins `PROTOCOL_VERSION RESPONSE_CODE REASON`

  ```
  HTTP/1.1 200 OK
  ```
  * Optional headers can (and just about always do) follow the response line.

    ```
    HTTP/1.1 301 Moved permanently
    Content-Length: 322

    <html><head><title>301 Moved permanently</title></head>
    <body><p>The document has moved <a href="http://example.com/
    pages/somepage.html">here</a>.</p><hr> .....
    ```
  * An extra blank line separates the request or response and its headers from any content to follow.

<hr>

[Prev](README.md) | [Up](README.md) | [Next](request-headers.md)

