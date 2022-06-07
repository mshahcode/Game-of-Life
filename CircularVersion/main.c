#include <stdio.h>
#include <stdlib.h>
#include "ansidraw.h"


int main(){

    CellList* cl = CL_newCellList(10,10); 

    while(true){
        CL_show(cl);
        CL_implement(cl);
        if(CL_equalLists(cl)){break;}
        CL_copy(cl);
        printf("\n");
        sleep(1);
    }  

    return 0;
}
