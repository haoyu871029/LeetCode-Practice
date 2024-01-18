#include <stdio.h>
#include <string.h>

void reverse(int start, int end, char* s){
    int m = end-start;
    for (int i=0; i<=m/2; i++){
        char tmp = s[start+i];
        s[start+i] = s[end-i];
        s[end-i] = tmp;
    }
}
char* reverseWords(char* s) {
    int n = strlen(s);
    int p = 0;
    for (int i=0; i<n; i++){
        if (s[i] == ' '){
            reverse(p, i-1, s);
            p = i+1;
        }
    }
    reverse(p, n-1, s);
    return s;
}
int main(){
    char s[] = "Let's take LeetCode contest";
    printf("%s\n", reverseWords(s));
    return 0;
}

//compile: gcc 557.c -o 557
//execute: ./557
