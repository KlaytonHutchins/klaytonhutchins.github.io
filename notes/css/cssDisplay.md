---
layout: default
title: Display Options
---

### `display` Property

* `display: inline;`: Elements such as `<div>` and `<p>` take the entire width by default.
When modified with `display: inline;`, a `<div>` or a `<p>` element will take only the width needed - similar to a `<span>`.
However, `display: inline;` causes any `height` and/or `width` properties to be ignored.

* `display: block;`: Elements such as `<span>` take only the width needed to display their content.
When modified with `display: block;`, a `<span>` element will start on a new line and take the entire available width.

* `display: inline-block;`: This style creates a box for the element but does not take up all available width.
This allows for additional content to flow with surrounding content.
The element itself is formatted as an inline element, but you can apply height and width values.

* `display: none;`: Causes an element to take up no space at all.
It is not visible to the user when the document renders.
This is used in conjunction with JavaScript to hide and unhide content.

**See Also**: https://www.w3schools.com/cssref/pr_class_display.asp

> ### Skill Drill
>
> 1. Copy and paste the HTML below into an `.html` file (and display that file in the browser).
>    Notice that the `<div>`s and `<p>`s take up the entire width of the page.
>    Notice that the `<span>`s take up only the width needed to display their content.
>
> 1. Add the `displayInline` class to one or more of the `<div>`s and/or `<p>`s.
>    Refresh the browser and observe the difference in how these tags are now rendered.
>
> 1. Add the `displayBlock` class to one or more of the `<span>` tags.
>    Refresh the browser and observe the difference in how these tags are now rendered.
>
> 1. Add `height50` and/or `width450` classes to the `<div>`s and `<p>`s that you modified above.
>    Refresh the browser.
>    Were the height and width altered?
>    Why or why not?
>
> 1. Edit one or more of the `<div>` and/or `<p>` elements to now have the `displayInlineBlock` class (and not the `displayInline` class).
>    Refresh the browser.
>    Was the height altered?
>    Why or why not?
>
> ```html
> <html>
>    <head>
>       <title> Display Block, Inline, Inline Block </title>
>       <link rel="stylesheet" type="text/css" href="myStyles.css" />
>    </head>
>
>    <body>
>       <div class="border"> (div 1) Lorem ipsum dolor sit . . . </div>
>
>       <p class="border"> (p) Lorem ipsum dolor sit . . . </p>
>
>       <span class="border"> (span 1) Lorem ipsum dolor sit . . . </span>
>       <span class="border"> (span 2) Lorem ipsum dolor sit . . . </span>
>
>       <div class="border"> (div 2) Lorem ipsum dolor sit . . . </div>
>    </body>
> </html>
> ```
>
> ```css
> .border {
>    border-style: solid;
>    border-width: 1px;
> }
>
> .displayBlock {
>    display: block;
> }
>
> .displayInline {
>    display: inline;
> }
>
> .displayInlineBlock {
>    display: inline-block;
> }
>
> .displayNone {
>    display: none;
> }
>
> .height50 {
>    height: 50px;   /* 'height' not allowed when 'display: inline;' */
> }
>
> .width450 {
>    width: 450px;   /* 'width' not allowed when 'display: inline;' */
> }
> ```

<hr>

[Prev](cssPositionFixed.md) -- [Up](README.md) -- [Next](cssFloatLeftRight.md)

