#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

#define STRINGNUM 100000     //データ数
#define RESULTNUM 0     //最小の表示する結果

int main(){

    char string[STRINGNUM];

    int alphanum[28]={};       //文字カウント配列 0-25アルファベット, 26スペース, 27改行
    int pair2[28][28]={};
    int moji;

    int alphacheck(char str){        //アルファベットと空白改行を識別する関数

        if(isalpha(str))
            moji=str - 'A';
        else if (str == ' ') 
            moji=26;
        else if (str == '\n') 
            moji=27;
        else
            moji=-1;

        return moji;
    }


    int first,second;

    while(fgets(string, STRINGNUM, stdin) !=NULL) {     //入力

        for (int i=0; i< strlen(string); i++)       //大文字固定
            string[i]=toupper(string[i]);

        for (int i=0; i< strlen(string)-1; i++) {   //文字カウント
            
            first = alphacheck(string[i]);
            second = alphacheck(string[i+1]);

            if(first!=-1 && second!=-1){
                pair2[first][second]++;
            }

        }
    }


    char moji1,moji2;

    for (int i = 0; i <= 27; i++) {         //出力
        if(i<=25) moji1= 'A'+i;
        else if(i==26) moji1= '_';
        else if(i==27) moji1= '@';

        for (int j = 0; j <= 27; j++) {
            if(j<=25) moji2= 'A'+j;
            else if(j==26) moji2= '_';
            else if(j==27) moji2= '@';

            if (pair2[i][j] >= RESULTNUM) {
                printf("%d [%c%c],\n", pair2[i][j], moji1, moji2);
            }
        }
    }

    return 0;
}