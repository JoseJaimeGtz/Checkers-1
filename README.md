# Checkers
## Project information
#### Authors
This game was created by Rodrigo Zamora Dávalos and 
José Jaime Gutierrez Martinez
#### Libraries
The library used to show the game is [RayLib](https://www.raylib.com/)
#### Required dependencies
You need to install cmake 3.18

#### Compile & Run in a IDE (Clion) or Text editor (VS Code)
**Clion**

Open the project folder and click on "Build" icon, to compile the project and click on "Run" icon to run the project.

**VS Code**

```
mkdir build # Create a build directory
cd build && cmake .. # Build from that directory so the build files are in one place
cmake --build . # Build the project
```

## Game information
#### How to play
1. The two players alternate turns and can only move their own pieces.
2. The dark squares are the only ones that may be occupied on the board. The light squares must remain empty.
3. Each turn involves the moving of one piece, which can consist of a piece moving forward to a diagonally adjacent 
square that is unoccupied, or jumping forward over an occupied diagonally adjacent square, provided that the square 
beyond is also empty.
4. If a player jumps over their opponent’s piece, they have successfully captured that piece and it is removed from 
the game.
5. Each piece is initially referred to as a man, but if it reaches the furthest side of the board it becomes a king. 
When this happens, the player stacks an additional piece on top of the original to signify the change.
6. Men may only move forward, but kings can move diagonally forwards as well as backwards.
7. Multiple pieces maybe jumped by both men and kings provided that there are successive unoccupied squares beyond 
each piece that is jumped.
#### How to win
Now that you know the setup and the rules, here are some general strategies on how to win checkers. These strategies 
won’t tell you how to always win at checkers, but they will often times work.
The game is won by either capturing all of your opponent’s pieces, or trapping their pieces disallowing them to make 
any more moves. The majority of strategies involve the first goal, but the latter is sometimes achieved.
1. Don’t be afraid to sacrifice pieces if doing so gives you an advantage.
2. Controlling the centre of the board is advantageous.
3. Maintaining your pieces on the back row of your game board will prevent your opponent from gaining any king pieces.
4. Moving your pieces forward in groups strengthens them.
5. When you’re in the lead during a game, sacrificing one of your own pieces for your opponents is beneficial for you.
6. Focus on gaining as many king pieces as possible.
