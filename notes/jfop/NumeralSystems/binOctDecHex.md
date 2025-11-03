## Numeral Systems for Programming

There are a lot of systems in use besides base-10 or decimal:

* For example, base-12 in packaging and shipping: dozen eggs in a carton, a gross of eggs in a case of 12 cartons.

You'll use at least four numeral systems as a developer:

* Decimal (base-10):
  * `0`, `1`, `2`, `3`, `4`, `5`, `6`, `7`, `8`, `9`
  * No need to explain this further here.

* Binary (base-2):
  * `0`, `1`

* Octal (base-8):
  * `0`, `1`, `2`, `3`, `4`, `5`, `6`, `7`

* Hexadecimal (base-16):
  * `0`, `1`, `2`, `3`, `4`, `5`, `6`, `7`, `8`, `9`, `a`, `b`, `c`, `d`, `e`, `f`

Computer technology is built on binary arithmetic because our hardware represents information as two different states of matter (a low voltage and a high voltage).

* Number systems based on powers of two fit nicely in this world.

* Because 8 and 16 are powers of 2 (2<sup>3</sup> and 2<sup>4</sup>) these are very common in computing.

### Binary

Though we seldom use binary numbers directly, understanding and being able to count in binary is a necessary skill.

```
place: 8421   decimal value
       ----
          0   [0]
          1   [1]
         10   [2] (There are 10 kinds of people in the world: those who understand binary and those who don't.)
         11   [3]
        100   [4]
        101   [5]
        110   [6]
        111   [7]
       1000   [8]
       1001   [9]
       1010   [10]
       1011   [11]
       1100   [12]
       1101   [13]
       1110   [14]
       1111   [15]
      10000   [16]
```

### Octal

The value of any 8-bit byte can be represented with three octal digits.

### Practice Exercise

File permission modes are often represented using octal digits (`0` - `7`), one each for the file's _owner_, members of the file's _group_, and all _others_.

* In each of the three numbers, each bit (binary digit) represents whether a permission is enabled or disabled.

  * The permissions are _**r**ead_, _**w**rite_, and _e**x**ecute_.

    ```
    owner  group  other
    -----  -----  -----
    r w x  r w x  r w x    permissions
    4 2 1  4 2 1  4 2 1    place
    1 1 0  1 0 0  1 0 0    binary
        6      4      4    octal
    ```
    ```bash
    chmod 644 myFile.txt   # Read-write for me, read-only for everyone else.
    ```

### Hexadecimal

The value of any 8-bit byte can be represented with two hexadecimal digits (`0` - `F`).

* ASCII characters are often encoded in hexadecimal.

The value of any two-byte (16-bit) `short` or `char` can be represented with four hexadecimal digits.

* Java `char` values (other than ASCII characters) are given in hexadecimal.

  * The Unicode code charts list character values in hex.

  * Java _unicode escapes_ also use hexadecimal.

A 32-bit int can be represented with eight hexadecimal digits.

* Hexadecimal is used for network MAC addresses.

* IP addresses and their netmasks are often represented in hexadecimal.

* IPv6 addresses are always given in hex.

* Hexadecimal color values are common in HTML and CSS.


### Practice Exercise
For extremely large numbers like encryption keys, or for encoding binary data as text for transmission via text-based protocols like email, base-64 is commonly used.  In base-64 the digits include:
* The uppercase letters: `A` - `Z`  (26)
* The lowercase letters: `a` - `z`  (another 26, 52 digits so far)
* The digits: `0` - `9`  (10 of these, 62 digits, need two more)
* `+` and `/`

To use this, the data is broken into groups of _six_ bits - a six-bit number can be represented by a single base-64 digit (the largest 6-bit number is 63) - and then encoded with these digits.

<hr>

[Prev](positionalNotation.md) | [Up](README.md) | [Next](javaLiterals.md)

