#include "s21_string.h"


int main() {
    char testString[] = "Hello";
    if (s21_strlen(testString) == 5) {
        printf("TEST STRLEN SUCSESS\n");
    } else {
        printf("TEST STRLEN FAIL\n");
    }

    char *reference;
    reference = strchr(testString, 'e');
    printf("%s\n", reference);
    char *testResult;
    testResult = s21_strchr_2(testString, 'e');
    printf("%s\n", testResult);
    
    if (!strcmp(testResult, reference)) {
        printf("TEST STRCHR SUCSESS\n");
    } else {
        printf("TEST STRCHR FAIL\n");
    }

    return 0;
}