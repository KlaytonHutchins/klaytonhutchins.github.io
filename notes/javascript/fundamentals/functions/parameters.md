---
layout: default
title: Function Parameters
---

Function _parameters_ are the names provided in the function definition.

Function _arguments_ are the values passed to the function when it is invoked.

JavaScript functions do **not** check the _type_ of incoming arguments.

```javascript
let petArray = ['cat', 'dog', 'frog'];

function funType(array, num) {
  return array[num];
}

funType(petArray, 1);    // petArray[1] ==> 'dog'
funType('hello', true);  // 'hello'[true] ==> undefined
```

Functions do **not** check the _number_ of arguments being passed when a function is invoked.

```javascript
function oneParam(x) {
  return x * x;
}

oneParam(5,6,'hello',true,{},[42]); // 25
```

The interpreter cannot differentiate between two functions with the same name (as it pays no attention to the number of parameters, and there is no return type). 

If you declare two functions with the same name, second one will replace the first.  

```javascript
function overwrite(x,y) {
  return 'FIRST';
}

function overwrite(arr,index,value) {
  return 'SECOND';
}

overwrite(0,12); // 'SECOND'
```

If it is imperative for a function to only accept certain types of arguments, you will have to enforce this yourself and perform type checking.

```javascript
function greet(name) {
  if (typeof name !== 'string') {
    throw new Error("argument (name) must be a string");
  }
  return "Hello " + name;
}
```

The function parameter names just give us a convenient way to reference the arguments we expect.

#### Default Values

Default values for a parameter can be assigned in the parameter list. 

If a value is provided to the function for the parameter, the passes in value will be assigned. 

If it is omitted, the default value will be used in its place.

```js
function func(x, y = 14, z = "Test") {
  console.log("x: " + x + " y: " + y + " z: " + z);
}

func();       //x: undefined y: 14 z: Test
func(5);      //x: 5 y: 14 z: Test
func(1,2,3);  //x: 1 y: 2 z: 3
```

### The `arguments` Object and Varargs Functions

In JavaScript, the way to access an arbitrary number of arguments is with the `arguments` object.

All of the arguments passed to a function at time of invocation can be accessed within the body of that function via the `arguments` object.

`arguments` is an array-like object (**not an Array**) that grants access to all arguments passed at the time of invocation by index.

```js
function sum() {
  let total = 0;
  for (let i = 0 ; i < arguments.length ; i++ ) {
    total += arguments[i];
  }
  return total;
}

sum(1,2,3,4,5); // => 15
```

Functions like the one above are called *variadic functions* or *varargs functions*.

#### Variadic arguments

We can define named parameters and still collect any additional arguments with `...` in front of the final parameter.

```js
function func(x, y, ...z){
  console.log("x: " + x + " y: " + y + " z: " + z.length);
}

func(1,2,"A","B","C","D");       //x: 1 y: 2 z: 4
```

In all cases, the `arguments` array will still contain the full list of arguments.

#### Spread Operator

The `...` is called the _spread_ operator which "spreads" an iterable into literals of its contents.

```javascript
function funcSpread() {
  console.log('Number of arguments: ' + arguments.length);
  console.log(arguments);
}

let petArray = ['cat', 'dog', 'frog'];

funcSpread(17, 'hello', petArray);
// Number of arguments: 3
// 0: 17
// 1: "hello"
// 2: (3) ['cat', 'dog', 'frog']

funcSpread(17, 'hello', ...petArray);
// Number of arguments: 5
// 0: 17
// 1: "hello"
// 2: "cat"
// 3: "dog"
// 4: "frog"
```

It can also be used to combine separate arrays into one collection.

```js
let arr1 = [1,2,3];
let arr2 = ["Apple", "Banana", "Coconut"];
let arr3 = ["Test", ...arr2];

arr1.push(...arr2);    //[1, 2, 3, "Apple", "Banana", "Coconut"]
arr3;                  //["Test", "Apple", "Banana", "Coconut"]
```

```js
let name = "Samantha";
let nameArr = [...name];  // ["S", "a", "m", "a", "n", "t", "h", "a"]
```

<hr>

[Prev](definitions.md) -- [Up](README.md) -- [Next](expressions.md)

