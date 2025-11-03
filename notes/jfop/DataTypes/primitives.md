---
layout: default
title: Primitive Data Type
---

## Primitive Data Types

There are eight primitive data types in Java, each using a certain number of bytes of memory.

| Type | Minimum | Maximum | Default | Size |
| - | - | - | - | - |
| byte | -128 | 127 | 0 | 8-bit signed integer |
| short | -32768 | 32767 | 0 | 16-bit signed integer |
| int | -2147483648 | 2147483647 | 0 | 32-bit signed integer |
| long | -9223372036854775808 | 9223372036854775807 | 0 | 64-bit signed integer |
| char | \u0000 | \uffff | \u0000 | 16-bit Unicode |
| float | -1.40239846e-45 | 3.40282347e+38 | +0.0F | 32-bit IEEE float |
| double | -4.94065645841246533e-324 | 1.79769313486231570e+308 | +0.0D | 64-bit IEEE double |
| boolean | false | true | false | N/A |

### Precision
* `float` = about 6 decimal places
* `double` = about 15 decimal places

### Practice Exercise
As a developer, you should know the exact bounds for a `byte`. Also know that the max for a `short` is about 32,000, and an `int` about 2 billion.

<hr>

[Prev](msb.md) -- [Up](README.md) -- [Next](primitives-memory.md)

