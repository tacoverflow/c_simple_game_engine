#ifndef GAME_H
#define GAME_H

typedef struct {
  int x;
  int y;
  int rotation;
  float collidable;
} GAME_PhysicsData;

typedef struct {
  char *image_path;
} GAME_Image;

typedef struct {
  float visible;
  GAME_Image image;
} GAME_GraphicsData;

typedef struct {
  char *map_id;
  GAME_Image background; 
  int width;
  int height;
} GAME_Map;

int GAME_Image_init(GAME_Image *image);
void GAME_Image_free(GAME_Image *image);

#endif
