---
layout: default
title: HTML Forms
---

A key part of the Web is displaying forms and collecting data.

Forms provide an interface for a user to provide input, such as:
* Registration information
* Login credentials
* Shipping information
* Credit card data

The general structure of a form is:

```html
form tag
  data inputs
  ....
  submit buttom
/form tag
```

Code:

```HTML
<form action="collectData.html">
  <input type="text"/>
  <input type="date"/>
  <input type="submit"/>
</form>
```

### The `<form>` element
Forms consist of a few key elements, the first being:
```HTML
<form>
</form>
```
* This `form` tag provides an encapsulated area in which to add fields that pertain only to that one form.
* Multiple forms can exist on a single page.

#### `<form action="">`
Use the `action` attribute to set a destination for user input.

```html
<form action="collectData.html">

</form>
```

### Data Inputs
Input fields are exactly what they sound like, areas for user input.

The input tag is `<input>`.
* Input tags are used inside of an encapsulating `<form>` tag.

#### Input `type`
There are multiple types of inputs, such as checkboxes, buttons, dates, and radio buttons.

All inputs are rendered with the `<input>` tag.

The browser uses the `type` attribute assigned to the tag to determine what to render.

A few of the attribute options are listed below:
  * button
  * **checkbox**
  * **date**
  * email
  * **hidden**
  * month
  * password
  * **radio**
  * **submit**
  * **text**

#### `<input name="">`
Setting the `name` attribute gives the `input`'s data a name, for use by a server.
* The `name` and user-entered data make a key-value pair.
* `input` with a `name` renders the same, but now has a key.

```html
<input type="text" name="firstName">
```


#### `<input type="submit">`
Input elements of this type are rendered as buttons, and used to send `form` data to the form's `action` destination.

Code:
```html
<input type="submit">
```

Use the `value` attribute to change the button's text.

Code:
```html
<input type="submit" value="Button Text">
```

> ### Skill Drill
> `helloWorld.html`
>
> Add a form to your `Hello World` page
> * Set the `action` to the same page, `helloWorld.html`.
> * Add a `text` input, and give it a `name`.
> * Add a `submit` input, and use `value` to change the text.
>
> Use the form in Chrome.
>
> Add an `h2` header `Second Form`.
> Create another form on the page.
> * Give this form a `date` input, with a `name` attribute.
> * Add a `password` input with `name`.
> * Give the `submit` button different text than the other form.
>
> Use both forms in Chrome.

<hr>

[Prev](htmlGlossary.md) -- [Up](README.md) -- [Next](labs.md)

