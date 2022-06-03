#include <stdio.h>
#include <stdlib.h>
#include "CellList.h"


int main(){
    
    CellList* cl;
    
    while(true){
        // creating a new random 2D Table
        cl = CL_newCellList(10,10);
        CL_show(cl); // print a table using ANSI
        printf("\n");
        sleep(1);
    }

    return 0;
}