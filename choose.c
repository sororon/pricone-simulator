#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "character.h"

void choose(size_t t)
{
    int* n = (int*)malloc(sizeof(int));
    char* buf = (char*)malloc(sizeof(4)); // 選べるキャラクターは二桁になる予定
    char* input = (char*)malloc(sizeof(4)); // 選べるキャラクターは二桁になる予定
    int count = 0;

    for (size_t i = 0; i < t; i++){
        count++;
        do {
            printf("《%d人目のキャラクターを選んでください》\n1.ぺコリーヌ\n2.コッコロ\n3.キャル\n->", count);
            scanf("%s", input);
            strncpy(buf, input, sizeof(buf+1));
            if (buf[sizeof(buf)-1] == '\0'){
                *n = atoi(buf);
            } else {
                *n = -1;
            }
        } while (*n != 1 && *n != 2 && *n != 3);

        switch (*n){
        case 1:
            character(&pecorine, 1);
            printf("%s HP:%d 物理攻撃:%d 魔法攻撃:%d 物理防御:%d 魔法防御:%d\n", pecorine.name, pecorine.hp, pecorine.phy_at, pecorine.mag_at, pecorine.phy_df, pecorine.mag_df);
            break;
        case 2:
            character(&kokkoro, 2);
            printf("%s HP:%d 物理攻撃:%d 魔法攻撃:%d 物理防御:%d 魔法防御:%d\n", kokkoro.name, kokkoro.hp, kokkoro.phy_at, kokkoro.mag_at, kokkoro.phy_df, kokkoro.mag_df);
            break;
        case 3:
            character(&kyaru, 3);
            printf("%s HP:%d 物理攻撃:%d 魔法攻撃:%d 物理防御:%d 魔法防御:%d\n", kyaru.name, kyaru.hp, kyaru.phy_at, kyaru.mag_at, kyaru.phy_df, kokkoro.mag_df);
            break;
        }
    }

    free(n);
    free(buf);
    free(input);
}
