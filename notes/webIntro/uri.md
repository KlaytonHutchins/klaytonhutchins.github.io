---
layout: default
title: URIs and URLs
---

Resources on the internet are identified by _URIs_.

> #### URI
> Uniform Resource Identifier - a globally unique text string identifying a resource.

The most important kind of internet URI is the _URL_.

> #### URL
> Uniform Resource Locator - a URI which also specifies how to _locate_ and _retrieve_ a resource.
>
> In other words, a URL is a subset of the URI, which specifies where a resource is and the mechanism for retrieving it.

### URL Examples

URLs typically specify an application protocol, followed by a hostname and a path to the resource on that host.

```html
http://www.example.com/content/somepage.html
```

![html url](images/uri.png)


Login and port information can be included.

```html
ftp://user2:mypass@ftp.example.com/pub/somefile.txt
```

![ftp url](images/uri2.png)

```html
rtsp://media.example.com:88/videos/somevideo.avi
```

![rtsp url](images/uri3.png)


> #### port
> An endpoint on a server in a network. Clients connect to ports. Ports are numbered 0 - 65535.

<br />

> ### Skill++
> Another acronym in this conversation is _URN_, "Uniform Resource Name." URN's must be unique, and be unique forever.

<hr>

[Prev](clients-and-servers.md) -- [Up](README.md) -- [Next](http-protocol.md)

