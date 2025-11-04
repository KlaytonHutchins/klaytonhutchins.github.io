---
layout: default
title: Lab
---


`Rank` and `Suit` are available in the `solutions.cards` package. Use them to create the classes in these labs. Be sure to copy-paste them into the package where you create your new classes.

1. Create a class called `Card`.
   1. A card has a `Suit` and `Rank`. Set these in the constructor.
   1. Generate the methods `hashCode` and `equals`
   1. Add a `toString` which says `rank + " of " + suit`.
   1. Add a method `getValue` to return the card's numeric value.

   (Solution: _Card.java_)

1. We will be simulating a deck of cards.
   1. Create a class `Deck`. It will hold a `List` of `Card`s.
   1. In the constructor, initialize the `List` with all 52 cards.
   1. Add a method `checkDeckSize` which returns the number of cards still in the deck.
   1. Add a method `dealCard` that removes a `Card` from the deck.
   1. Add a method `shuffle` to shuffle the deck.

   (Solution: _Deck.java_)

1. Write a program to ask a user how many cards they want.
   * Handle the case where users enter a non-integer or a number greater than `52`: print an error message.

   Deal the cards and display them on the screen. Also display the total value of all cards.

   (Solution: _Dealing.java_)

<hr>

[Prev](enum-members.md) -- [Up](README.md)

