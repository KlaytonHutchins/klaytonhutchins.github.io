---
layout: default
title: HTML Attributes
---

A normal HTML element is structured as follows.

```html
<p>This is a P tag</p>
```

HTML elements can also contain _attributes_.

> #### attribute
> Meta-information stored within a tag.

Attributes are defined inside of the opening tag.

```xml
<tag attribute="">... </tag>
```

Attribute names, like tag names, are case-insensitive.

Certain tags have pre set attributes we can use to add functionality to our page.

### `<a href="">`

If we wanted to include a link in a page we would use the `<a>` tag.
This tag has an attribute, `href`, that allows us to link to a certain page.

```html
<a href="http://www.google.com">Google it</a>
```
* The value is enclosed in either single or double quotes.
* **There must be no spaces around the `=` sign**.

When a user clicks on the words `Google it`, the link would cause the page to be directed to Google's home page.


### `<img src="">`
An image tag has a source attribute, `src`, that will load an image from the specified location.
* The location could be a file or URL.

```html
<img src="myPicture.jpg"/>
<img src="https://via.placeholder.com/350x150"/>
```

### Practice Exercise
When we get into JavaScript you will see that we can create our own custom element attributes to store any additional information we think is important.

<hr>

[Prev](htmlHelloWorld.md) -- [Up](README.md) -- [Next](htmlGlossary.md)

