---
layout: default
title: Deaf Grandma
---

## Deaf Grandma

### Application Overview

You are going to see your sweet old Grandma. Unfortunately, she can't hear very well (she would never admit it, but she's stone cold deaf). This application will mirror your interactions with Grandma.

#### User Story #1

The user is prompted to say something to Grandma.

#### User Story #2

Grandma can only hear the user if the user yells (writes in capital letters).

#### User Story #3

When Grandma doesn't hear you, she yells a phrase such as "HUH? SPEAK UP BILLY!"

#### User Story #4

When Grandma does hear you, she yells something like "NO, NOT SINCE THE WAR".

#### User Story #5

Grandma will keep trying to have a conversation with you until you yell goodbye.

#### User Story #6

When you yell goodbye at Grandma she yells back something like "SMELL YOU LATER!"

#### User Story #7
Grandma needs more interesting phrases. In fact, she should choose from a _different_ set of phrases for her affirmative (hears you), negative (doesn't hear you), and farewell phrases.

Refactor your code so that Grandma will randomly choose a response. Each set of phrases should contain at least five things Grandma could say.

### Design Notes
Grandma should be an object in your program. This means there is a separate class for Grandma.

Grandma will decide if she hears you, and choose an appropriate response based on whether she does. Similarly, if you yell goodbye, she chooses how she responds. (This all means your main method does not contain the code for whether Grandma hears you. Instead, Grandma's methods determine this.)

The program has to exit at some point. Depending on your implementation, Grandma could call `System.exit(0)` after she says farewell. However, if Grandma returns her responses from a method, you will have to find another way to end the program. Perhaps Grandma has a `boolean` field that says whether she is still talking, which the program can check at the end of each iteration.

### Stretch goals
* Can you store all of Grandma's sets of responses in a single two-dimensional array?
* Can you choose Grandma's random response in a separate method? What about a _single_ method that can randomly choose an affirmative, negative, or farewell response (i.e. a random response from any array)?

<hr>

[Up](../README.md)
