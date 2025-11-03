---
layout: default
title: Most Significant Bit
---

## Most Significant Bit

If part of determining a negative number is inverting the bits, how can Java determine if a number is positive or negative?

Data types in Java each have a certain number of bytes.
* This is important for _signed_ data types because the left-most bit, or _most significant bit_ tells whether a number is positive or negative.

| MSB | Sign |
| --- | ---- |
| 0 | positive |
| 1 | negative |

With the left-most bit now reserved for positive or negative, we can determine the maximum and minimum values for `byte`.

<table>
<tr>
<td>MSB</td>
<td>2<sup>6</sup></td>
<td>2<sup>5</sup></td>
<td>2<sup>4</sup></td>
<td>2<sup>3</sup></td>
<td>2<sup>2</sup></td>
<td>2<sup>1</sup></td>
<td>2<sup>0</sup></td>
<tr>
<tr>
<td>0</td>
<td>64</td>
<td>32</td>
<td>16</td>
<td>8</td>
<td>4</td>
<td>2</td>
<td>1</td>
</tr>
</table>

The maximum value for a byte is `127`.

Recall that `-1` is `11111111`.
* The most negative `byte` possible is `10000000` - this value is `-128`.

### Practice Exercise
The `char` data type is not signed. There is no such thing as a negative character.

<hr>

[Prev](binary-math.md) -- [Up](README.md) -- [Next](primitives.md)

