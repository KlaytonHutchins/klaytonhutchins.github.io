## Labs

Going forward, we will stop using the default, unnamed package.  In fact, Eclipse warns us that its use is discouraged.

We'll also move away from simple package names like `examples` and `labs`, and develop the habit of using globally unique package names.

1. In the `Packages` project are some existing classes:

   ```
   com
      |_example
                      |_Helper.java
                      |_packages
                                |_Util.java
                                |_labs
                                      |_Product.java
   ```

   In the `com.example.packages.labs` package, create another class named `ProductMain` and replace its entire contents with the following:

   ```java
   public class ProductMain {

     Product product;

     public static void main(String[] args) {
       ProductMain app = new ProductMain();
       app.go();
     }

     public ProductMain() {
       product = new Product();
     }

     public void go() {
       Util.utilMethod();
       Helper.helperMethod();
     }
   }
   ```
   * Now add appropriate `package` and/or `import` statements so it will compile.

   (Solution: _com.example.packages.solutions.ProductMain_)

2. In your `com.example.packages.labs` package, create a new class named `ProductMainStatics` and replace its entire contents with the following:

   ```java
   package com.example.packages.labs;

   public class ProductMainStatics {

     Product product;

     public static void main(String[] args) {
       ProductMainStatics app = new ProductMainStatics();
       app.go();
     }

     public ProductMainStatics() {
       product = new Product();
     }

     public void go() {
       utilMethod();
       helperMethod();
     }
   }
   ```

   * Add `import` statements that will allow it to compile.

   (Solution: _com.example.packages.solutions.ProductMainStatics.java_)

<hr>

[Prev](staticImports.md) -- [Up](README.md)

