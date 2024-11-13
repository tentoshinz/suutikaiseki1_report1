#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

#define STRINGNUM 1000000     //データ数
#define STRINGNUMTEMP 10000
#define RESULTNUM 1000 

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


    //第三近似のランダムな文字列
    srand((unsigned int)time(NULL));
    int k= rand()% M;       
    int ktmp;       //見つからない時用

    stringresult[0]=string[k];              //第3近似のランダムな文字列
    char A= string[k+1];           
    char B= string[k+2];
    stringresult[1]=A;
    stringresult[2]=B;

    for(int i=3;i<RESULTNUM-1;i++){

        k= rand()% M-2;       
        ktmp=k;         //見つからない時用

        while( !(string[k]== A && string[k+1]== B) || ktmp==k-1){       
            if(k>=M-2)
                k=0;
            else
                k++;
        }

        A=B;
        B= string[k+2];         
        stringresult[i]=B;
    }

    printf("%s",stringresult);

    return 0;
}