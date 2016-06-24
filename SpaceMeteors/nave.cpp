#include "nave.h"
nave::nave(const char* temp_file,SDL_Renderer* temp_renderer){
    Set_Image(temp_file);
    Create_Texture(temp_renderer);
    Set_position('x',589);
    Set_position('y',589);
}
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
    if(char_pos=='y' && (position_temp>=-10 && position_temp<600)) position_y=position_temp;
}
SDL_Rect* nave::movement(){
    this->var_mov={position_x,position_y,100,90};
    return &var_mov;
}
void nave::Shoot(SDL_Renderer* temp_render){
    weapon.push_back(new Weapons("bullet.png",temp_render,position_x,position_y));
}
void nave::delete_shoot(SDL_Renderer* temp_render){
    for(counter_shoots=weapon.begin();counter_shoots!=weapon.end();++counter_shoots){

        (*counter_shoots)->Set_position('y',(*counter_shoots)->Get_position('y')-1);
        SDL_RenderCopy(temp_render,(*counter_shoots)->Get_Texture(),NULL, (*counter_shoots)->movement());
        if(((*counter_shoots)->eraser_shoot())==true){

            delete(*counter_shoots);

            counter_shoots=weapon.erase(counter_shoots);
        }
    }
}
