#include <stdlib.h>
#include <stdio.h>
#include "raylib.h"
#include "game.h"

/* Una letra 'a' por cada vez que quise dar de baja la materia de programación (rodri)
aaaaaaaaaaaaaaaaaaaaaaaaa
*/
/* Una letra 'a' por cada vez que quise dar de baja la materia de programación (jaime)
aaaaaaaaaaaaaaaaaaaaaa
*/

int main()
{   
    struct gameStruct game;
    createBoard(&game);
    createWindow(&game);
    return 0;
} 
