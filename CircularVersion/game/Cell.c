#include "Cell.h"


Cell* C_newCell(int row,int col,boolean isAlive){
    Cell* newcell = (Cell*)malloc(sizeof(Cell));
    newcell->row = row;
    newcell->col = col;
    newcell->isAlive = isAlive;
    return newcell;
}

void C_show(Cell* c){
    if(c->isAlive){
        printf("\033[48;5;15m--\033[0m");
    }else{
        printf("\033[48;5;10m--\033[0m");
    }
}


