#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "character.h"

#define DEBUG 0 /* デバッグ設定(1:有効, 0:無効) */

static FILE* fp;
static char buf[5][100]; // 行/列

void character(Character* p, const size_t n)
{
    fp = fopen("character_data.csv", "r");
    if(!fp) {
        perror("fopen\n");
        exit(1);
    }
    // pのデータの行まで読み飛ばす
    for (size_t i = 0; i < n; i++){
        fscanf(fp, "%[^,],%[^,],%[^,],%[^,],%[^,],%s", buf[0], buf[1], buf[2], buf[3], buf[4], buf[5]);
         #if DEBUG
         printf("skip%ld:%s %s %s %s %s %s\n",i+1, buf[0], buf[1], buf[2], buf[3], buf[4], buf[5]);
         #endif
    }

    fscanf(fp, "%[^,],%d,%d,%d,%d,%d", p->name, &p->hp, &p->phy_at, &p->mag_at, &p->phy_df, &p->mag_df);
     #if DEBUG
     printf("data:%s %d %d %d %d %d\n", p->name, p->hp, p->phy_at, p->mag_at, p->phy_df, p->mag_df);
     #endif

    //memset(buf, '\0', sizeof(buf));
    fclose(fp);
}

// character()のデバッグ用。コンパイル名はデフォルト（a.out、-oオプションを付けない）。
// gcc -Wall -g character.c

/* int main(){
    character(&pecorine, 1);
    character(&kyaru, 3);
    character(&kokkoro, 2); //kokkoroを一回目、二回目に渡すとprintfでkokkoro.nameが表示されない。character内でprintfすると表示される（参照先をprintfしているから？）。
    character(&rei, 5);
    character(&hiyori, 6);
    character(&yui, 4); //yuiもkokkoroと同じ現象。rei,hiyoriのところで呼び出すとyui.nameが表示されない。

     #if DEBUG
     printf("%s:pec%d\n", pecorine.name, pecorine.hp);
     printf("%s:kok%d\n", kokkoro.name, kokkoro.hp);
     printf("%s:kya%d\n", kyaru.name, kyaru.hp);
     printf("%s:yui%d\n", yui.name, yui.hp);
     printf("%s:rei%d\n", rei.name, rei.hp);
     printf("%s:hiy%d\n", hiyori.name, hiyori.hp);
     #endif

    return 0;
}
 */
