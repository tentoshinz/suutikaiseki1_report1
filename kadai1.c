#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

#define STRINGNUM 10000     //データ数

int main(){

    char string[STRINGNUM];
    while(fgets(string, STRINGNUM, stdin) !=NULL) {     //入力

        for (int i=0; i< strlen(string); i++) {
            if (!isalpha(string[i]) && string[i] != '\n' && string[i] != ' ') {     //文字種判定
                string[i] = ' ';
            }
        }

        printf("%s", string);       //出力
    }

    return 0;
}