#include "s21_string.h"


int main() {
    char testString[100] = "Hello";
    if (s21_strlen(testString) == 5) {
        printf("TEST STRLEN SUCSESS\n");
    } else {
        printf("TEST STRLEN FAIL\n");
    }

    int c = '\0';

    printf("%p\n", strchr(testString, c));
    printf("%s\n", strchr(testString, c));
    printf("%p\n", s21_strchr(testString, c));
    printf("%s\n", s21_strchr(testString, c));
    
    if (strchr(testString, c) == s21_strchr(testString, c)) {
        printf("TEST STRCHR SUCSESS\n");
    } else {
        printf("TEST STRCHR FAIL\n");
    }

    char *testString2 = "Hell";
    printf("%d\n", s21_strncmp(testString, testString2, 4));
    
    printf("%s\n", strncat(testString, testString2, 0));
    
    printf("%s\n", s21_strncat(testString, testString2, 10));

    return 0;
}