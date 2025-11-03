## HTTP and MVC

Before we move into REST, we need to review a few topics.

### HTTP

Example GET request:

*(Client connects to web server via socket connection on port 80)*
```
GET /index.html HTTP/1.0                                                             Request line
Connection: Keep-Alive                                                             General header
User-Agent: Mozilla/5.0 (Windows NT 6.1; WOW64; rv:11.0)                           Request header
Accept: image/gif, image/x-xbitmap, image/jpeg, */*                                Request header
                                                Carriage-return terminates client request headers
HTTP/1.1 200 OK                                                                     Response line
Connection: Close                                                                  General header
Date: Mon, 04 Aug 2014 20:28:06 GMT                                                General header
Server: Apache/2.2.29 (CentOS)                                                    Response header
Content-Type: text/html                                                             Entity header
Content-Length: 249                                                                 Entity header
                                               Carriage-return terminates server response headers
<HTML>                                                                  Response body from server
<HEAD><TITLE>Welcome to my Web Site</TITLE></HEAD>                      Response body from server
<BODY>This is a sample page...                                          Response body from server
```

#### Request

HTTP requests are comprised of four pieces:  
1: Request line  
2: Request headers  
3: A blank line  
4: An optional request body  

##### The request line
The Request Line takes the following format `Method Request-URI HTTP-Version`
* The method is a our standard HTTP Request Methods (GET/POST/PUT/DELETE)  
* The request URI is the location where you are requesting resources from.  
* The http-version is which version of HTTP you are using to execute the request. (HTTP/1.1)

##### Request headers
Request headers allow the sender to pass additional information about the nature of the request.

This piece can also contain information about the user sending the request to see if they have the appropriate permissions to access specific info.

A blank line indicates the end of the request headers.

##### Body
HTTP requests can include an optional request body.

This body is used to send the actual data being transferred with a request.

* For example, when an HTML form is submitted with POST, the body will consist of the URL-encoded form field values.

GET and DELETE requests do not send a request body.

#### Response
HTTP responses are similar in their structure:  
1: A status line  
2: Response headers  
3: A blank line  
4: Response body  

##### The status line  
The status line includes information about the HTTP-Version and a status code.  

##### Response headers  
Response headers allow the server to pass additional information about the response - any information that does not belong in the body or headers.

##### Response body  
The response body contains the requested information.

Example POST request:

*(Client connects to web server via socket connection on port 80)*
```
POST /cgi-bin/guestbook HTTP/1.0                                                     Request line
Connection: Keep-Alive                                                             General header
User-Agent: Mozilla/5.0 (Windows NT 6.1; WOW64; rv:11.0)                           Request header
Accept: image/gif, image/x-xbitmap, image/jpeg, */*                                Request header
Content-Type: text/plain                                                            Entity header
Content-Length: 37                                                                  Entity header
                                                Carriage-return terminates client request headers
Hello, I’m Bob Dobbs! Nice web site!                                     Request body from client
                                                                         Request body from client
HTTP/1.1 200 OK                                                                     Response line
Connection: Close                                                                  General header
Date: Mon, 04 Aug 2014 20:28:06 GMT                                                General header
Server: Apache/2.2.29 (CentOS)                                                    Response header
Content-Type: text/html                                                             Entity header
Content-Length: 100                                                                 Entity header
                                               Carriage-return terminates server response headers
<HTML>                                                                  Response body from server
<HEAD><TITLE>Thanks!</TITLE></HEAD>                                     Response body from server
<BODY>You’ve been added to my guest book.</BODY>                        Response body from server
</HTML>                                                                 Response body from server
```

### Remember Spring MVC?

Let's go over a brief overview of what Spring-MVC is:

* Spring-MVC is a web application framework that leverages the Model-View-Controller pattern to make dynamically generated web pages.

* Spring-MVC uses `@Controller` and `@RequestMapping` to take an HTTP request and map it to a **controller** method which returns a **view** (either by view name, or with a `ModelAndView` object.

* A Spring-MVC `@RequestMapping` returns a view, which is usually a HTML or JSP (Java Server Page) file.

  * Spring-MVC passes data via the model (e.g. a Java object) to the view, which then uses it to add custom data to a web page, and returns it in a response to the client.

* The JSP views returned from a Spring-MVC view use a template language called *Expression Language* to access data inside of the JSP.

  * In addition to Expression Language, JSPs use a tag library called **JSTL** or *JSP Standard Tag Library* to format the template page.

<hr>

[Prev](README.md) | [Up](README.md) | [Next](introToREST.md)

