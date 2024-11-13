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


    //第二近似のランダムな文字列
    srand((unsigned int)time(NULL));
    int k= rand()% M;       
    int ktmp;   //見つからない時用

    stringresult[0]=string[k];              
    char A= string[k+1];           
    stringresult[1]=A;

    for(int i=2;i<RESULTNUM-1;i++){

        k= rand()% M-1;      
        ktmp=k;     //見つからない時用
        
        while(string[k]!= A || ktmp==k-1){       
            if(k>=M-1)
                k=0;
            else
                k++;
        }

        A= string[k+1];         
        stringresult[i]=A;
    }

    printf("%s",stringresult);

    return 0;
}