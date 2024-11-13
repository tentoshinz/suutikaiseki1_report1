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
    int pair3[28][28][28]={};
    int moji;
    int temp=0;

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


    int first,second,third;

    while(fgets(string, STRINGNUM, stdin) !=NULL) {     //入力

        for (int i=0; i< strlen(string); i++)       //大文字固定
            string[i]=toupper(string[i]);

        for (int i=0; i< strlen(string)-1; i++) {   //文字カウント
            
            first = alphacheck(string[i]);
            second = alphacheck(string[i+1]);
            third = alphacheck(string[i+2]);

            if(first!=-1 && second!=-1 && third!=-1){
                pair3[first][second][third]++;
            }

        }
    }


    char moji1,moji2,moji3;

    for (int i = 0; i <= 27; i++) {      //出力
        if(i<=25) moji1= 'A'+i;
        else if(i==26) moji1= '_';
        else if(i==27) moji1= '@';

        for (int j = 0; j <= 27; j++) {
            if(j<=25) moji2= 'A'+j;
            else if(j==26) moji2= '_';
            else if(j==27) moji2= '@';

            for (int k = 0; k <= 27; k++) {
                if(k<=25) moji3= 'A'+k;
                else if(k==26) moji3= '_';
                else if(k==27) moji3= '@';

                if (pair3[i][j][k] >= RESULTNUM) {
                    printf("%d [%c%c%c],\n", pair3[i][j][k], moji1, moji2, moji3);
                }
            }
        }
    }

    return 0;
}