## Positional Notation

We use _positional notation_ to represent numbers

> #### positional notation
> A numeral system in which each digit position has a place value, and the value of a number is the sum of each of the digits times its place value.

In positional notation we must define our numeral system's _base_ - how much each position is worth.

* This is the total number of unique numeral symbols we use, including 0.

  * In our familiar base 10, each place is worth a power of 10:

    ```
     12   - 1 times 10 plus 2 times 1
    404   - 4 times 100 plus 0 times 10 plus 4 times 1
    ```

  * In base 2, there are only two symbols, `0` and `1`, so each place is worth a power of 2.

    ```
      1   - 1 * 1                             [1, in base 10]
     10   - (1 * 2) plus (0 * 1)              [2]
    101   - (1 * 4) plus (0 * 2) plus (1 * 1) [5]
    ```

### Numerals

We're all familiar with the numerals of our base-10 system, in which each place is worth a power of 10: `0`, `1`, `2`, `3`, `4`, `5`, `6`, `7`, `8`, `9`.

* When we count past `9` we put a `1` in the next higher place and a `0` in the first place.


For base 2 counting we need only two numeral symbols, or digits: `0` and `1`.

```
11001   - (1 * 16) + (1 * 8) + (0 * 4) + (0 * 2) + (1 * 1) [25]
```

* Note that any leading zeros don't change the overall value:

  ```
  00011001   - (0*128) + (0*64) + (0*32) + (1*16) + (1*8) + (0*4) + (0*2) + (1*1) [still 25]
  ```

The more symbols our numeral system has, the less places it takes to represent a large number.

### Drill
Write out the following decimal numbers in binary:
* 3
* 4
* 7
* 11
* 16
* 15
* 20
* 21

Solution: _NumeralSystems/com.example.numeralsystems.solutions/SkillDrills1.java_

<hr>

[Prev](tallying.md) -- [Up](README.md) -- [Next](binOctDecHex.md)

