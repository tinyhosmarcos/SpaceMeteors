#include "meteors.h"
meteors::meteors(const char* temp_file,SDL_Renderer* temp_renderer){
    Set_Image(temp_file);
    Create_Texture(temp_renderer);
    proportions(50,50);
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
