#include <stdio.h>
#include <stdlib.h>
#include "character.h"

#define DEBUG 1 /* デバッグ設定(1:有効, 0:無効) */

static FILE* fp;
static int ret;
static char buf[5][100];

void data_copy(Character* p, const size_t n)
{
    // 最初の一行は読み飛ばす
    if(n == 1) fscanf(fp, "%[^,],%[^,],%[^,],%[^,],%[^,],%s", buf[0], buf[1], buf[2], buf[3], buf[4], buf[5]);
     #if DEBUG
     printf("skip:%s %s %s %s %s %s\n",buf[0], buf[1], buf[2], buf[3], buf[4], buf[5]);
     #endif
    
    while ((ret = fscanf(fp, "%[^,],%d,%d,%d,%d,%d", p->name, &p->hp, &p->phy_at, &p->mag_at, &p->phy_df, &p->mag_df)) == n){}
    ret = 0;
}

void character()
{
    fp = fopen("character_data.csv", "r");
    if(!fp) {
        perror("fopen\n");
        exit(1);
    }

    data_copy(&pecorine, 1);
    data_copy(&kokkoro, 2);
    data_copy(&kyaru, 3);

    printf("%s:pec%d\n", pecorine.name, pecorine.hp);
    printf("%s:kok%d\n", kokkoro.name, kokkoro.hp);
    printf("%s:kya%d\n", kyaru.name, kyaru.hp);

    fclose(fp);
}

int main(){
    character();
    return 0;
}
