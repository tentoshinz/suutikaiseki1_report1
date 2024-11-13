#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

#define STRINGNUM 10000     //1行のデータ数
#define STRINGNUMTEMP 100000     //すべてのデータ数
#define RESULTNUM 1000           //結果の数

int main(){

    char string[STRINGNUM];
    char stringtmp[STRINGNUMTEMP];
    char stringresult[RESULTNUM];    

    int M=0;

    while(fgets(stringtmp, STRINGNUMTEMP, stdin) !=NULL) {     //入力
        for (int i=0; i< strlen(stringtmp) && M< STRINGNUM; i++){
            string[M]=toupper(stringtmp[i]);
            M++;
        }
    }
    string[M]='\0';

    int k;
    srand((unsigned int)time(NULL));

    for(int i=0;i<RESULTNUM;i++){   //ランダムな文字列
        k= rand()% M;
        stringresult[i]=string[k];
    }

    printf("%s",stringresult);  //結果  

    return 0;
}