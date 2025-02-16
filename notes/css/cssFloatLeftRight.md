---
layout: default
title: Floating Elements
---

### `float` Property

The `float` property specifies that an element should be place on the `left` or `right` side of its container.

Floating an element allows subsequent text and inline elements to wrap around it on one side or the other.

  * The element is taken out of the normal flow of the page, and moved to the edge of its container, _or another floated element_.
  * Once an element is floated, all other elements around it will move with respect to the float.
  * This behavior can be negated by using the clear property `clear : both;`.

> ### Skill Drill
>
> 1. Copy and paste the HTML below into an `.html` file.
>    Display the file in a browser.
>    Notice the text above and below the image.
>    Notice the empty space to the right of the image.
>
> 1. Add the `floatLeft` class to the `<img>` tag.
>    Refresh the browser.
>    Notice that the second block of text is now displayed to the right of the image (where the empty space used to be).
>
> 1. Replace the `floatLeft` class with `floatRight` in the `<img>` tag.
>    Refresh the browser.
>    Notice that the image is now on the right of the page.
>    Notice that the second block of text is displayed to the left of the image.
>
> ```html
> <html>
>    <head>
>       <title> Float Left Right </title>
>       <link rel="stylesheet" type="text/css" href="myStyles.css" />
>    </head>
>
>    <body>
>       <p> Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do
>           eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim
>           ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut
>           aliquip ex ea commodo consequat. Duis aute irure dolor in
>           reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla
>           pariatur. Excepteur sint occaecat cupidatat non proident, sunt in
>           culpa qui officia deserunt mollit anim id est laborum. </p>
>
>       <img class="border" src="https://wiki.faforever.com/images/2/21/Java_logo.jpg" />
>
>       <p> Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do
>           eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim
>           ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut
>           aliquip ex ea commodo consequat. Duis aute irure dolor in
>           reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla
>           pariatur. Excepteur sint occaecat cupidatat non proident, sunt in
>           culpa qui officia deserunt mollit anim id est laborum. </p>
>    </body>
> </html>
> ```
>
> ```css
> .border {
>    border-style: solid;
>    border-width: 2px;
> }
>
> .clearFloat {
>    clear: both;
> }
>
> .floatLeft {
>    float: left;
> }
>
> .floatRight {
>    float: right;
> }
> ```

<hr>

[Prev](cssDisplay.md) | [Up](README.md) | [Next](labs.md)

