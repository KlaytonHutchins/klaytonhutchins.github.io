---
layout: default
title: `GET` vs. `POST`
---

## `GET` vs. `POST`

So far, the only difference between `GET` and `POST` has been how the data is sent:

* `GET` - in the query string.
* `POST` - in the request body.

A major difference is the _intention_ or each request method.


### `GET`
A `GET` request should have no new side effects no matter how many times the request is repeated.
* A `GET` request should do no more than retrieve data.

`GET` requests are said to be `idempotent`.

> #### idempotent
> Clients making the same call repeatedly will produce the same result.


### `POST`
`POST` is intended for providing information to a server that might be used by the server-side code to modify content on the site.

* Browsers are required to warn the user before posting a form for a second time (e.g. on a page refresh) because the POSTed data is not guaranteed to be idempotent.

> ### Practice Exercise
> It's perfectly fine for a `POST` to actually be idempotent (having no new side-effects), and `POST` can have advantages over `GET`.
> * For a large, complex form, the length of the URI query string can be awkward and even run into length limits of various browsers and web servers.
> * Sensitive query parameters should be sent only by `POST`.

<br >

> ### Practice Exercise
> We say _should_ when discussing `GET` vs. `POST` because you _can_ use them however you want - but you should stick to each method's purpose.

<hr>

[Prev](forms.md) -- [Up](README.md) -- [Next](status-codes.md)

