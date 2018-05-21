Filler Project

Project Overview
Filler is 42 projects to learn about AI. The goal is that the last player put a piece that can have any size and shape sent by the virtual machine. To place a piece, he needs to cross the player's ONE cell and only ONE, and not overlap any of the competing cells.

Strategy
The strategy is to check the relative position in comparison with the applicant.
Then close enough from the opponent, surrounding it, keeping a sufficient distance.


Installation
$> make

Usage
./filler_vm -f MAP -p1 ./P1_NAME -p2 P2_NAME -v
We can add -q to prevent display in the terminal

Example:
$> ./filler_vm -f maps/map01 -p1 ./vgryshch.filler -p2 players/hcao.filler -v -q

Add animation
./filler_vm -f maps/map01 -p1 ./vgryshch.filler -p2 players/hcao.filler -v -q | ./bonus/visualization.c
