//
//  Ex1_Task4.c
//  Infor2_Exercise
//
//  Created by 谭特 on 17/2/25.
//  Copyright © 2017年 谭特. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#define MAX 256

int compare(char a, char b) {
    if(tolower(a) == tolower(b)) {
        return a-b;
    } else {
        return tolower(a) < tolower(b)? -1:1;
    }
}

void exchange(char *a, char *b) {
    char c = *a;
    *a = *b;
    *b = c;
}

void selection_sort(char s[], int n) {
    for(int i=0; i <= n-1; i++){
        int k = i;
        for(int j=i+1; j <= n-1; j++) {
            if(compare(s[k], s[j]) > 0) {
                k = j;
            }
        }
        exchange(&s[i], &s[k]);
    }
}

int main() {
    char str[MAX];
    printf("Input a string here: ");
    scanf("%s", str);
    printf("The input string is: %s\n", str);
    selection_sort(str, strlen(str));
    printf("The sorted string is: %s\n", str);
    return 0;
}