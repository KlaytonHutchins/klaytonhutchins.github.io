---
layout: default
title: What is REST
---

## What is REST

A RESTful web service allows a client to retrieve and manage _resources_ stored on a server.

REST is widely implemented using HTTP.

* GET/POST/PUT/PATCH/DELETE are the common HTTP methods used with REST.

REST clients communicate via URLs.

REST defines a number of guidelines that help structure these URLs into a standardized format.

### Verbs

Just like with English, verbs play an important role in describing what action is going to take place. 'GET coffee' and 'MAKE coffee' yield two completely different actions.

These verbs (GET/POST/PUT/PATCH/DELETE) are paired with a noun-based URL to provide a semantic, human readable URI that properly describes the resources you are accessing.

### REST Fundamentals

#### Client-Server

Clients are not concerned with data storage (this remains internal to each server).

Servers are not concerned with the user interface.

Both the server and the client may be completely replaced independently and the other would work in isolation.

#### Stateless

Each request from client to server must contain all of the information necessary to understand the request and cannot take advantage of any stored context on the server.

* Session state is kept ENTIRELY on the client.

Improves visibility, reliability, and scalability

#### Uniform interface

Information is transformed in a standardized form instead of one that specifically fits the application's needs (there is an implicit tradeoff here).

Implementations are decoupled from the services they provide.

### What Is an API?

API is short for _Application Program Interface_.

RESTful APIs provide endpoints, URIs, that give a programmer or application access to data.

The programmer can send requests to, or _consume_, a resource via the specified URI and request verb, and display this data to the user in their own application.

![API Diagram](./images/API_diagram.png)

Once an API is configured, the service can be used by any application via the specifications set forth by the API provider.

### REST vs MVC

A RESTful web service **WILL**:

* Use a standardized 'noun' based URI naming schema for its `@RequestMapping`

* Follow the semantic HTTP Protocol for our RESTful services, utilizing the extended vocabulary of GET/PUT/POST/DELETE

* Respond to requests with a resource, typically data in JSON format

A RESTful service will **NEVER**:

* Respond with a view not associated with the manipulation of a resource (i.e. something other than a create or edit form)

It is possible to have BOTH REST and MVC controllers in one Spring project.

* The REST controller will provide data, which can be consumed by a view presented by an MVC controller.

* **NOTE**: These controllers should be completely separate, and your REST controller should not customize the presentation of data in anyway (this makes it as reusable and maintainable as possible).

<hr>

[Prev](review.md) -- [Up](README.md) -- [Next](restEndpoints.md)

