Hand Eye Coordination Game

This is a game that tests the hand-eye coordination of two opponents. Each player has a joystick, button, and an 8x8 LED matrix. The objective of each player is to move their joystick cursor to the randomly lit cell on the LED matrix and press the button to score a point. The player with the most points scored at the end of the round wins.

The game has three subsystems:

Game boards: Two Arduino boards and their respective I/O devices act as the player's game boards.
Logic board: One Arduino board and its respective I/O devices handle the game logic, scorekeeping, and all other necessary information to make the game run correctly.
Serial communication: Two Arduino boards communicate with each other using SoftwareSerial library to exchange the player's name and turn on LEDs on their respective boards.
