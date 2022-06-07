#include <stdio.h>
#include <stdlib.h>
#include "ansidraw.h"
#include "drawSDL.h"

/// Clipped Implementation of Game of Life
/// ANSI console or SDL draw board


int main(){

    printf("Do you want ANSI console version or SDL version? 'A' for ANSI | 'S' for SDL:  ");
    char c;
    scanf("%c",&c);

    if( c == 'A'){
        /// ansi code
        printf("\n");
        CellList* cl = CL_newCellList(10,10);

        while(true){
            CL_show(cl);
            CL_implement(cl);
            if(CL_equalLists(cl)){break;}
            CL_copy(cl);
            printf("\n");
            sleep(1);
        }  
    }else if (c == 'S'){
        /// SDL code
        drawSDL();
    }else{
        printf("Please make correct input next time!\n");
        return 0;
    }

    return 0;
}