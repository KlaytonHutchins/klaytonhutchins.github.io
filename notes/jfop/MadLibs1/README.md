---
layout: default
title: Mad Lib
---

## Mad Libs

We will be creating a Mad Libs game.

Mad Libs is a game where a user is prompted to enter parts of speech. The user's words are then used in a pre-defined section of text, usually some type of story.

### Example User Interaction
```
Enter a noun: STORE
Enter an adjective: BIG
Enter a plural noun: CATS
Enter a verb: SMOOCH
```

### Example Output
```
You go to a STORE and see BIG CATS.
You decide to SMOOCH them...
```

#### User Story 0
Create a program with a `main` method.

#### User Story 1
Write another method to handle creating and outputting the story. It will not output a story yet, but display something like `story method called`.

Call the method from `main` and verify that your program outputs your test message to the screen.

#### User Story 2
In your story method, request parts of speech from a user. This will require several prompts, and several variables for storing the data.

#### User Story 3
After you have retrieved all user input, use the data to create a story by using `String` concatenation.

Output the story to the screen.

Test your program.

#### HINT
This is much easier if you think of a story first, and then determine where you would put user-entered data. Then you will know which parts of speech to request from the user.

#### User Story 4
In `main`, give the user an option to choose a short or long story.

If the user chooses a short story, call your story method.

* **User Story 4.1**

  Repeat Users Stories 1-3 for a longer story. (Coding this will go faster because you have already done the process once.)

If the user chooses a long story, call your long story method.

<hr>

[Up](../README.md)
