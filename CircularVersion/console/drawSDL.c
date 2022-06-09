#include "drawSDL.h"

void drawSDL(){


    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL is peyser %s\n", SDL_GetError());
    }

    SDL_Window * win = SDL_CreateWindow(
        "Game of Life", 
        SDL_WINDOWPOS_UNDEFINED, 
        SDL_WINDOWPOS_UNDEFINED, 
        1000, 1000, SDL_WINDOW_SHOWN
    );

    if (win == NULL) printf("Window error: %s", SDL_GetError());

    SDL_Renderer * renderer = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    CellList* cl = CL_newCellList(100,100);
    
    SDL_Event event;

    while(true){
        // CL_show(cl);
        
        SDL_SetRenderDrawColor(renderer, 0, 0 ,0, 0);

        SDL_RenderClear(renderer);



        for (int i = 0; i < cl->col; i++) {
            for (int j = 0; j < cl->row; j++) {

                if (cl->board1[i][j].isAlive) {
                    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 0);
                } else {
                    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 0);
                }

                SDL_Rect rect = {
                    .x = j * cellSize,
                    .y = i * cellSize,
                    .w = cellSize,
                    .h = cellSize
                };
                SDL_RenderFillRect(renderer, &rect);
            }
        }



        SDL_RenderPresent(renderer);
        if (SDL_PollEvent(&event) && event.type == SDL_QUIT)
            break;

        SDL_Delay(120);

        CL_implement(cl);
        // if(CL_equalLists(cl)){break;}
        CL_copy(cl);
        // sleep(1);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(win);

}