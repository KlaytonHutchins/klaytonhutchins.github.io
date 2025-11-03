---
layout: default
title: Stretch Goal : Mayhem
---

## Stretch Goal : Mayhem
Sometimes things go wrong. In the case of the Sanctuary, all the habitat doors open and the Carnivores are loose.

Carnivores will visit other habitats and eat other Animals until one remains.

##### Functionality
Translating this scenario into code can be challenging, and requires design decisions.

The functionality will exist in a new method.

* `Carnivore`s - and only `Carnivores`s - will try to eat other Animals from the `Animal[]`.
* `Carnivore`s cannot eat themselves - you must prevent this somehow.

Decisions:
* Does a single `Carnivore` iterate the entire array, and thus always be the last one remaining, or does it eat one Animal, then the next `Carnivore` tries?
* Do `Carnivore`s go through the `Animal[]` in order, or do they choose a random habitat?
* How does the `Carnivore` know there are no other Animals left?
* Does mayhem occur with each run of the program? Is it random? Is it a menu choice, like the Attendant doing rounds?

Sample Output:
```
Welcome to the Sanctuary.
What would you like to do?
1. Add an Animal
2. Start the Attendant's rounds
3. List Animals
4. Exit
5. Mayhem

Your choice: 5
The animals are out of their cages!
I'm Hillary the Hippo and this Giraffe is yummy!
I'm Leon the Lion and this Hippo is yummy!
I'm Leon the Lion and this Elephant is yummy!
Who's left?
Leon the Lion
```

<hr>

[Prev](menu.md) -- [Up](README.md)

