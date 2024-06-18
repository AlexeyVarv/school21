#include "s21_string.h"
#include <check.h>

START_TEST(test_strlen)
{
    char *testString1 = "Hello";
    ck_assert_int_eq(s21_strlen(testString1), 5);
    char *testString2 = "";
    ck_assert_int_eq(s21_strlen(testString2), 0);
    char *testString3 = "A";
    ck_assert_int_eq(s21_strlen(testString3), 1);
    char *testString4 = "Umbrella corporation!";
    ck_assert_int_eq(s21_strlen(testString4), 21);
    char *testString5 = "Oops\n";
    ck_assert_int_eq(s21_strlen(testString5), 5);
}
END_TEST

START_TEST(test_strchr)
{
    char *testString1 = "Hello";
    char c1 = 'e', c2 = '\0', c3 = 'm', c4 = ' ';
    ck_assert_str_eq(s21_strchr(testString1, c1), strchr(testString1, c1));
    ck_assert_str_eq(s21_strchr(testString1, c2), strchr(testString1, c2));
    ck_assert_ptr_eq(s21_strchr(testString1, c3), strchr(testString1, c3));
    char *testString2 = "";
    ck_assert_ptr_eq(s21_strchr(testString2, c1), strchr(testString2, c1));
    ck_assert_str_eq(s21_strchr(testString2, c2), strchr(testString2, c2));
    char *testString3 = "Umbrella corporation!";
    ck_assert_str_eq(s21_strchr(testString3, c1), strchr(testString3, c1));
    ck_assert_str_eq(s21_strchr(testString3, c2), strchr(testString3, c2));
    ck_assert_ptr_eq(s21_strchr(testString3, c3), strchr(testString3, c3));
    ck_assert_str_eq(s21_strchr(testString3, c4), strchr(testString3, c4));
}
END_TEST

START_TEST(test_strncat)
{
    char testString1_1[20] = "Hello";
    char testString1_2[20] = "Hello";
    char c1[] = " man!", c2[] = "\nOK", c3[] = "", c4[] = "!";
    ck_assert_str_eq(s21_strncat(testString1_1, c1, 4), strncat(testString1_2, c1, 4));
    ck_assert_str_eq(s21_strncat(testString1_1, c2, 5), strncat(testString1_2, c2, 5));
    ck_assert_str_eq(s21_strncat(testString1_1, c3, 1), strncat(testString1_2, c3, 1));
    ck_assert_str_eq(s21_strncat(testString1_1, c4, 0), strncat(testString1_2, c4, 0));
    char testString2_1[10] = "";
    char testString2_2[10] = "";
    ck_assert_str_eq(s21_strncat(testString2_1, c1, 4), strncat(testString2_2, c1, 4));
    ck_assert_str_eq(s21_strncat(testString2_1, c2, 5), strncat(testString2_2, c2, 5));
}
END_TEST

START_TEST(test_strncpy)
{
    char testString1_1[20] = "Hello";
    char testString1_2[20] = "Hello";
    char c1[] = " man!", c2[] = "darling", c3[] = "", c4[] = "!";
    ck_assert_str_eq(s21_strncpy(testString1_1, c1, 3), strncpy(testString1_2, c1, 3));
    ck_assert_str_eq(s21_strncpy(testString1_1, c2, 10), strncpy(testString1_2, c2, 10));
    ck_assert_str_eq(s21_strncpy(testString1_1, c3, 1), strncpy(testString1_2, c3, 1));
    ck_assert_str_eq(s21_strncpy(testString1_1, c4, 1), strncpy(testString1_2, c4, 1));
    char testString2_1[10] = "";
    char testString2_2[10] = "";
    ck_assert_str_eq(s21_strncpy(testString2_1, c1, 4), strncpy(testString2_2, c1, 4));
    ck_assert_str_eq(s21_strncpy(testString2_1, c2, 10), strncpy(testString2_2, c2, 10));
}
END_TEST

