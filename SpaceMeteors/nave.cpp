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
void nave::shoot(SDL_Renderer* renderer){
    Weapon.push_back(new Weapons(renderer,(this->position_x)+20,(this->position_y)-60));

}
void nave::shots_impact(SDL_Renderer* renderer){
    int coord_temp;
    for(num_shoot=Weapon.begin();num_shoot!=Weapon.end();++num_shoot){
        coord_temp=(*num_shoot)->Get_position('y');
        (*num_shoot)->Set_position('y',coord_temp-1);
        if((*num_shoot)->eraser_shoot()==true ){
            delete(*num_shoot);
            num_shoot=Weapon.erase(num_shoot);
            //delete_shoot(num_shoot);
        }
        else{
            SDL_RenderCopy(renderer,(*num_shoot)->Get_Texture(),NULL, (*num_shoot)->movemento());
        }

    }
}

void nave::delete_shoot(int temp_num_shoot){
    for(num_shoot=Weapon.begin();num_shoot!=Weapon.end();++num_shoot){
        if(temp_num_shoot==0){
             delete(*num_shoot);
             num_shoot=Weapon.erase(num_shoot);
             break;
        }
        temp_num_shoot--;
    }


}
void nave::controler(SDL_Event event,SDL_Renderer *render){
    SDL_PollEvent(&event);
        if(state[SDL_SCANCODE_1]){

        }
        if (state[SDL_SCANCODE_UP]) {
            Set_position('y',Get_position('y')-1);

        }
         if (state[SDL_SCANCODE_DOWN]) {
            Set_position('y',Get_position('y')+1);
        }
         if (state[SDL_SCANCODE_LEFT]) {
            Set_position('x',Get_position('x')-1);
        }
         if (state[SDL_SCANCODE_RIGHT]) {
            Set_position('x',Get_position('x')+1);
        }
         //if (state[SDL_SCANCODE_A]) {
           // space.shoot(board.Get_Renderer());
        //}


       switch (event.type){
            case SDL_KEYDOWN:
                switch (event.key.keysym.sym){
                        //case SDLK_LEFT:  space.Set_position('x',space.Get_position('x')-1); break;
                        //case SDLK_RIGHT: space.Set_position('x',space.Get_position('x')+1); break;
                        //case SDLK_UP:    space.Set_position('y',space.Get_position('y')-1); break;
                        //case SDLK_DOWN:  space.Set_position('y',space.Get_position('y')+1); break;
                        case SDLK_a:     shoot(render); break;
                }
        }
}
