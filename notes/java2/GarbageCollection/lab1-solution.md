## Lab 1 Solution
After which line is the object created at line `4` eligible for garbage collection?
```java
1: public class GCObj {
2:   public static void main(String[] args) {
3:     GCObj one = new GCObj();
4:     GCObj two = new GCObj();
5:     GCObj three = one;
6:     one = null;
7:     GCObj four = one;
8:     three = null;
9:     two = null;
10:    two = new GCObj();
11:  }
12:}
```

![one initialized](images/lab1-line3.png)

![two initialized](images/lab1-line4.png)

![three points to one](images/lab1-line5.png)

![one points to null](images/lab1-line6.png)

![four points to one object](images/lab1-line7.png)

![one broken](images/lab1-line8.png)

![three broken, now eligible for gc](images/lab1-line9.png)

![two is a new object](images/lab1-line10.png)

It is eligible after line `9`.

<hr>

[Prev](labs.md) | [Up](README.md) | [Next](lab2-solution.md)

