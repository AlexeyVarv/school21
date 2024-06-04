#include "s21_string.h"

START_TEST(test_strlen)
{
  /* Исходный код теста. */
    char *testString = "Hello";
    ck_assert_int_eq(s21_strlen(testString), 5);
}
END_TEST

Suite *example_suite_create(void)
{
    Suite *suite = suite_create("Example");
    // Набор разбивается на группы тестов, разделённых по каким-либо критериям.
    TCase *tcase_core = tcase_create("Core of example");
    
    // Добавление теста в группу тестов.
    tcase_add_test(tcase_core, test_strlen);
    
    // Добавление теста в тестовый набор.
    suite_add_tcase(suite, tcase_core);
    
    return suite;
}


int main() {
    /*char *testString = "Hello";
    if (s21_strlen(testString) == 5) {
        printf("TEST SUCSESS\n");
    } else {
        printf("TEST FAIL\n");
    }*/


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

    return 0;
}