START_TEST(test_strncmp)
{
    char *testString1 = "Hello";
    char c1[] = "Hello", c2[] = "darling", c3[] = "", c4[] = "Hello!";
    ck_assert_int_eq(s21_strncmp(testString1, c1, 5), strncmp(testString1, c1, 5));
    ck_assert_int_eq(s21_strncmp(testString1, c2, 5), strncmp(testString1, c2, 5));
    ck_assert_int_eq(s21_strncmp(testString1, c3, 2), strncmp(testString1, c3, 2));
    ck_assert_int_eq(s21_strncmp(testString1, c4, 6), strncmp(testString1, c4, 6));
    char *testString2 = "";
    ck_assert_int_eq(s21_strncmp(testString2, c1, 5), strncmp(testString2, c1, 5));
    ck_assert_int_eq(s21_strncmp(testString2, c2, 5), strncmp(testString2, c2, 5));
    ck_assert_int_eq(s21_strncmp(testString2, c3, 1), strncmp(testString2, c3, 1));
    ck_assert_int_eq(s21_strncmp(testString2, c4, 6), strncmp(testString2, c4, 6));
}
END_TEST

START_TEST(test_sprintf_1)
{
    char testString1[500];
    char testString2[500];
    int a = 2147483647;
    int b = 0;
    char company[] = "Umbrella Corp.";
    char status = 'Z';
    unsigned int salary = 42583;
    double coefficient = .00000000105000;
    unsigned int group = 4294967290;
    void *ptr = &a;
    int testNum = s21_sprintf(testString1, "MAX Code: %-.5ld Age: %.d Employer: %-20s Status: %8c Reward: %-4u Priority: %015g Group %018x Adress %p", a, b, company, status, salary, coefficient, group, ptr);
    int controlNum = sprintf(testString2, "MAX Code: %-.5d Age: %.d Employer: %-20s Status: %8c Reward: %-4u Priority: %015g Group %018x Adress %p", a, b, company, status, salary, coefficient, group, ptr);
    ck_assert_int_eq(testNum, controlNum);
    ck_assert_str_eq(testString1, testString2);
}
END_TEST

START_TEST(test_sprintf_2)
{
    char testString1[500];
    char testString2[500];
    int a = 2147483647;
    float b = 0.159;
    char company[] = "Umbrella Corp.";
    char status = 'Z';
    unsigned int salary = 0;
    float coefficient = 1.000000;
    unsigned int group = 4294967290;
    void *ptr = &a;
    int testNum = s21_sprintf(testString1, "MAX Code: %10.d Age: %.f Employer: %-20s Status: %8c Reward: %.u Priority: %015g Group %#18o Adress %p", a, b, company, status, salary, coefficient, group, ptr);
    int controlNum = sprintf(testString2, "MAX Code: %10.d Age: %.f Employer: %-20s Status: %8c Reward: %.u Priority: %015g Group %#18o Adress %p", a, b, company, status, salary, coefficient, group, ptr);
    ck_assert_int_eq(testNum, controlNum);
    ck_assert_str_eq(testString1, testString2);
}
END_TEST

START_TEST(test_sprintf_3)
{
    char testString1[500];
    char testString2[500];
    int a = 2147483647;
    float b = 15250.159;
    char company[] = "Umbrella Corp.";
    char status = 'Z';
    unsigned int salary = 0;
    float coefficient = 156412.0000015;
    unsigned int group = 4294967290;
    void *ptr = &a;
    int testNum = s21_sprintf(testString1, "MAX Code: %10.d Age: %5.5E Employer: %-20s Status: %8c Reward: %.u Priority: %015.0e Group %o Adress %p", a, b, company, status, salary, coefficient, group, ptr);
    int controlNum = sprintf(testString2, "MAX Code: %10.d Age: %5.5E Employer: %-20s Status: %8c Reward: %.u Priority: %015.0e Group %o Adress %p", a, b, company, status, salary, coefficient, group, ptr);
    ck_assert_int_eq(testNum, controlNum);
    ck_assert_str_eq(testString1, testString2);
}
END_TEST

START_TEST(test_sprintf_4)
{
    char testString1[500];
    char testString2[500];
    int a = 2147483647;
    float b = 15250.159;
    char company[] = "Umbrella Corp.";
    char status = 'Z';
    unsigned int salary = 0;
    float coefficient = 156412.0000015;
    unsigned int group = 4294967290;
    void *ptr = &a;
    int testNum = s21_sprintf(testString1, "MAX Code: %+10.d Age: % 5.5E Employer: %-20s Status: %8c Reward: %.u Priority: %015.0e Group %0X Adress %p", a, b, company, status, salary, coefficient, group, ptr);
    int controlNum = sprintf(testString2, "MAX Code: %+10.d Age: % 5.5E Employer: %-20s Status: %8c Reward: %.u Priority: %015.0e Group %0X Adress %p", a, b, company, status, salary, coefficient, group, ptr);
    ck_assert_int_eq(testNum, controlNum);
    ck_assert_str_eq(testString1, testString2);
}
END_TEST

