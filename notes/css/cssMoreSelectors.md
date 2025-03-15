---
layout: default
title: CSS Targeting - More Selectors
---

### Parent/Child and Sibling Selectors

* Parent/child: A greater-than sign, `>`, requires the right-hand element to be the direct child of the left-hand selector (i.e. nested inside the parent).

`parent > child`.

This rule selects an `h3` element that is nested directly under a `div` element:

```css
div > h3 {
   text-decoration: underline;
}
```

* Adjacent Sibling: A plus sign between two selectors selects the right-hand element only if it's adjacent to (next to) the left-hand one. The elements are not nested.

`left + selected`

This rule selects any paragraph immediately following an `h1`:

```css
h1 + p {
   font-family: cursive;
}
```

### Attribute Selectors

Square brackets target an element attribute.

In the examples below, `alt` is a common `img` attribute.

* [*attrName*] select if the attribute is present.

```css
[alt] {
   border: 1px solid orange;
}
```

* [*attrName*=*value*] select if the attribute is present _and_ has the given value.

```css
[alt="Java Duke"] {
   border: 1px solid orange;
}
```

* [*attrName*~=*value*] select if the attribute is present and contains the word *value*.

```css
[alt~=Duke] {
   border: 1px solid orange;
}
```

There are many variations of the attribute selector. See: https://developer.mozilla.org/en-US/docs/Web/CSS/Attribute_selectors

#### Pseudo-classes

A single colon, `:`, indicates a *pseudo-class* specifying a particular *state* of an element.

* `:hover` - apply the style rule only when the input pointer is over the element.

```css
ul.myMenu > li:hover {
   color: navy;
   background-color: yellow;
}
```

* `:active` - apply the style rule only when the element is being clicked.
* `:first-child` - apply the style rule only if the element is the first child of its parent.
* `:last-child` - apply the style rule only if the element is the last child of its parent.
* `:nth-child()` - apply the style rule only if the element is the indicated child of its parent.

For example, `li:nth_child(3)` targets the third item of a list.

https://developer.mozilla.org/en-US/docs/Web/CSS/Pseudo-classes

#### Pseudo-elements

A double colon, `::`, indicates a *pseudo-element* targeting a specific part of an element.

* `::first-letter` - apply to the first letter of the element.

```css
article p::first-letter {
   font-size: x-large;
}
```

* `::first-line` - apply to the first line of the element.
* `::after` - create and target a new, empty element as the last child of the targeted parent.

```css
ol > ul > li:first-child::after {
   content: "";
   background-image: url(JavaDuke.png);
   opacity: .3;
}
```

<hr>

[Prev](cssCascade.md) -- [Up](README.md) -- [Next](cssBoxModel.md)

