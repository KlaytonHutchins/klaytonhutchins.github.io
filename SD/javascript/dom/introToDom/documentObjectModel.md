### Document Object Model
When a web page is loaded, the browser creates a _Document Object Model_ (DOM) of the page.

The DOM is a programming interface for HTML. It exposes and grants Read/Write access to:
  * HTML elements (represented as objects)
  * the properties of the HTML elements
  * the methods to access HTML elements
  * the events for all HTML elements

Access to this allows us to dynamically manipulate our HTML via scripts we include in our HTML page.

The DOM is accessible by JavaScript through the top level global object `Window`. The `Window` object has several nested properties, which allow us to access browser functionality programmatically.

## The `Document` object
One of the `Window` object's properties is `Document`.

The `Document` interface inherits from the `HTMLDocument` interface, which provides an expansive list of properties and methods to interact with the HTML elements. The `Document` allows us to:
  * select HTML elements
  * change properties on HTML elements
  * create new HTML elements
  * set up event listeners

> ### ![Logo](http://skilldistillery.com/downloads/sd_logo.jpg) Skill++
> * In a chrome console, type in `window.document` and see what is returned.

The Document Object Model (DOM), is a tree of objects (see below for an example) that the browser creates.

![DOM](images/dom_heirarchy.jpg)

<hr>

[Prev](README.md) | [Up](README.md) | [Next](htmlReview.md)

