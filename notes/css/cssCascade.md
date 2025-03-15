---
layout: default
title: The Cascade
---

Style rules come from several places.

* Each browser (*user agent*) has its own prebuilt stylesheet that defines default styles for all elements.
* As the page author you can link multiple stylesheets to your page.
* A user can apply their own stylesheet to your page.
  For example, someone with a visual impairment might style all text for size and contrast.

When multiple stylesheets try to set the same style property, the values [*cascade*][MDNCascade] in order of:

* Importance: a style rule can be marked as `!important` to give it higher priority.
  ```css
  p {
     color: red !important;
  }
  ```

* Specificity: the most specific selector has higher priority than less-specific selectors (more on selectors coming up...)

* Order of appearance: the order in which the browser encountered the rules.
  * Browser (user-agent) stylesheet rules.
  * Author style rules override browser stylesheet rules:
    * Internal and external stylesheets, in the order they appear in the document.
    * Inline styles (which we won't use).
  * User style rules override author style rules (these are not very common).

### Inheritance

In the absence of a specific rule, many CSS properties are inherited from _parent_ elements.

> #### parent
> HTML elements have a parent-child relationship, which is based on nesting of elements. A _child_ is an element nested inside a _parent_.
>
> Here, `<div>` is the parent of `<span>`.
> ```html
> <div>
>    <span> I am a child ... </span>
> </div>
> ```
>
> In this example, the `<span>` will inherit any styling from its `<div>` parent.

[BuildingYourFirstWebPage]: http://learn.shayhowe.com/html-css/building-your-first-web-page/
[MDNCascade]: https://developer.mozilla.org/en-US/docs/Web/CSS/Cascade

<hr>

[Prev](cssSpecificity.md) -- [Up](README.md) -- [Next](cssMoreSelectors.md)

