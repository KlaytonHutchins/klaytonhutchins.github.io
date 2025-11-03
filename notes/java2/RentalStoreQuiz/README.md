## Rental Store Quiz

You are going to create an application that models a film rental store. The store is hoping to grow its list of registered customers, and make lots of money. When a new customer comes in, the store gathers their first and last name, and updates the system with their data.

Each customer can rent 0 or more films.
 
We have provided the `Customer` and `Film` classes for you.

This quiz requires you to add code to the `RentalStoreQuizApp` and `Store` classes, in addition to finishing the `RentalStoreTests` JUnit test.

You will:

* Finish implementing the given `Store` class, where each `Store` has
    * An integer identifier
    * 0 or more registered _unique_ `Customer`s  <br/>
    * Methods to add a customer, return the number of customers, and display all data in the store and its customers.

* Finish implementing the `RentalStoreQuizApp` methods that allow you to:
    * Create a store  
    * Create a customer  
    * Register a customer with the store
    * Display all the store's customer data, including any films they may have rented  <br/> 

* Finish implementing the provided JUnit test
    * The JUnit test will verify that you can not add a duplicate customer to a store.

This is a graded quiz.

1. Download  [RentalStoreQuiz.zip](RentalStoreQuiz.zip) 

1. Move it from _~/Downloads/_ to _~/SD/Java/_.

1. Import it into Eclipse.

   * Open _RentalStoreTests.java_, hover over the first error, select `Fix project setup...`, and click **OK** to _Add JUnit 5 library to the build path_.

1. Change directories (`cd`) into _~/SD/Java/workspace/RentalStoreQuiz/_.

1. On Github, create a repository named **RentalStoreQuiz**.

1. In _~/SD/Java/workspace/RentalStoreQuiz/_, initialize git and connect the remote repo:

   ```bash
   echo "# RentalStoreQuiz" >> README.md
   git init
   git add README.md
   git commit -m "first commit"
   git branch -M main
   git remote add origin https://github.com/YOURGITHUBUSERNAMEHERE/RentalStoreQuiz.git
   git push -u origin main
   ```

When you finish, push to Github.


<hr>

[Up](../README.md) | [Next](RentalStoreQuiz.zip)
