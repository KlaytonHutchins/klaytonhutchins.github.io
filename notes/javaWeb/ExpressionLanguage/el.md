## JSP Expression Language Syntax
JSP Expression Language (JSP EL) allows us to present data from a servlet on the JSP page.

### `${  }`
EL uses `${expression}` syntax.

```html
${stock}
```

* The value within the curly braces is usually a JavaBean that the servlet created and saved to a _scope_ accessible by the JSP.
* Whatever we put in braces is evaluated at runtime and written to the response.

> #### scope
> In web applications, scope is where the data is stored, which affects where it is available.

We do not have to add any dependencies to enable EL.

<hr>

[Prev](README.md) -- [Up](README.md) -- [Next](el-model.md)

