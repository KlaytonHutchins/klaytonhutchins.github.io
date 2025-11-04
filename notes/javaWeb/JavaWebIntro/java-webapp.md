---
layout: default
title: Java Web Application
---


Java Web Applications consist of several types of files.

![Java web app files](images/javaWebapp.png)


### Java Servlets
A Java servlet is a Java class which handles a request and returns a response (usually HTML).
* The servlet uses objects built by the Web Container to receive the request and return the response.

### Java Classes
A Java servlet is specialized: it has methods for handling requests and returning responses.

Applications can still have other Java classes that the servlet can call for things like data access and calculation.

### JSP Pages
A JSP page is a file containing HTML and special tags for executing Java code.
* Most JSP pages look just like HTML pages, with additional tags.

### HTML and CSS Files
A Java Web Application can contain static HTML and CSS files.
* These are not dynamic; a file's contents are returned without any Java involved.

### Images
Image resources can be returned as-is, just like HTML files.

<hr>

[Prev](webapps.md) -- [Up](README.md) -- [Next](servlet.md)

