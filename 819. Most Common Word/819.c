#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h> //support strtok(), strcmp()
#include <ctype.h> //support tolower()

char* mostCommonWord(char* paragraph, char** banned, int bannedSize){
    int word_num = 0;
    char** word_record_list = NULL;
    int* freq = NULL;
    const char sep[7] = {'!', '?', ',', ';', '.', ' ', '\''};
    bool match = false;

    /* converting the string to lower case */
    int i = 0;
    while(paragraph[i]){
        paragraph[i] = tolower(paragraph[i]);      
        i++;
    }

    char* token = strtok(paragraph, sep);
    while (token != NULL){
        /* Check if token is banned */
        for (int i=0; i<bannedSize; i++){
            if (!strcmp(token, banned[i])){
            //token is banned
                goto banned;
            } 
        }
        //token is not banned

        /* Check if token is recorded */
        for (int i=0; i<word_num; i++){
            if (!strcmp(token, word_record_list[i])){ 
            //token is already in word_record_list
                match = true;
                freq[i] += 1 ;
                break;
            }
        }
        if (!match){
        //token is not recorded yet
            word_num++;
            word_record_list = realloc(word_record_list, word_num*sizeof(char*));
            freq = realloc(freq, word_num*sizeof(int));
            word_record_list[word_num-1] = token;
            freq[word_num-1] = 1;
        }
        
        banned:
            match = false;
            token = strtok(NULL, sep);
    }

    int max_freq = 0;
    int index = 0;
    for(int i=0; i<word_num; i++){   
        //printf("%s: %d\r\n",word_record_list[i],freq[i]);  
        if(freq[i] > max_freq){
            index = i;
            max_freq = freq[i];
        }
    }
    return word_record_list[index];
}
int main(){
    char paragraph[] = "Bob hit a ball, the hit BALL flew far after it was hit.";
    char* banned[] = {"hit"};
    int bannedSize = 1;
    char* result = mostCommonWord(paragraph, banned, bannedSize);
    printf("%s\r\n", result);
    return 0;
}
// compile: gcc 819.c -o 819
// execute: ./819