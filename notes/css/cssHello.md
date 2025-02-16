---
layout: default
title: Lab - CSS Hello World
---

1. Open a terminal, navigate to _~/SD/HTML/_, create an HTML file and a CSS file, and edit these two files with `atom`.

   ```bash
   cd ~/SD/HTML/
   touch index.html
   touch myStyles.css
   atom .
   ```

1. Once in Atom, open `index.html`.
At the very top of this file, type `html` and press `return`.
This should create a basic, well-formed, HTML document for you.

1. Inside of the `<head>` of your HTML document add the following:

   ```html
   <title> Hello World </title>
   <link rel="stylesheet" type="text/css" href="myStyles.css">
   ```

1. Inside of the body of your document:
   * Create two `<p>` elements (with brief text of your choice).
   * Create two unordered lists (each with a few `<li>`s of your choice).
   * Create two `<h1>` elements (with brief text of your choice).
   * Assign the class `font40` to the first `<p>` tag and to the first `<h1>` tag.
   * Assign the id `header2` to the second `<h1>` tag.
   * Assign the ids `list1` and `list2` to the two `<ul>` tags.

1. Open up a new Browser Tab and navigate to `~/SD/HTML/index.html` (_Command-O_).

1. In your CSS document:
   * Target all of the `<h1>` tags and give them the property `color: red`.
   * Target the `font40` class and give them the property `font-size: 40px;`.
   * Target the `header2` id and give it the property `color: #29c2d4;`.
   * Target the `list1` id and give it the property `font-weight: bold;`.
   * Target the `list2` id and give it the property `font-family: cursive;`.

1. Refresh your Browser Tab.

1. When finished, leave atom open with these two files.
We will be editing them throughout this section.

<hr>

[Prev](cssSelectors.md) | [Up](README.md) | [Next](cssSpecificity.md)

