#include "CellList.h"


CellList* CL_newCellList(int row,int col){
    CellList* newcelllist = (CellList*)malloc(sizeof(CellList));
    if(newcelllist==NULL){
        printf("Allocation failed!\n");
        exit(1);
    }
    newcelllist->row = row;
    newcelllist->col = col;
    CL_initialize(newcelllist);
    CL_FillRandomCellList(newcelllist);
    return newcelllist;
}

void CL_initialize(CellList* cl){
    for(int i = 0 ; i < cl->row; i++){
        for(int j = 0 ; j < cl->col; j++){
            cl->board1[i][j] = *(C_newCell(i,j,false));
            cl->board2[i][j] = *(C_newCell(i,j,false));
        }
    }
}


void CL_FillRandomCellList(CellList* cl){
    srand(time(NULL));
    for(int i = 0 ; i < cl->row; i++){
        for(int j = 0 ; j < cl->col; j++){
            cl->board1[i][j] = *(C_newCell(i,j,random0n(1)));
        }
    }
}

void CL_show(CellList* cl){
    if(cl==NULL){
        printf("List is empty!\n");
        return;
    }
    for(int i = 0 ; i < cl->row; i++){
        for(int j = 0 ; j < cl->col; j++){
            C_show(&cl->board1[i][j]);
        }
        printf("\n");
    }
}

