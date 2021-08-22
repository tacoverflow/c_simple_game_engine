#include <stdio.h>
#include <SDL.h>
#include "src/statemanager.h"
#include "src/engine.h"
#include "src/graphics.h"
#include "src/engine.h"

Engine MAIN_engine;

unsigned int initState1() {
  printf("state 1 created\n");
  return 0;
}

unsigned int updateState1(float deltatime) {
  printf("state 1 update %f\n", deltatime);
  return 0;
}

unsigned int destroyState1() {
  printf("state 1 destroyed\n");
  return 0;
}

unsigned int draw1(float deltatime) {
  printf("state 1 drawing\n");
  SDL_Surface *screen = SDL_GetWindowSurface(MAIN_engine.graphics.window);
  int width = MAIN_engine.options.width;
  int height = MAIN_engine.options.height;
  SDL_Rect rect = {0,0, width, height};
  SDL_FillRect(screen, &rect, SDL_MapRGB(screen -> format, 0x00, 0x00, 0x00));
  SDL_UpdateWindowSurface(MAIN_engine.graphics.window);
  return 0;
}

int main() {
  EngineOptions options = {0};
  options.title = "C engine test ";
  options.width = 480;
  options.height = 272;

  ENGINE_init(&MAIN_engine, &options);

  State state1 = {0};
  state1.init = initState1;
  state1.update = updateState1;
  state1.draw = draw1;
  state1.destroy = destroyState1;

  STATEMANAGER_push(&MAIN_engine.statemanager, &state1);

  SDL_Event e;
  while(!MAIN_engine.quit) {
    while (SDL_PollEvent(&e)) {
      if (e.type == SDL_QUIT) MAIN_engine.quit = 1;
    }

    STATEMANAGER_update(&MAIN_engine.statemanager, 10.0f);
    STATEMANAGER_draw(&MAIN_engine.statemanager, 10.0f);
    SDL_Delay(2000);
  }

  ENGINE_free(&MAIN_engine);
}
