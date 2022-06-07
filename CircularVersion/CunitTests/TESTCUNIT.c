#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include <stdlib.h>
#include <math.h>
#include "../game/CellList.h"

/**
 * @brief Check if dinamic allocation fails
 * 
 */

void testFunc1()
{
    Cell* c = C_newCell(0,0,1);
    CU_ASSERT_NOT_EQUAL(c,NULL);
}

/**
 * @brief Check if dinamic allocation fails
 * 
 */

void testFunc2()
{
    CellList* cl = CL_newCellList(10,10);
    CU_ASSERT_NOT_EQUAL(cl,NULL);
}

/**
 * @brief Check if row 0 col 0 belongs to boards
 * 
 */

void testFunc3()
{
    CellList* cl = CL_newCellList(10,10);
    CU_ASSERT_TRUE(CL_belong(0,0,cl));
}

/**
 * @brief Check if size of neighbours greater than 0 (must be)
 * 
 */

void testFunc4()
{
    CellList* cl = CL_newCellList(10,10);
    Cell neighbours[8];
    int size = CL_neighbours(5,5,neighbours,cl);
    CU_ASSERT_NOT_EQUAL(size,0);

}



int main()
{
    CU_initialize_registry();

    /// first suite for cell codes
    CU_pSuite suite1 = CU_add_suite("Cell code", NULL, NULL);
    CU_pTest t1 = CU_add_test(suite1, "my_test1", testFunc1);

    /// second suite for cellList code
    CU_pSuite suite2 = CU_add_suite("CellList code", NULL, NULL);
    CU_pTest t2 = CU_add_test(suite2, "my_test2", testFunc2);
    CU_pTest t3 = CU_add_test(suite2, "my_test3", testFunc3);
    CU_pTest t4 = CU_add_test(suite2, "my_test4", testFunc4);


    if (CU_get_error() != CUE_SUCCESS)
        exit(1);
    CU_basic_run_tests();
    int nb =  CU_get_number_of_failures();
    return nb;

}