#include "s21_string.h"


int main() {
    char *testString = "Hello";
    if (s21_strlen(testString) == 5) {
        printf("TEST STRLEN SUCSESS\n");
    } else {
        printf("TEST STRLEN FAIL\n");
    }

    char *reference;
    reference = strchr(testString, 'c');
    if (reference) {
        printf("%s\n", reference);
    } else {
        printf("NULL\n");
    }
    
    char *testResult;
    testResult = s21_strchr(testString, 'c');
    if (testResult) {
        printf("%s\n", testResult);
    } else {
        printf("NULL\n");
    }
    
    if (!strcmp(testResult, reference)) {
        printf("TEST STRCHR SUCSESS\n");
    } else {
        printf("TEST STRCHR FAIL\n");
    }

    return 0;
}