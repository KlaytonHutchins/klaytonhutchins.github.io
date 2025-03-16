---
layout: default
title: HTML
---

### Overview
HTML is a markup language we will be using to display information via web browsers to a user.
* All HTML documents follow the same base structure.
  * They are written inside of files with the `.html` extension.

#### Structure
```HTML
<!DOCTYPE html>
<html>
<head>
  <title>Page Title</title>
</head>
<body>

</body>
</html>
```

The `<head>` of the document contains _meta-information_ about the document that is being displayed.

> #### meta-information
> Information about information.
>
> If the HTML page is the information, the title is meta-information.

The `<body>` contains all of the visible elements the user can interact with on a page.
* This is where we will be adding HTML elements to the document.


### Elements
HTML elements or _tags_ are keywords wrapped in angle brackets.
* Most elements require an opening and closing tag.
* The closing tag adds a `/` in front of the final keyword.

```html
<h1>Hello</h1>
```

* `<h1>`: opening tag of type `h1`.
* `Hello`: the tag's content. This is what will be rendered to the screen.
* `</h1>`: closing tag. Must match the type of the opening tag, `h1`.

If you forget an end tag, some browsers may not be able to properly interpret your document.

Because HTML is so forgiving, the browser will attempt to render the content anyway. This can result in elements being unexpectedly nested or some other bizarre behavior.
```html
<h1>Hello
```

#### Empty tags
Some elements do not require an opening and closing tag.
* A break tag, which inserts an empty line at that location, can simply be added as `<br>`.

Other examples of this are image tags or form inputs:
```html
<img src="myPicture.jpg">
<input type="submit" value="SUBMIT">
```

> ### Skill++
> If an element is not going to have content inside of it, it may be an indicator that you do not need a closing tag.

#### Nested elements
Some HTML elements are required to be nested.

When building a list, for example, you have the options of a numbered, ordered list; or bulleted, unordered list.
* These tags are `<ol>` for ordered, and `<ul>` for bulleted.
* When building one of these elements the list type element wraps the content that will be inside of the list. Each `<li>` below is a bullet point.

```html
<ul>
  <li>Mike</li>
  <li>Davey</li>
  <li>Peter</li>  
  <li>Mickey</li>
</ul>
```
Yields:
* Mike
* Davey
* Peter
* Mickey

```html
<ol>
  <li>Mike</li>
  <li>Davey</li>
  <li>Peter</li>  
  <li>Mickey</li>
</ol>
```

Yields:  
1. Mike  
2. Davey  
3. Peter  
4. Mickey

> ### Skill++
> Tim Berners-Lee, inventor of the World Wide Web, originally invented HTML as a medium to share academic papers with his peers.

<hr>

[Prev](README.md) -- [Up](README.md) -- [Next](htmlHelloWorld.md)

