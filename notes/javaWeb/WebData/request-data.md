---
layout: default
title: Request Data
---

## Request Data

We can send data in an HTTP request as key-value pairs.

The method we use for the request determines how the data is sent.

### `GET` Request Data
A `GET` request sends data as part of the URI.

```
GET /JavaWebIntro/hello?nm=Marvin HTTP/1.0
```

A `?` separates the URI from the _query parameters_.
  * URI: `/JavaWebIntro/hello`
  * Query parameters: `nm=Marvin`

`&`'s separate the parameters.

```
GET /JavaWebIntro/hello?fName=Marvin&lName=Gardens HTTP/1.0
```

This forms the _CGI Query String_: `fName=Marvin&lName=Gardens`

> #### CGI
> Common Gateway Interface - a specification for what information is communicated between a Web server and clients' Web browsers, and how the information is transmitted.

#### URL Encoding
A URL is a text string that cannot contain spaces, and since `/`, `?`, `&`, `=`, and other characters have special meanings in URIs, the entire query string must be _URL encoded_.

> #### URL Encoding
> Translating special or unprintable characters within URLs to strings that are unambiguous and universally accepted by web browsers and servers.

* Each space character can be encoded as a `+`:

  This URL represents a resource named `/My Cool Page.html`

  ```
  http://example.com/My+Cool+Page.html
  ```


* Other reserved characters like `?`, `&`, `/`, `%`, etc. are encoded with *percent encoding*: the character is replaced by its hexadecimal character code, preceded by a percent sign:

  This URL represents a resource named `/What Is HTML/CSS/JavaScript?.html`.

  ```
  http://example.com/What+Is+HTML%2FCSS%2FJavaScript%3F.html
  ```

Note that a space can be represented either as a `+`, or as `%20`. A newline is `%0A`. A percent sign is `%25`.

### `POST` Request Data
`POST` data is sent as the request entity body rather than in the request URI used by `GET`.
* A user will not see the data in a query string.

We often use HTML forms to send `POST` data.

* For a basic form, the form content is a fully URL-encoded query string just like the equivalent `GET` query string.
  * However, the data is sent in the **entity body** rather than the query string.

  ```
  Content-type: application/x-www-form-urlencoded
  ```
* For complex or binary form content such as a form containing a file upload element, the content is broken into multiple parts.

  ```
  Content-type: multipart/form-data; boundary=---ArbitraryStringToUseBetweenChunksOfDataXYZABCRubberDucky
  ```

* Using `POST` instead of `GET` does not provide confidentiality.
  * Form parameter names and options are visible simply by using "view source" in the browser.
  * POSTed form content is easily seen using packet-sniffing software.

> ### Drill
> `WebData`
>
> * Run the project on Eclipse's Tomcat server.
> * Open a Chrome browser and enter the URL `http://localhost:8080/WebData/`.
>   * Open the _Developer Toolbar_ and select the _Network_ tab.
> * Submit the form, and examine your request headers and body.
>   * Choose _view source_ to see the raw form data.

<hr>

[Prev](request-headers.md) -- [Up](README.md) -- [Next](forms.md)

