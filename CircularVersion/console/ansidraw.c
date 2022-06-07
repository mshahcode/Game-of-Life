#include "ansidraw.h"


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
