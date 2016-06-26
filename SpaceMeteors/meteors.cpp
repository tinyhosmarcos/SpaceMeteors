#include "meteors.h"
meteors::meteors(const char* temp_file,SDL_Renderer* temp_renderer){
    Set_Image(temp_file);
    Create_Texture(temp_renderer);
    proportions(50,55);
    Set_position('x',589);
    Set_position('y',0);
}
void meteors::frec_col(){
	this->position_x=rand()%1230;
	this->position_y=0;

}
void meteors::frec_velocidad(){
	if(position_y>670 or position_y==0){
		velocidad=rand()%2+1;
	}
	position_y+=velocidad;
}
void meteors::movimiento(){
	frec_velocidad();
	if (position_y>670 or position_x==589){
		frec_col();

	}
}
bool meteors::crash_shoots(nave &test_n){
    list<Weapons*> temp_arma=test_n.Get_shoot();
    list<Weapons*>::iterator temp_shoot;
    for(temp_shoot=temp_arma.begin();temp_shoot!=temp_arma.end();temp_shoot++){
        if( ((this->position_x + this->width) > (*temp_shoot)->Get_position('x'))
        &&((this->position_y + this->length) > (*temp_shoot)->Get_position('y'))
        && (((*temp_shoot)->Get_position('x') + (*temp_shoot)->Get_position('h')) > this->position_x)
        && (((*temp_shoot)->Get_position('y') + (*temp_shoot)->Get_position('w')) > this->position_y)){

        return true;
        }
    }
    return false;

}
bool meteors::crash_nave(nave &test_n){


    if( ((this->position_x + this->width) > test_n.Get_position('x'))
        &&((this->position_y + this->length) > test_n.Get_position('y'))
        && ((test_n.Get_position('x') + test_n.Get_position('h')) > this->position_x)
        && ((test_n.Get_position('y') + test_n.Get_position('w')) > this->position_y)){
        return true;
        }
    return false;
}
