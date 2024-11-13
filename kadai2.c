#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

#define STRINGNUM 10000     //データ数

int main(){

    char string[STRINGNUM];
    int alphanum[27]={};       //文字カウント配列 0-25アルファベット, 26スペース, 27改行

    while(fgets(string, STRINGNUM, stdin) !=NULL) {     //入力

        for (int i=0; i< strlen(string); i++) {
            string[i]=toupper(string[i]);
            
            if(isalpha(string[i])){
                alphanum[string[i] - 'A']++;    //文字カウント
            }
            else if (string[i] == ' ') { 
                alphanum[26]++;
            }
            else if (string[i] == '\n') {
                alphanum[27]++;
            }
            else{
                fprintf(stderr, "ERROR %d,\n",string[i]);   //エラー
            }

        }
    }

    for(int i=0;i<=25;i++)
        printf("%d [%c],\n",alphanum[i],'A'+i);     //出力
    printf("%d [SPACE],\n",alphanum[26]);
    printf("%d [ENTER],\n",alphanum[27]);

    return 0;
}