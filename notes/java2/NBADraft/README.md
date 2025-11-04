---
layout: default
title: Lottery: NBA Draft
---


### Application Overview

Each summer the National Basketball Association (NBA) conducts a lottery to determine which team gets the first pick in the upcoming draft.  The fourteen teams that failed to make the playoffs the previous season are eligible to participate in the lottery.  

Let’s assume that the lottery drawing uses 1000 ping pong balls placed in a hopper.
* Each ping pong ball has the name of a team on it.

Each team has a different number of ping pong balls in the hopper based on their record.
* The team with the worst record (seeded number 1) has a better chance to win the lottery with 250 balls than the team with the best record which has just 5 balls in the hopper.

The team whose name is listed on the first ball drawn is the winner and is awarded the first pick in the draft.

Each team would have the following number of balls:

| Seed | Number |
| - | - |
| 1 | 250 |
| 2 | 199 |
| 3 | 156 |
| 4 | 119 |
| 5 | 88 |
| 6 | 63 |
| 7 | 43 |
| 8 | 28 |
| 9 | 17 |
| 10 | 11 |
| 11 | 8 |
| 12 | 7 |
| 13 | 6 |
| 14 | 5 |

See this wikipedia page for more information on the lottery:

https://en.wikipedia.org/wiki/NBA_draft_lottery

#### Task 1
Before writing any code, design classes for a ping pong ball, a hopper, and something that will create balls with labels on them.

* This should be simple classes that are completely uncoupled from the NBA draft: you should be able to use these classes, unchanged, in a bingo or other lottery application.

Implement these classes in their own package.

#### Task 2
Design your NBA draft application classes by thinking about the roles involved.
* Who creates and owns the hopper?
* Who creates the balls to put in the hopper?
* Who specifies the team names and how many balls they get?  How do they provide this information to the owner of the hopper?
* Who draws the winner?
* Who initiates the draft and announces the winner?

Implement these in a different package than the ball and hopper classes.

#### Task 3
Design an NBA draft simulator that runs `100` simulations - creating and loading the hopper, and drawing one winner - and prints out the winner each time.

#### Task 4
Next, have your simulator calculate and display the total number of times each team won for various numbers of simulations.

For example, if a team is the first seed for `1000` simulations, we expect that team would win about `250` times. But does it? What about for `100` simulations?

#### Task 5
Print the simulation results as a list in order from highest number of wins to lowest.

<hr>

[Up](../README.md)
