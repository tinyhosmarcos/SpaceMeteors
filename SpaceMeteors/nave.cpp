#include "nave.h"

void nave::Set_Image(const char* file){
    image_ship=IMG_Load(file);
}
void nave::Create_Texture(SDL_Renderer* renderer){
    texture_ship=SDL_CreateTextureFromSurface(renderer,image_ship);
}
SDL_Texture* nave::Get_Texture(){
    return texture_ship;
}
int nave::Get_position(char char_pos){
    if(char_pos=='x') return position_x;
    if(char_pos=='y') return position_y;
}
void nave::Set_position(char char_pos,int position_temp){
    if(char_pos=='x' && (position_temp>=-10 && position_temp<1200) ) position_x=position_temp;
    if(char_pos=='y' && (position_temp>=-10 && position_temp<620)) position_y=position_temp;
}
SDL_Rect* nave::movement(){
    this->var_mov={position_x,position_y,100,60};
    return &var_mov;
}
