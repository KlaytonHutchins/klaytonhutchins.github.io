---
layout: default
title: CSS Targeting - Selectors
---

### Rulesets

There are many ways to target a style rule to an HTML element. The basic format of a targeted element is:

```css
p {
   color: red;
   font-size: 20px;
}
```

where:
* `p` is the **selector** (targeting all HTML `<p>` elements).
* `color` and `font-size` are **properties**.
* `red` and `20px` are the **values** assigned to the properties.
* `color: red;` and `font-size: 20px;` are **style rules**.
* `p {color: red; font-size: 20px;}` is a **ruleset**.

This page will focus primarily on **selectors**.

See Also: https://www.w3schools.com/css/css_syntax.asp

#### Target An Element

We can apply a ruleset to all tags of a certain type.
If we wanted all `<h1>` elements to have red text we could change the color attribute:

```html
<h1> Text Content </h1>
```

```css
h1 {
   color: red;
}
```

The element or elements we are targeting are listed first.
This element is then followed by a `{ }`, similar to a code block.
Inside of the curly brackets we can change properties to whatever we see fit.

Each attribute we are altering is listed out in the following format `property-name: value;`.
**Each rule must be terminated with a semicolon**.
We can include as many properties as we want to alter for that element.

#### Target A Class

Any HTML element can have a `class` attribute containing a space-separated list of classes the element belongs to.
Class names are arbitrary:

```html
<h1 class="christmasColors header textStuff"> Text Content </h1>
```

This particular `<h1>` element has 3 classes: `christmasColors`, `header`, and `textStuff`.

The same class can be assigned to multiple elements in a document.
This allows you to assign the same stylings to multiple element types.

To select a class for a ruleset, precede a classname with `.`:

```css
.christmasColors {
   background-color: green;
   color: red;
}
```

#### Target An ID

Any HTML element can have an id attribute:

```html
<h1 id="uniqueID"> Text Content </h1>
```

**IDs need to be unique within the HTML file.**
They are used to target specific elements within a page.
If you want to style one specific `<h1>` tag you could use an `id` to do so.

To target a ruleset using an ID, precede the ID name with `#`.

```css
#uniqueID {
   color: green;
   font-family: verdana;
   font-size: 20px;
}
```

<hr>

[Prev](cssBasics.md) -- [Up](README.md) -- [Next](cssHello.md)

