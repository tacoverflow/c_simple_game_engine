#ifndef ENGINE_MAIN_H
#define ENGINE_MAIN_H

#include "graphics.h"
#include "statemanager.h"

typedef struct {
  char *title;
  int width;
  int height;
} EngineOptions;

typedef struct {
  char quit;
  Graphics graphics;
  StateManager statemanager;
  EngineOptions options;
} Engine;

int ENGINE_init(Engine *engine, EngineOptions *options);
int ENGINE_free(Engine *engine);

#endif

