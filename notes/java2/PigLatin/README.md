---
layout: default
title: Project: Pig Latin
---


### Application Overview

You are going to write a translation program that converts English into [Pig Latin](pig_latin.md).

#### Class structure

The class that does the conversion will extend an abstract class that partially implements an interface.

* `Translator` - interface for translation with two methods:

  ```java
  String translateWord(String word);
  String translateText(String text);
  ```

* `AbstractTranslator` - `implements Translator`, implements `translateText` which breaks its input into words, passing each word to `translateWord` to be translated, and builds a new string of the translated text.

* `PigLatinTranslator` - `extends AbstractTranslator`, implements `translateWord`.

   * You will write JUnit tests for this class.

* `TranslatorApp` - has `main` method, takes user input, calls `Translator` method(s).

![Translator UML](images/Translator.png)

#### JUnit tests

Create and implement JUnit tests for your `PigLatinTranslator` based on the  [Pig Latin Rules](pig_latin.md) . Also be sure to handle `null` inputs. Methods should be well-named to reflect the class's functionality, such as

```java
@Test
public void test_translateWord_returns_empty_String_for_null_input(){
  //tests
}

@Test
public void test_translateWord_for_word_starting_with_consonant_and_vowel_moves_consonant_to_end_of_word_and_adds_ay(){
  //tests
}

// etc.
```

_Write JUnit tests before method implementations._


### Prerequisites

Create a `Translation` application with appropriate package(s).

Define the `Translator` interface, the `AbstractTranslator` abstract class, and the `PigLatinTranslator` concrete class, with methods stubbed in each.

Create a new _Source Folder_ for tests, and add the same package(s) to it.

Create a JUnit test case for the `PigLatinTranslator` class.

Create JUnit tests for `PigLatinTranslator`.

Implement `AbstractTranslator.translateText`.

Implement `PigLatinTranslator.translateWord`, and get all your tests to pass.

### User Story #1

User is prompted for a word.

### User Story #2

The word the user entered is displayed, along with the pig latin equivalent.

### User Story #3

The user can enter any number of words (a sentence/paragraph), and it will be displayed along with the pig latin translation.

### Stretch Goals

* Make sure everything is encapsulated within methods, only call one method in your main.

* Did you use `StringBuilder` to complete this?

* In the translated text, preserve all white space and punctuation from the input text.

* Preserve capitalization: translate "Hello, my name is Melvin!" to "Ellohay, ymay amenay isway Elvinmay!".

* Add an option for the user to enter a filename, and have the contents of the file translated and displayed.

<hr>

[Up](../README.md) -- [Next](pig_latin.md)
