---
layout: default
title: Task 1: Class Design
---


Before writing any code, you will design your application classes.

Brainstorm as a team, and start roughing out a class diagram.

### Actors

Think about the active parts of your game: the player, non-players the player fights, other non-players the player might interact with.  What do they have in common? How do they differ?  What are the actions they can can be instructed to take?  Can you find uses for inheritance and polymorphism?

How do they interact in a turn of the game?  If there is combat, how does one attack the other, and how does that change their state?

If there are game items, how many of each can a player carry?  How are they stored?

### Items

Will characters be given, find, or earn items - weapons, health boosts, treasure?

How can you use inheritance?

### Game

What class keeps track of a player, allowing them to proceed through the game in response to user input?  How does it initiate interaction between characters?

How does the game get launched?

Where is the main game loop going to run?

How are turns handled?  Is there one path through the game? What choices can the player make at each stage?

Where is `main`?

### Overall

* Maximize cohesion - a class has only the state and behavior of the thing it represents.
* Minimize coupling - a class is as independent as possible of other classes.
* Separate responsibilities - only one class should be interacting with the user, displaying menus, getting input, showing results.

<hr>

[Prev](README.md) -- [Up](README.md) -- [Next](task2.md)

