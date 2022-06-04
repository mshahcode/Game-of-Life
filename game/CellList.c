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


boolean CL_belong(int row,int col,CellList* cl){
    if(row >= 0 && row < cl->row && col >= 0 && col < cl->col){
        return true;
    }
    return false;
}

int CL_neighbours(int row,int col,Cell* neighbours,CellList* cl){
    int size = 0;
    if(CL_belong(row-1,col,cl)){
        neighbours[size++] = cl->board1[row-1][col];
    }
    if(CL_belong(row+1,col,cl)){
        neighbours[size++] = cl->board1[row+1][col];
    }
    if(CL_belong(row-1,col-1,cl)){
        neighbours[size++] = cl->board1[row-1][col-1];
    }
    if(CL_belong(row-1,col+1,cl)){
        neighbours[size++] = cl->board1[row-1][col+1];
    }
    if(CL_belong(row+1,col+1,cl)){
        neighbours[size++] = cl->board1[row+1][col+1];
    }
    if(CL_belong(row+1,col-1,cl)){
        neighbours[size++] = cl->board1[row+1][col-1];
    }
    if(CL_belong(row,col+1,cl)){
        neighbours[size++] = cl->board1[row][col+1];
    }
    if(CL_belong(row,col-1,cl)){
        neighbours[size++] = cl->board1[row][col-1];
    }
    return size; 
}

int CL_countAlive(int row,int col,CellList* cl){
    int count = 0;
    Cell neighbours[8];
    int size = CL_neighbours(row,col,neighbours,cl);
    for(int i = 0 ; i < size; i++){
        if(neighbours[i].isAlive){
            count++;
        }
    }
    return count;
}

boolean CL_Rules(int row,int col,CellList* cl){
    int nAliveNeighbours = CL_countAlive(row,col,cl);
    if(cl->board1[row][col].isAlive){
        if(nAliveNeighbours<2 || nAliveNeighbours > 3){
            return false;
        }else{
            return true;
        }
    }else{
        if(nAliveNeighbours==3){
            return true;
        }else{
            return false;
        }
    }
}

void CL_implement(CellList* cl){
    for(int i = 0 ; i < cl->row; i++){
        for(int j = 0 ; j < cl->col; j++){
            cl->board2[i][j].isAlive = CL_Rules(i,j,cl);
        }
    }
}

void CL_copy(CellList* cl){
    for(int i = 0 ; i < cl->row; i++){
        for(int j = 0 ; j < cl->col; j++){
            cl->board1[i][j].isAlive = cl->board2[i][j].isAlive;
        }
    }
}

boolean CL_equalLists(CellList* cl){
    for(int i = 0 ; i < cl->row; i++){
        for(int j = 0 ; j < cl->col; j++){
            if(cl->board1[i][j].isAlive != cl->board2[i][j].isAlive){
                return false;
            }
        }
    }
    return true;
}
