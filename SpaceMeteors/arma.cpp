#include "arma.h"

Weapons::Weapons(SDL_Renderer* temp_renderer,int post_x,int post_y){
    Set_Image(file);
    Create_Texture(temp_renderer);
    proportions(60,90);
    Set_position('x',post_x);
    Set_position('y',post_y);

}
bool Weapons::eraser_shoot(){
    if(position_y==0){
      return true;
    }
    return false;

}
