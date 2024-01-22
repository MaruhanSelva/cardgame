# Cardgame!

A Hearthstone-like game made in C++ using object-oriented programming principles.

## Overview

This project aims to create a card game similar to the online game Hearthstone in which two players face each other using Monsters, Spells, and Enhancements. This game is run using the terminal and supports writing actions and running files that will simulate the first part of a game. 

<img width="1191" alt="image" src="https://github.com/MaruhanSelva/cardgame/assets/75972624/970071c5-db2c-4749-a926-75437b61e100">

## The structure

This project is composed using the principles of object-oriented programming. Specifically, using the following design patterns: Visitor Pattern, Decorator Pattern, Factory Method Pattern, and Template Method Pattern. 

The main class in this project is the Card class. This class serves the purpose of being the base class for all other cards in the game. i.e. all other card classes inherit properties from this class. Each card (and its descendants) share the same methods and properties, aside from those specific to the individual card class. Each of its children: Monster, Spell, and Enhancement classes are template classes from which specific cards inherit. For example, the Red Monster inherits from the Monster class where only their card-specific ability is changed (and its stats like ATK and DEF).


## Future Improvements:
* Update all current vectors to smart pointer vectors to better manage memory
* Implement a Visual Interface
* Add more interesting (and complex) cards to the game


