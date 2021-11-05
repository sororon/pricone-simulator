#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "quest.h"
#include "arena.h"

void mode()
{
    int* n = (int*)malloc(sizeof(int));
    char* buf = (char*)malloc(sizeof(2)); // 入力は一桁なので
    char* input = (char*)malloc(sizeof(2)); // 入力は一桁なので

    do {
        printf("《モードを選んでください》\n1.クエスト\n2.アリーナ\n3.クラン（未実装）\n4.ガチャ（未実装）\n->");
        scanf("%s", input);
        strncpy(buf, input, sizeof(buf+1));
        if (buf[sizeof(buf)-1] == '\0'){
            *n = atoi(buf);
        } else {
            *n = -1;
        }
    } while (*n != 1 && *n != 2 && *n != 3 && *n != 4);

    free(buf);
    free(input);

    switch (*n){
    case 1:
        free(n);
        quest();
        break;
    case 2:
        free(n);
        arena();
        break;
    case 3:
        free(n);
        printf("実装待ち！\n");
        break;
    case 4:
        free(n);
        printf("実装待ち！\n");
        break;
    }
}
