## Conditional Statements

### If statements
JavaScript `if` statements are identical to their Java counterparts' syntax.

```javascript
// simple
if (1 < 2) {
	// do something
}

// With an else clause
if (condition) {
	// do something
} else {
	// do some other thing
}

// With more conditions

let num = 9;
if (typeof num === 'number') {
	// do this thing
} else if (typeof num === 'string') {
	// do this other thing
} else {
	// otherwise do this
}
```

### Switch Statements
`switch` statement syntax should also be very familiar.

```javascript
switch(num) {
	case 1:
		// do something
		break; // --> Stop! Do not cascade
	case 2:
		// do something
		// --> no break, keep going
	default:
		// do this if nothing else
		break;
}
```

<hr>

[Prev](README.md) | [Up](README.md) | [Next](loops.md)

