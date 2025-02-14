## Traversing the DOM
As we saw previously the `window` object has a property, `document`, that represents the tree-like structure of an html document.

We can _traverse_ this tree by navigating up and down its branches.

Traversing the DOM means to move through the `HTMLElements` in an html page. We can use tools built into JavaScript to select specific HTML elements based on their proximity to other elements.

If you look at a well-formed HTML document you can see the relationships through indentation. Any element in the page can have `parent` nodes, `child` nodes, and `sibling` nodes.

```html
<h1>I Like to</h1>
<ul>
  <li>Hike</li>
  <li>Sleep</li>
  <li>Code</li>
</ul>
```
**Parent**: A parent element is an element that has other html elements inside of it. Each `<li>` element's parent is the `<ul>` element.

**Child**: A child element is an element that exists inside of another html element.
The `<ul>` element has 3 children, the `<li>`s.

**Sibling**: Sibling elements are elements that exist at the same level of the HTML document structure. All the`<li>` elements are siblings. The `<h1>` and `<ul>` elements are siblings as well. Siblings do not need to be of the same type.

<hr>

[Prev](README.md) | [Up](README.md) | [Next](usingSelectedElement.md)

