## Variable Naming Rules
Java is a case-sensitive language.

In a single program, the following variable names would all refer to different variables:
```
number Number NUMBER NuMbEr
```
### Rules for Naming Variables
The Java compiler will enforce rules for naming variables.

We only need to remember three rules for declaring legal variables:
* The name must begin with a letter or `$` or `_`.
* Characters after the first character may also be numbers.
* You can't use Java _reserved words_. These are words in the Java language's vocabulary that you are not allowed to use, like `double` or `class`.

### Recommendations for Naming Variables
We also want to make sure that variables are useful to ourselves and other developers.

* Name variables something that is related to their purpose. `int age` is much better than `int x` when we want a variable for storing how many years a person has been alive.
* Use _camel case_, starting with a lowercase letter.

> #### camel case
> After the first word in a variable, the first letter of each concatenated word is capitalized. For example `camelCase` or `bookIdentificationNumber`.
>
> Naming variables is slightly different than naming a class, as classes use camel case but start with a capital letter, like `class VariableNaming`.

<hr>

[Prev](variables.md) | [Up](README.md) | [Next](literals.md)

