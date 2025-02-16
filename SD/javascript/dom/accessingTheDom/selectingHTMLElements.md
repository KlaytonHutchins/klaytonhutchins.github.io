---
layout: default
title: Selecting HTML Elements
---
The `Document` makes selecting HTML elements relatively easy.

HTML elements in the DOM can be accessed by:
  * Tag name: `document.getElementsByTagName(str)`
  * ID: `document.getElementById(str)`
  * Class name: `document.getElementsByClassName(str)`
  * Name: `document.getElementsByName(str)`
  * CSS Selector: `document.querySelector(str)`, `document.querySelectorAll(str)`

### CSS Selectors
JavaScript introduced `querySelector`, `querySelectorAll` methods to integrate CSS style selectors.

Normally you will target elements by tag, class, and id.
  * Target by tag name: ``('h1')``  
  * Target by class name: ``('.myClass')``  
  * Target by ID: ``('#myID')``  
  * Target by Attribute: ``('div[name]')``  or ``('div[name = "test"]')``  

You are not limited to these simple selectors. Any valid CSS selector can be passed into a `querySelector` method to access an element. An example can be seen below.

``document.querySelectorAll("ul li:first-child")``

### `HTMLElement`
Any of the above selectors return either a collection or a single instance of an `HTMLElement` object. An `HTMLElement` is the programatic representation of a single 'node' from our DOM tree. It stores all the information about one of the HTML tags that was loaded by the browser.

Selecting elements with `getElementsByTagName`, `getElementsByClassName`, and `querySelectorAll`, return collections of `HTMLElement`s, while `getElementById` and `querySelector` return a single `HTMLElement`.

Once we have access to an `HTMLElement` object we can utilize the properties configured by the browser to check information about that node, as well as change those properties to alter the user experience.

### Example
```html  
<html>
  <head>
    <title>Some Page</title>
  </head>
  <body>
        <h1>Hello World</h1>
        <p>para 1</p>
        <p>para 2</p>
        <p>para 3</p>
        <p>para 4</p>
        <p>para 5</p>

        <ul class="list">
            <li>item 1</li>
            <li>item 2</li>
            <li>item 3</li>
            <li>item 4</li>
            <li>item 5</li>
        </ul>

        <div id='mainContent'>
            <div id='subContent'>
                <div id='nestedContent'></div>
            </div>
        </div>

        <script type="text/javascript">
            let paragraphs = document.getElementsByTagName('p');
            let mainContent = document.getElementById('mainContent');
            let list = document.getElementsByClassName('list');
            let firstPara = document.querySelector('p');
            let allItems = document.querySelectorAll('li');

            console.log('paragraphs');
            console.log(paragraphs);

            console.log('mainContent');
            console.log(mainContent);

            console.log('list');
            console.log(list);

            console.log('firstPara');
            console.log(firstPara);

            console.log('allItems');
            console.log(allItems);
        </script>
  </body>
</html>
```
##### Console
```bash
*****paragraphs*****
[p, p, p, p, p]

*****mainContent*****
div#mainContent

*****list*****
[ul.list]

*****firstPara*****
p

*****allItems*****
[li, li, li, li, li]
```

* It is important to note that the items above that look like `Array`s are not actually `Array`s, they are `HTMLCollection`s. These are `Array`-like-objects that can be iterated over, but which do not have access to the the `Array` methods.

> ### ![Logo](http://skilldistillery.com/downloads/sd_logo.jpg) Skill Drill
> 1. Create an HTML document with the following content
>    ```html
>    <body>
>      <h1 class="header" id="title1">Title 1</h1>
>    
>      <ul>
>        <li>item 1</li>
>        <li>item 2</li>
>      </ul>
>    
>      <h2 class="header" id="title2">Title 2</h2>
>      <h3 class="header" id="title3">Title 33</h3>
>    </body>
>    ```
> 1. Select all the Header tags in the page (h1-h6) and store them into a variable.
> 1. Select only the HTML element with 'Title 2' inside of it, and store them into a variable.
> 1. Select the unordered list and store it into a variable.
> 1. Print out all of the values you selected from the DOM.

<hr>

### Text Content
With elements selected we can access the properties associated with them.

For example, one of those properties is `textContent`. The text content of an element defines the text within an HTML element with `.textContent`.

The `textContent` can both get and set the value of the `HTMLElement`'s text. The statement `element.textContent` would retrieve the value, while the expression `element.textContent = "Test"` would change the text value of the selected element, thus altering what the user sees.

```html
<html>
  <head>
    <title>Some Page</title>
    </head>
    <body>
        <h1>SD</h1>

        <script type="text/javascript">
            let header = document.querySelector('h1');
            console.log('Text Content: ' + header.textContent); // SD

            header.textContent = 'SD14';
            console.log('Text Content: ' + header.textContent); // SD14
        </script>

    </body>
</html>
```

```bash
Text Content: SD
Text Content: SD14
```

> ### ![Logo](http://skilldistillery.com/downloads/sd_logo.jpg) Skill Drill
> Using the same HTML as the previous drill, select the header with text content 'Header 33' and change its value to 'Header 3'.

<hr>

> ### ![Logo](http://skilldistillery.com/downloads/sd_logo.jpg) Skill++
> The DOM exists for all web pages and we can access these values by using the chrome console. For example, if we navigate to _CNN_ we can locally alter some of the values associated with their site.
> 1. Open the chrome console, and select the value with class `banner-text`.
>    ```js
>    let cnnHeader = document.querySelector(".banner-text");
>    ```
> 1. Change the `textContent` to a more interesting story.
>    ```js
>    cnnHeader.textContent = "SD Rocks!"
>    ```
> 1. We could even do a similar thing with the corresponding image.
>    ```js
>    let cnnHeaderImg = document.querySelector(".media__image");
>    cnnHeaderImg.src = "https://pbs.twimg.com/profile_images/720847195860127744/K4Ld3JCd_400x400.jpg";
>    ```

<hr>

[Prev](README.md) | [Up](README.md) | [Next](labs.md)

