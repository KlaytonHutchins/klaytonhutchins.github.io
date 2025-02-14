## Using a Selected Element to traverse the DOM

Once an HTML element has been selected you can access that element's children, parent, and siblings.

#### Children
* `children`- returns all elements that are direct children of the selected element.  

* `firstElementChild`- returns the first child of the selected element. `target.children[0] => target.firstElementChild`  

* `lastElementChild`- returns the last child of the selected element. `target.children[target.children.length -1] => target.lastElementChild`  

* `hasChildNodes()`- returns a boolean representing if the element has any children.

#### Siblings
* `previousElementSibling`- returns the sibling to the _left_ of the selected element.

* `nextElementSibling`- returns the sibling to the right of the selected element.

#### Parent
* `parentElement`- returns the selected element's parent.


### Example
```html
<html>
  <head>
    <title>Some Page</title>
    </head>
    <body>
        <ul id="list">
            <li>item 1</li>
            <li>item 2</li>
            <li>item 3</li>
            <li>item 4</li>
            <li>item 5</li>
        </ul>

        <script type="text/javascript">
            let list = document.getElementById('list');

            console.log(list.children.length);

            console.log(list.childElementCount); // essentially the same as using .length

            // List of child elements
            console.log(list.children);

            // Access one of the children HTMLElements
            console.log(list.children[2]);

            // One single parent
            console.log(list.parentElement);
        </script>
    </body>
</html>
```

```bash
5
5
[li,li,li,li,li]
<body>...</body>
```

> ### ![Logo](http://skilldistillery.com/downloads/sd_logo.jpg) Skill Drill
> Use the following HTML for this example.
> ```html
> <body>
>   <div id="wrapperDiv">
>     <ul>
>       <li>List 1</li>
>       <li>List 2</li>
>     </ul>
>   </div>
> </body>
> ```
> 1. Select the unordered list and return a list of its children.
> 1. Select the parent element of the unordered list.
> 1. Select the parent element of the div.
> 1. Select the second list item and print out its `textContent`.

<hr>

[Prev](traversingTheDom.md) | [Up](README.md) | [Next](labs.md)

