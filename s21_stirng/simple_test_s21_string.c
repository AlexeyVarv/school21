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

    char *testString2 = "Goot Morgen";
    printf("%d\n", s21_strncmp(testString, testString2, 4));
    printf("%d\n", strncmp(testString, testString2, 4));


    char testString1_1[20] = "Hello";
    
    char c1[] = " man!", c2[] = "OK", c3[] = "", c4[] = "!";
    printf("%s\n", s21_strncat(testString1_1, c1, 4));
    
    printf("%s\n", s21_strncat(testString1_1, c2, 5));
    
    printf("%s\n", s21_strncat(testString1_1, c3, 5));
    printf("%s\n", strncat(testString1_1, c3, 5));
    printf("%s\n", s21_strncat(testString1_1, c4, 0));
    printf("%s\n", strncat(testString1_1, c4, 0));
    //printf("%s\n", strncpy(testString, testString2, 2));
    
    //printf("%s\n", s21_strncpy(testString, testString2, 0));



    return 0;
}