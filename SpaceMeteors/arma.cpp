#include "arma.h"

Weapons::Weapons(const char* temp_file,SDL_Renderer* temp_renderer,int post_x,int post_y){
    Set_Image(temp_file);
    Create_Texture(temp_renderer);
    proportions(20,20);
    Set_position('x',post_x);
    Set_position('y',post_y);

}
bool Weapons::eraser_shoot(){
    if(position_y==0){
      return true;
    }
    return false;

}
