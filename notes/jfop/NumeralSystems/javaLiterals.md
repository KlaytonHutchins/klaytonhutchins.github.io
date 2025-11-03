## Numeric Literals in Java

When we write a numeric literal in our code, Java interprets it as base-10 or decimal.

* If we code `int i = 12`, that's 12; a dozen.

### Non-decimal Literals

A leading zero in front of a number doesn't change its magnitude.

* It does change how Java _interprets_ the number.

#### Octal

A simple leading `0` tells Java our number is base-8 or octal.

* If we code `int i = 012`, it's octal 12 (1\*8 + 2\*1): actually a decimal `10`.

#### Hexadecimal

When we add a leading `0x`, we're telling Java our number is base-16 or hexadecimal.

* If we code `int i = 0x12`, (1\*16 + 2\*1): that's actually a decimal `18`.

* If we code `int i = 0xa`, that's a decimal `10`.

  * We could also code this as `0x000a`.

#### Binary

When we add a leading `0b`, we're telling Java our number is base-2 or binary.

* If we code `int i = 0b12` we get a compiler error: there's no `2` in binary.

* If we code `int i = 0b10`, (1\*2 + 0\*1) that's actually a decimal `2`.

  * We could also code this as `0b00000010` as a reminder there's eight bits in a byte.

### Practice Exercise
For all of these Java numeric literals that contain alphabetic characters, it doesn't matter if you use lower or upper case:
```java
i = 0B0100;
i = 0X123AbC;
```
Reference: https://docs.oracle.com/javase/specs/jls/se8/html/jls-3.html#jls-3.10.1

### Formatting

You can use underscores in all of these for readability.

```java
int ipAddress = 0xc0_a8_01_65;
int permissions = 0b0_110_100_100;
char newLine = 012;  // ASCII 10, aka '\n'
int oneMillion = 0b00000000_00001111_01000010_01000000;
```

* Remember the rule for `_` in number literals: there must be a digit or another underscore on either side.

  ```java
  int i = 0x_1abc;        // NO
  int k = 0b01001_;       // NO
  float f = 0x01abc_.246; // NO
  ```

### Drill
Yes or no: which of these declarations will compile?
```
int i1 = 678;
int i2 = 0678;
int i3 = 0x678;
int i4 = 01101;
int i5 = 0b1101;
int i6 = 0x01101;
int i7 = 1101;
int i8 = 0x12;
int i9 = 0b12;
int ia = 0xb2;
int ib = 0bx2;
int ic = 0b_101_111_111;
int id = 0xb10_000;
int ie = 0b10_000;
int if_ = 0xCAFE_BABE;

double d1 = 123.456;
double d2 = 1.235_56;
double d43 = 123._456;
```

Solution: _NumeralSystems/com.example.numeralsystems.solutions.SkillDrills2.java_

<hr>

[Prev](binOctDecHex.md) | [Up](README.md) | [Next](printf.md)

