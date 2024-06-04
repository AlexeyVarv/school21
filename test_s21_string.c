#include "s21_string.h"
#include <check.h>

START_TEST(test_strlen)
{
  /* Исходный код теста. */
    char *testString = "Hello";
    ck_assert_int_eq(s21_strlen(testString), 5);
}
END_TEST

START_TEST(test_strchr)
{
  /* Исходный код теста. */
    char *testString = "Hello";
    char *reference;
    char *testResult;
    char c = 'e';
    reference = strchr(testString, c);
    testResult = s21_strchr(testString, c);
      
    ck_assert_int_eq(strcmp(testResult, reference), 0);
}
END_TEST

Suite *example_suite_create(void)
{
    Suite *suite = suite_create("Example");
    // Набор разбивается на группы тестов, разделённых по каким-либо критериям.
    TCase *tcase_core = tcase_create("Core of example");
    
    // Добавление теста в группу тестов.
    tcase_add_test(tcase_core, test_strlen);
    tcase_add_test(tcase_core, test_strchr);
    
    // Добавление теста в тестовый набор.
    suite_add_tcase(suite, tcase_core);
    
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