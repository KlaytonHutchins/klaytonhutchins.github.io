---
layout: default
title: JS Racer
---

### Application Overview
It's time to dip a toe into the world of games. Albeit a very tiny toe.  

You are going to build a simple racing game that moves some "cars" (colored divs) across the screen. It'll even be a multi-player game as each player will be able to hit their own key to make their div move.

### Release 1 - Listen for keydown
1. Create an HTML file with two `div` elements. Give them `id`s of 'car1', 'car2' respectively.
1. Use CSS to make one of them blue and the other red, and both of them `50px` by `50px`. You can use a style sheet for this as opposed to using JavaScript.
1. Add a `keydown` event listener.
   * For now just print a message to the console when a key is pressed.

1. Create a function which checks which key was pressed. If the `p` key was pressed move the blue car, and if the `q` key was pressed move the red car.
   * For the time being, just print "blue" or "red" depending on which key was pressed.

### Release 2 - Move the cars
1. Create a function named `moveCar`. Pass this function the `HTMLElement` of the `div` that corresponds to the key that was pressed and the event from the key press.
1. Use the marginLeft style property to "move" the corresponding `div` across the screen when its key is pressed. If the left-margin is increasing it will appear that that div is gliding across the screen.
1. Inside of your `moveCar` function each time the marginLeft property is increased check to see if it is equivalent to the browser window's width. `window.innerWidth` returns the current width of the screen in `px`. When one of the divs reaches this value, it is the winner. Print out a message to the console notifying you which div won.

### Release 3 - Make it better
1. Replace the colored `div`s with actual images of cars (or horses, dragons, what have you).
1. Add additional logic to the keydown so that the red car moves on alternating `q` and `w` keys, and the blue car moves on alternating `o` and `p` keys. If the user does not alternate, the car should not move (remove the event listeners).
1. When a user wins the race, clear the screen and display a message or image notifying the players who won the race.
1. Do anything else you can think of to spruce up this relatively simple game. Maybe add some more players/key events, a finish line, background image, etc.

<hr>

[Up](README.md)

