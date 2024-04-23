#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* capitalizeTitle(char* title) {
    int len = strlen(title);
    int count = 0;
    for (int i=0; i<=len; i++){ //title[len] = '\0'
        if (title[i]>='A' && title[i]<='Z'){
            title[i] += 32;
        }//不管怎樣先轉小寫
        
        if (title[i]==' ' || title[i]=='\0'){
            if (count > 2){
                title[i-count] -= 32; //把 ' ' 或 '\0' 前的這個單字的第一個字母轉大寫
            }
            count = 0;
            continue;
        }
        else{
            count++;
        }
    }
    return title;
}

int main(){
    char title[] = "i love you";
    printf("%s", capitalizeTitle(title));
    return 0;
}

//compile: gcc 2129.c -o 2129
//execute: ./2129