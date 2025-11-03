---
layout: default
title: Jet
---

## Jets

### Application Overview
You are going to create a fleet of jets with different capabilities. Your application will be a menu to use your jets and access information about them.

As you work through the user stories think about what classes you will need before your start writing code.

### Structure
All jets must have a `model`, `speed`, `range`, and `price` associated with them. Speed is in MPH, but your Jet can also output the speed in mach.

Jets have a `fly()` method that prints out the jet details and the amount of time the jet can fly until it runs out of fuel (based on speed and range).

#### Specialized Behavior
`Jet` itself is an `abstract` base class. Its purpose it to be extended by other types with different behavior.

That said, you will still have a plain vanilla Jet class. Create a `JetImpl` class that extends the base class.

You must create two interfaces of your choice for specializations of Jets. For example, `CargoCarrier` could have a `loadCargo()` method (which just prints out a message about loading cargo). `CombatReady` could have a method `fight()`.

You will create at least two implementation classes that extend `Jet` and implement your interfaces. (The more types you have, the more interesting the project.)
* Do not structure your code so that _all_ implementation classes implement _all_ interfaces. We want Jets with different capabilities.


### UML Diagrams
For those of you that are having trouble getting started, we have provided you with a potential UML diagram [here](images/UMLJets.png). (The diagram does not contain all the methods you will need.)

#### User Story #1
Create a `JetsApplication` with a `main` method to launch your program.

#### User Story #2
Jets are found at an `AirField`. Create the `AirField` class, which has an empty `List` of Jets.

#### User Story #3
On program startup, populate the `AirField` with at least 5 Jets of different types.

These jets must be read from a text file, where each line in the file contains data for a single `Jet` object.
* This file exists at the root of your Eclipse project. It can be comma- or tab-separated; either implementation is acceptable.
* The method to parse a file into `Jet` objects should return a `List<Jet>`. Its parameter can be a `String` file name.
  * Remember to use `String.split(regex)` to break each line in the file into data to create an individual jet.

#### User Story #4
There is a menu with these options:
1. List fleet
1. Fly all jets
1. View fastest jet  
1. View jet with longest range  
1. _Load all Cargo Jets_
1. _Dogfight!_
1. Add a jet to Fleet
1. Remove a jet from Fleet
1. Quit

#### User Story #5
List fleet prints out the model, speed, range, and price of each jet. (There must be at least 5 jets stored when the program starts).

#### User Story #6
Fly all Jets calls the `fly()` method on the entire fleet of jets. `fly()` prints out the jet details and the amount of time the jet can fly until it runs out of fuel (based on speed and range).

#### User Story #7
The view fastest jet and longest range options both print out all of the information about a jet.
* Note: these methods must _search_ the collection of jets to find the appropriate jet.

#### User Story #8
The user is presented with an option specific to the interfaces you created. For example, _Load all Cargo Jets_, above, finds all implementors of the `CargoCarrier` interface and calls `loadCargo()` on each. (Note that the menu text is italicized because your options may be different, depending on your interfaces.)

#### User Story #9
A user can add custom jets to the fleet.
* This can be a `JetImpl`.
* Stretch Goal: This leads to a sub-menu where the user chooses the type of Jet.

Users then enter information for the Jet, and it is added to the `AirField`.

#### User Story #10
A user can remove a jet from the fleet.
* The user is presented with a sub-menu to select a jet to delete by number.
* Stretch Goal: a user can remove a jet (or jets) by name.

#### User Story #11
Quit exits the program.


### Stretch Goals

Try implementing these stories only when you have committed and pushed a working project.

#### User Story #12
Users see a menu item to fly an individual Jet, and then choose the Jet in a sub-menu.

#### User Story #13
Each jet has a pilot.

#### User Story #14
Assign a random pilot to each jet that is created.

#### User Story #15
Users can hire pilots.

#### User Story #16
Whenever a jet's information is displayed, that jet's pilot and his/her information should also be displayed.

#### User Story #15
The user is given a menu option to save jets to a file.  When selected the user enters the file name.  The program then saves all jets to that file in the same format as the original input file.  The code should first check that the file name isn't the same as the original input file, printing an error message if it is.


### Grading
This is a graded project. You are expected to have your project completed by the start of class next week.

You will be given either a pass or fail based on whether your code works given all of the following test conditions:

* The initial list of Jets must be loaded from a text file.
* When menu option 1 is pressed all Jets in the fleet are displayed to the user.
* When menu option 2 is selected, `fly()` is executed on all Jets.
* When menu option 3 is selected, the fastest jet from the list of Jets should be displayed to the user.
* When menu option 4 is selected, the jet with the longest range should be displayed to the user.
* Choosing type-specific behavior calls the interface method for those Jets.
* When the user chooses to add a Jet, you are prompted to enter the model, speed (in MPH), range, and price. This Jet should be added to the list of Jets so that when the user again selects menu option 1, that custom jet is included.
  * If you implement the option to choose Jet type, this menu displays before entering Jet data.
* When the user chooses to remove a Jet, the user is presented a menu for selecting the jet to remove.
* The final menu option should exit the program.

If the project does work with all of the above test conditions, you will be given a 1 for this week's project.

If the project does not work with the above test conditions, you will be given a 0 for this week's project.

If you get a zero on the project, you can upgrade to a score of .5 if you turn in a working project by the start of class on the following week AND notify an instructor that you wish to get partial credit.

To turn in a project, you must push it to GitHub. You must include a README.md that describes how to run your program.

<hr>

[Up](../README.md)
