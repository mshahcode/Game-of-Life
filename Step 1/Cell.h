/**
 * @file Cell.h
 * @author Mikayil Shahtakhtinski
 * @author Arif Ahmadli
 * @brief Cell file
 * @version 1
 * @date 2022-06-03
 *
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef __CELL_H__
#define __CELL_H__

#define true 1
#define false 0
typedef unsigned char boolean;


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "Random.h"

typedef struct Cell{
    int row;
    int col;
    boolean isAlive;
} Cell;

/**
 * @brief Initialise new cell
 * 
 * @param row 
 * @param col 
 * @param isAlive dead or alive
 * @return Cell* return an address of Cell
 */

Cell* C_newCell(int row,int col,boolean isAlive);

/**
 * @brief Print one cell on the console
 * 
 * @param c 
 */
void C_show(Cell* c);









#endif // __CELL_H_