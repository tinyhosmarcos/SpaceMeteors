#ifndef METEORS_H_INCLUDED
#define METEORS_H_INCLUDED
#include <SDL.h>
#include <SDL_image.h>
#include "SDL_Create.h"
#include <time.h>
#include <stdlib.h>
class meteors:public SDL_Create{
private:
    int velocidad;
public:
    meteors(){velocidad=0;};
    meteors(const char* temp_file,SDL_Renderer* temp_renderer);
    void frec_col();
	void frec_velocidad();
	void movimiento();
};

#endif // METEORS_H_INCLUDED
