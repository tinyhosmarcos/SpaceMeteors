#include "SDL_Create.h"

void SDL_Create::Set_Image(const char* file){
    image=IMG_Load(file);
}
void SDL_Create::Set_Sound(const char* file){
    sound_effect=Mix_LoadWAV(file);
}
void SDL_Create::Create_Texture(SDL_Renderer* renderer){
    texture=SDL_CreateTextureFromSurface(renderer,image);
}
SDL_Texture* SDL_Create::Get_Texture(){
    return texture;
}

void SDL_Create::Set_position(char char_pos,int position_temp){
    if(char_pos=='x' && (position_temp>=-10 && position_temp<1200) ) this->position_x=position_temp;
    if(char_pos=='y' && (position_temp>=-10 && position_temp<620))   this->position_y=position_temp;
}
int SDL_Create::Get_position(char char_pos){
    if(char_pos=='x') return position_x;
    if(char_pos=='y') return position_y;
    if(char_pos=='l') return length;
    if(char_pos=='w') return width;
}

void SDL_Create::proportions(int temp_width,int temp_length){
    this->width=temp_width;
    this->length=temp_length;
}
SDL_Rect* SDL_Create::movemento(){
    var_mov={this->position_x,this->position_y,width,length};
    return &var_mov;
}
