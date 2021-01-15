#include "CUnit/CUnit.h"
#include "CUnit/Basic.h"

#include "main.h"

#include <stdio.h>

int init_suite(void) { return 0; }
int clean_suite(void) { return 0; }

// test arg
void CSC_test_1(void)
{
    //CU_ASSERT_EQUAL(CSC(11, arg), 2);
}

int main(void)
{
    CU_pSuite pSuite = NULL;

    /* initialize the CUnit test registry */
    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();

    /* add a suite to the registry */
    pSuite = CU_add_suite("max_test_suite", init_suite, clean_suite);
    if (NULL == pSuite)
    {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* add the tests to the suite */
    if ((NULL == CU_add_test(pSuite, "CSC_test_1", CSC_test_1)) ||
        (NULL == CU_add_test(pSuite, "propage_message_test", propage_message_test)))
    {
        CU_cleanup_registry();
        return CU_get_error();
    }

    // Run all tests using the basic interface
    /*
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_basic_run_suite(pSuite);
    printf("\n");
    CU_basic_show_failures(CU_get_failure_list());
    printf("\n\n");
    */
   CU_automated_run_tests();
}