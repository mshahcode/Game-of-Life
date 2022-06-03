/**
 * @file CellList.h
 * @author Mikayil Shahtakhtinski
 * @author Arif Ahmadli
 * @brief CellList file 
 * @version 1
 * @date 2022-06-03
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef __CELLLIST_H__
#define __CELLLIST_H__


#define MAXSIZE 128

#include <stdio.h>
#include <stdlib.h>
#include "Cell.h"

typedef struct CellList
{
    int row;
    int col;
    Cell board1[MAXSIZE][MAXSIZE];
    Cell board2[MAXSIZE][MAXSIZE];
} CellList;


/**
 * @brief Creates a new CellList with specified row and column
 * 
 * @param row Overall row (size)
 * @param col Overall col (size)
 * @return CellList* A new CellList
 */

CellList* CL_newCellList(int row,int col);

/**
 * @brief Initializes each board of CellList
 * 
 * @param cl Address to List
 */

void CL_initialize(CellList* cl);

/**
 * @brief Randomly fills with either dead or alive cells to the board 1
 * 
 * @param cl Address to List
 */

void CL_FillRandomCellList(CellList* cl);

/**
 * @brief Prints the List in the console
 * 
 * @param cl List Address
 */


void CL_show(CellList* cl);

#endif