START_TEST(test_sprintf_5)
{
    char testString1[500];
    char testString2[500];
    int a = -2147483;
    float b = 15250.00000;
    char company[] = "Umbrella Corp.";
    char status = 'Z';
    unsigned int salary = 0;
    float coefficient = 156412.0000015;
    unsigned int group = 4294967290;
    void *ptr = &a;
    int testNum = s21_sprintf(testString1, "MAX Code: %d Age: % 5.5G Employer: %.6s Status: %8c Reward: %.u Priority: %015.0e Group %X Adress %p", a, b, company, status, salary, coefficient, group, ptr);
    int controlNum = sprintf(testString2, "MAX Code: %d Age: % 5.5G Employer: %.6s Status: %8c Reward: %.u Priority: %015.0e Group %X Adress %p", a, b, company, status, salary, coefficient, group, ptr);
    ck_assert_str_eq(testString1, testString2);

    ck_assert_int_eq(testNum, controlNum);
    //ck_assert_str_eq(testString1, testString2);
}
END_TEST

START_TEST(test_sprintf_6)
{
    char testString1[500];
    char testString2[500];
    int a = -2147483;
    float b = 15250.00000;
    char company[] = "Umbrella Corp.";
    char status = 'Z';
    unsigned int salary = 0;
    float coefficient = 156412.0000015;
    unsigned int group = 4294967290;
    void *ptr = &a;
    int testNum = s21_sprintf(testString1, "MAX %% Code: %d Age: % 5.5G Employer: %.6s Status: %8c Reward: %.u Priority: %015.0e Group %X Adress %p", a, b, company, status, salary, coefficient, group, ptr);
    int controlNum = sprintf(testString2, "MAX %% Code: %d Age: % 5.5G Employer: %.6s Status: %8c Reward: %.u Priority: %015.0e Group %X Adress %p", a, b, company, status, salary, coefficient, group, ptr);
    ck_assert_str_eq(testString1, testString2);

    ck_assert_int_eq(testNum, controlNum);
    //ck_assert_str_eq(testString1, testString2);
}
END_TEST


Suite *example_suite_create(void)
{
    Suite *suite = suite_create("MyStrings&Sscanf");
    // Набор разбивается на группы тестов, разделённых по каким-либо критериям.
    TCase *tcase_core_strings = tcase_create("Core of strings");
    TCase *tcase_core_sscanf = tcase_create("Core of sscanf");
    TCase *tcase_core_sprintf = tcase_create("Core of sprintf");
    // Добавление теста в группу тестов.
    tcase_add_test(tcase_core_strings, test_strlen);
    tcase_add_test(tcase_core_strings, test_strchr);
    tcase_add_test(tcase_core_strings, test_strncat);
    tcase_add_test(tcase_core_strings, test_strncpy);
    tcase_add_test(tcase_core_strings, test_strncmp);

    tcase_add_test(tcase_core_sprintf, test_sprintf_1);
    tcase_add_test(tcase_core_sprintf, test_sprintf_2);
    tcase_add_test(tcase_core_sprintf, test_sprintf_3);
    tcase_add_test(tcase_core_sprintf, test_sprintf_4);
    tcase_add_test(tcase_core_sprintf, test_sprintf_5);
    tcase_add_test(tcase_core_sprintf, test_sprintf_6);
    // Добавление теста в тестовый набор.
    suite_add_tcase(suite, tcase_core_strings);
    suite_add_tcase(suite, tcase_core_sscanf);
    suite_add_tcase(suite, tcase_core_sprintf);

    return suite;
}


int main() {
    Suite *suite = example_suite_create();
    SRunner *suite_runner = srunner_create(suite);
    
    srunner_run_all(suite_runner, CK_NORMAL);
    // Получаем количество проваленных тестов.
    int failed_count = srunner_ntests_failed(suite_runner);
    srunner_free(suite_runner);
    
    if (failed_count != 0) {
        // Сигнализируем о том, что тестирование прошло неудачно.
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}