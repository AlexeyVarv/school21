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

Suite *example_suite_create(void)
{
    Suite *suite = suite_create("MyStrings&Sscanf");
    // Набор разбивается на группы тестов, разделённых по каким-либо критериям.
    TCase *tcase_core_strings = tcase_create("Core of strings");
    TCase *tcase_core_sscanf = tcase_create("Core of sscanf");
    // Добавление теста в группу тестов.
    tcase_add_test(tcase_core_strings, test_strlen);
    tcase_add_test(tcase_core_strings, test_strchr);
    tcase_add_test(tcase_core_strings, test_strncat);
    tcase_add_test(tcase_core_strings, test_strncpy);
    tcase_add_test(tcase_core_strings, test_strncmp);

    // Добавление теста в тестовый набор.
    suite_add_tcase(suite, tcase_core_strings);
    suite_add_tcase(suite, tcase_core_sscanf);
    
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