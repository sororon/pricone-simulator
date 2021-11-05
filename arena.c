#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "character.h"
#include "choose.h"
#include "arena.h"

void re(ArenaCharacter* c)
{
    
}

void arena()
{
    printf("［アリーナモード］\n");

    for (size_t i = 0; i < 3; i++){
        choose(3);
    }
    

    printf("キャラクター選択完了");

}
