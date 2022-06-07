/**
 * @file CellList.h
 * @author Mikayil Shahtakhtinski
 * @author Arif Ahmadli
 * @brief CellList file 
 * @version 3
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


/**
 * @brief Assign neighbours of cell in specified row and column to neighbours list
 * 
 * @param row 
 * @param col 
 * @param neighbours 
 * @param cl 
 * @return int returns size of the neighbours
 */

int CL_neighbours(int row,int col,Cell* neighbours,CellList* cl);

/**
 * @brief counts Alive cell of neighbours of a cell with specified row and column
 * 
 * @param row 
 * @param col 
 * @param cl 
 * @return int 
 */

int CL_countAlive(int row,int col,CellList* cl);

/**
 * @brief Checks if Alive cell should die or vice-versa
 * 
 * @param row 
 * @param col 
 * @param cl 
 * @return boolean True/False
 */

boolean CL_Rules(int row,int col,CellList* cl);

/**
 * @brief Changes the state of cells isAlive value
 * 
 * @param cl 
 */

void CL_implement(CellList* cl);

/**
 * @brief Copies isAlive values from board 2 to board 1
 * 
 * @param cl 
 */

void CL_copy(CellList* cl);

/**
 * @brief if cells in both board are equal, return true
 * 
 * @param cl 
 * @return boolean 
 */

boolean CL_equalLists(CellList* cl);

#endif