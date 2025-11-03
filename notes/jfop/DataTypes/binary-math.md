---
layout: default
title: Counting in Binary
---

## Counting in Binary

In binary only two symbols are available, `0` and `1`.

When we add `1 + 1` in binary, we must "carry the 1" to the next available place - just like in the decimal system when we add `9 + 1`.

<pre>
0000 = 0
0001 = 1
0010 = 2 (1 + 1 = 0; carry the 1)
0011 = 3
0100 = 4 (1 + 1 = 0; carry the 1; 1 + 1 = 0; carry the 1)
0101 = 5
0110 = 6
0111 = 7
1000 = 8
</pre>

The pattern we see is that every bit represents a power of `2`.

<table>
<tr>
  <td>Power</td>
  <td>2<sup>3</sup></td>
  <td>2<sup>2</sup></td>
  <td>2<sup>1</sup></td>
  <td>2<sup>0</sup></td>
</tr>
<tr>
  <td>Value</td>
  <td>8</td>
  <td>4</td>
  <td>2</td>
  <td>1</td>
</tr>
</table>

We can construct any number using these values.

<table>
<tr>
  <td>Bit</td>
  <td>0</td>
  <td>1</td>
  <td>0</td>
  <td>1</td>
  <td></td>
</tr>
<tr>
  <td>Value</td>
  <td>0</td>
  <td>4</td>
  <td>0</td>
  <td>1</td>
  <td> = 5</td>
</tr>
</table>

<table>
<tr>
  <td>Bit</td>
  <td>1</td>
  <td>0</td>
  <td>1</td>
  <td>1</td>
  <td>1</td>
  <td></td>
</tr>
<tr>
  <td>Value</td>
  <td>16</td>
  <td>0</td>
  <td>4</td>
  <td>2</td>
  <td>1</td>
  <td> = 23</td>
</tr>
</table>

### Drill
This drill requires pen and paper or whiteboard.
* What is `011011` in decimal?
* Write the number `28` in binary. How? Find the largest power-of-2 number you can have in 28. Subtract it. Find the next-largest. Repeat this pattern.
* Write the number `17` in binary.
* Write the number `43` in binary.

### Negative Numbers
To get the binary representation of a negative number, follow these steps:
* Take the binary positive number.
* Invert the bits
* Add 1.

For example, the number `-1`:
* `00000001`
* `11111110`
* `11111111` = `-1`

For the number `-15`:
* `00001111`
* `11110000`
* `11110001` = `-15`

<hr>

[Prev](bits-and-bytes.md) -- [Up](README.md) -- [Next](msb.md)

