#include <stdlib.h>
#include <stdio.h>
#include "raylib.h"
#include "game.h"

/* Una letra 'a' por cada vez que quise dar de baja la materia de programación (rodri)
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
*/
/* Una letra 'a' por cada vez que quise dar de baja la materia de programación (jaime)
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
*/

int main()
{   
    struct gameStruct game;
    initGame(&game);
    createBoard(&game);
    drawMain(&game);
    return 0;
} 
