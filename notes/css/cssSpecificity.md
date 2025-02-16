---
layout: default
title: CSS Targeting - Specificity
---

### Specificity

In the cascade, more specific selectors have higher precedence than less-specific.
The basic selectors below appear in order of specificity (least-specific to most-specific):

* Element
* Class
* ID

> ### Skill Drill
>
> * Copy the following files into `index.html` and `myStyles.html` (_from previous SkillDrill_).
> * Look at each tag inside the `<body>`.
> * Figure out what color it will be displayed in (based on the inline CSS in the `<head>`).
> * Uncomment each body tag (one-by-one) to see if the output matches what you expected.
>
> ```html
> <html>
>
>    <head>
>       <title> My Page </title>
>       <link rel="stylesheet" type="text/css" href="myStyles.css" />
>    </head>
>
>    <body>
>       <!-- To Do: For each tag below (one by one):
>                      - Figure out what color it will displayed in
>                      - Uncomment the tag
>                      - Refresh the browser to see if you were right
>       -->
>       <!-- <p> Hello World 1 </p> -->
>       <!-- <p class="blue"> Hello World 2 </p> -->
>       <!-- <p class="green"> Hello World 3 </p> -->
>       <!-- <p class="red green blue"> Hello World 4 </p> -->
>       <!-- <p id="blue" class="green"> Hello World 5 </p> -->
>       <!-- <p id="green" class="blue"> Hello World 6 </p> -->
>       <!-- <p id="red" class="red"> Hello World 7 </p> -->
>
>       <!-- <h1 id="p"> Hello World 8 </h1> -->
>       <!-- <h1 class="p"> Hello World 9 </h1> -->
>       <!-- <h1 id="orange" class="yellow"> Hello World 10 </h1> -->
>       <!-- <h1 id="yellow" class="blue"> Hello World 11 </h1> -->
>
>       <!-- <h2 id="gray" class="blue"> Hello World 12 </h2> -->
>    </body>
>
> </html>
> ```
>
> ```css
> p {
>    color: red;
> }
>
> #green {
>    color: green;
> }
>
> blue {
>    color: blue;
> }
>
> #gray {
>    color: gray;
> }
>
> h2 {
>    color: purple !important;
> }
> ```

### Combining Selectors

#### Element.Class

You can specify particular elements with a particular `class` value:

```html
<html>

   <head>
      <title> My Page </title>
      <link rel="stylesheet" type="text/css" href="myStyles.css" />
   </head>

   <body>
      <h1 class="productTitle"> First Header </h1>
      <h2 class="productTitle"> Second Header </h2>
      <h2 class="productSummary"> Third Header </h2>
   </body>

</html>
```

```css
h2.productTitle {
   color: blue;
}
```

The `h2.productTitle` **selector** targets ALL `<h2>` elements that have `class="productTitle"`.
Only the second HTML element will be targeted.
It is the only HTML element that is both an `h2` element and that has a `class` of `productTitle`.

> ### ![Logo](http://skilldistillery.com/downloads/sd_logo.jpg) Skill Drill
>
> Create an HTML file from the above.
> Does the output match your expectations?

#### Ancestor / Descendant (Indirect)

Space-separated elements require the selected element to have particular ancestor elements in the document hierarchy.

```html
<html>

   <head>
      <title> My Page </title>
      <link rel="stylesheet" type="text/css" href="myStyles.css" />
   </head>

   <body>
      <div>
         <p> Lorem Ipsum . . . </p>
         <span>
            <ul>
               <li> Green </li>
            </ul>
            <ol>
               <li> Not Green </li>
            </ol>
         </span>
      </div>
      <ul>
         <li> Not Green </li>
      </ul>
   </body>

</html>
```

```css
div ul li {
   color: green;
}
```

This rule selects any list item (`li`) that is inside a `ul` which itself is inside a `div`:

**Note**: The `ul` does NOT have to be a direct child of the `div`, and the `li` does NOT have to be a direct child of the `ul`.
In the following HTML snippet, only the `li` on line 5 would match the **selector** above and be set to green.
The other `li` elements are not inside of a `ul` which itself is inside of a `div`.

> ### ![Logo](http://skilldistillery.com/downloads/sd_logo.jpg) Skill Drill
>
> Create an HTML file from the above.
> Does the output match your expectations?

#### Direct Ancestor / Descendant

Elements separated by `>` require the selected element to have direct ancestor elements in the document hierarchy.

This rule selects any list item (`li`) that is directly inside a `ul` which itself is directly inside a `div`:

```html
<html>

   <head>
      <title> My Page </title>
      <link rel="stylesheet" type="text/css" href="myStyles.css" />
   </head>

   <body>
      <div>
         <p> Lorem Ipsum . . . </p>
         <ul>
            <li> Green </li>
         </ul>
         <span>  
            <ul>
               <li> Not Green </li>
            </ul>
         </span>
      </div>
      <ul>
         <li> Not Green </li>
      </ul>
   </body>

</html>
```

```css
div > ul > li {
   color: green;
}
```

**Note**: The `ul` must be a direct child of the `div`, and the `li` must be a direct child of the `ul`.
In the following HTML snippet, only the `li` on line 4 would match the **selector** above and be set to green.
The other `li` elements are not directly inside of a `ul` which itself is directly inside of a `div`.

> ### ![Logo](http://skilldistillery.com/downloads/sd_logo.jpg) Skill Drill
>
> Create an HTML file from the above.
> Does the output match your expectations?

#### Multiple Selectors

You can apply a single style rule to a comma-separated list of selectors:

```css
div ul li, h2.productTitle, .myCustomClass {
  background-color: lightgray;
}
```

The selector above will match all `li`s inside of `ul`s inside of `div`s **AND** all `h2`s with a class of `productTitle` **AND** all elements with a class of `myCustomClass`.

### Specificity With Combined Selectors

In addition, combining selectors increases specificity.

```css
div.someClass p {   /* All paragraphs nested inside a div with the class someClass */

}
```

is more specific than

```css
div p {   /* All paragraphs nested inside a div */

}
```

which is more specific than

```css
p {   /* All paragraphs */

}
```

> ### ![Logo](http://skilldistillery.com/downloads/sd_logo.jpg) Skill++
> IDs will become very important to target elements when we get into JavaScript.

<hr>

[Prev](cssHello.md) | [Up](README.md) | [Next](cssCascade.md)

