#include <SDL.h>
#include <SDL_image.h>

int main(int argc, char* argv[])
{
    SDL_Surface *screen; 
    SDL_Window *window;

    SDL_Init(SDL_INIT_VIDEO); 

    window = SDL_CreateWindow("SDL2 Example", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, 0);

    screen = SDL_GetWindowSurface(window);

    SDL_Surface *image = IMG_Load("images/hazard_suit.png"); 
    SDL_BlitSurface(image, NULL, screen, NULL); 
    SDL_FreeSurface(image); 

    SDL_UpdateWindowSurface(window);

    SDL_Delay(20000);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}

