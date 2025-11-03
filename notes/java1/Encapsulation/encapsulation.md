## Encapsulation

One of the most important features of Object-Oriented Programming is `encapsulation`.

> #### encapsulation
> Hiding internal state and requiring all interaction to be performed through an object's methods.<sup>1</sup>

Encapsulation insulates changes from propagating throughout your program.

* This is good because if a private part is changed, that change is constrained to the class in which it was defined.

To increase encapsulation, you should:

* Give fields and methods the most restricted access possible.

* Make all fields `private` and provide non-private methods to access and modify (or _mutate_) them.

> #### mutate
> A fancy word for _change_. A method that sets a `private` field could be called a _mutator_.  Similarly, a method that retrieves the value of a `private` field could be called an _accessor_.
> Or we could just call them a _setter_ and a _getter_.

The goal of encapsulation is to keep users from changing data you don't want them to change, or changing it in a way we don't want them to.

### Practice Exercise
> Allowing other code to access fields directly could create an unwanted _dependency_. This means other code expects our code to work a certain way.
>
> If we change a field's visibility later, we risk breaking other code that depends on our field being visible.
>
> Practice good encapsulation from the start.

### Drill
>
> `Encapsulation/com.example.encapsulation.drills.BankApp`
>
> `Encapsulation/com.example.encapsulation.drills.Account`
>
> You have already made the `accountId` and `balance` fields private in `Account`.
> * Add four `public` methods to `Account`.
>   * `getAccountId()` to allow users to retrieve the `accountId`.
>   * `setAccountId(String id)` to allow users to set the `accountId` field by passing a new value.
>   * A `get-` and `set-` method for the `balance`.
> * Call the methods from `BankApp`.
>
> (Solution:_BankApp2.java_, _Account2.java_)



### Drill
>
> `Encapsulation/com.example.encapsulation.drills.Student`
>
> ```java
> public class Student{
>  
>  int[] scores;
>  private double average;
>  
>  public int[] getScores(){ return scores; }
>  
>  public double getAverage(){ return average; }
>  
>  private void computeAverage(){
>      // valid code to compute average
>      // average = update average value
>  }
>
>  public Student(){
>      computeAverage();
>  }
> }
> ```
> What two things can we do to improve the encapsulation of this class (choose two)?
> * [ ] Make the class `private`.
> * [ ] Make the scores instance field private.
> * [ ] Make getScores() `protected`.
> * [ ] Make computeAverage() `public`.
> * [ ] Change getScores to return a copy of the scores list:
>  ```java
>  public int[] getScores() {
>    int[] sCopy = new int[scores.length];
>    for (int i=0; i < scores.length; i++) {
>      sCopy[i] = scores[i];
>    }
>    return sCopy;
>  }
>  ```
> (Solution: _Student.java_)

[1] https://docs.oracle.com/javase/tutorial/java/concepts/object.html

<hr>

[Prev](visibility.md) | [Up](README.md) | [Next](getters-setters.md)

