## Lab 1 Solution
After which line is the object at line `6` eligible for garbage collection.
```java
1: public class RefObj {
2:
3:   private RefObj ref;
4:   
5:   public static void main(String[] args) {
6:      RefObj a = new RefObj();
7:      RefObj b = new RefObj();
8:      b.ref = a;
9:      a = null;
10:     RefObj c = a;
11:     b = null;
12:   }
13: }
```

![a is new object](images/lab2-line6.png)

![b is new object](images/lab2-line7.png)

![b ref points to a](images/lab2-line8.png)

![a is broken, but b.ref still points to a](images/lab2-line9.png)

![c points to a null](images/lab2-line10.png)

![b is broken](images/lab2-line11.png)

It is eligible when the method finishes.

<hr>

[Prev](lab1-solution.md) -- [Up](README.md)

