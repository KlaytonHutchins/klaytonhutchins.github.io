---
layout: default
title: CSS Basics
---

Cascading Style Sheets (CSS) allow us to separate visual presentation of an HTML page from the page content.

Every element of an HTML document has many CSS properties that determine its visual presentation and positioning.  There are hundreds of CSS properties, some generic, some specific to certain types of HTML elements like images or tables.

A CSS rule has the form:

```css
selector {
   property-name: property-value;
}
```

### Applying Styles

To apply a style, you can use:

1. **Inline styles**: any HTML element can have a `style` attribute in its opening tag, containing a list of CSS properties (style rules):

```html
<html>
   <head>
      <title> My Page </title>
   </head>

   <body>
      <p style="font-family: cursive; text-decoration: underline;"> Lorem ipsum dolor sit amet, ... </p>
      <p> Ipsum dolor sit amet consectetur adipiscing. </p>
   </body>
</html>
```

This technique sets the font of this single paragraph (`<p>`) only to cursive and underline.
It does not affect any other elements on the page.

This defeats a primary purpose of CSS, which is to separate all styling from the HTML content.
You should never use inline styles.

2. **Internal stylesheet**: in the `<head>` of your HTML page, you can use the `<style>` tag to enclose a list of style rulesets:

```html
<html>
   <head>
      <title> My Page </title>
      <style type="text/css">
         p {
            font-family: cursive;
            text-decoration: underline;
         }
      </style>
   </head>

   <body>
      <p> Lorem ipsum dolor sit amet, ... </p>
      <p> Ipsum dolor sit amet consectetur adipiscing. </p>
   </body>
</html>
```

This technique sets the font of all paragraphs on the page to cursive and underline.

While this disentangles the style rules from the HTML tags, it still requires editing the HTML page source to change presentation. This can be cumbersome if the HTML is actually generated dynamically by program code.

3. **External stylesheet**: place CSS rulesets in one or more separate stylesheet files (by convention named with the `.css` extension, and use the `<link>` tag to associate them with the HTML:

index.html:
```html
<html>
   <head>
      <title> My Page </title>
      <link rel="stylesheet" type="text/css" href="myStyles.css">
   </head>

   <body>
      <p> Lorem ipsum dolor sit amet, ... </p>
      <p> Ipsum dolor sit amet consectetur adipiscing. </p>
   </body>
</html>
```

myStyles.css:
```css
p {
   font-family: cursive;
   text-decoration: underline;
}
```

This technique sets the font of all paragraphs on the page to cursive and underline.

The HTML file reads in and applies the CSS file.

This is the preferred technique.
It separates the content and styling into two separate files.
This allows HTML files created dynamically by software to read in and apply static, predefined CSS styling file(s).

<hr>

[Prev](README.md) -- [Up](README.md) -- [Next](cssSelectors.md)

