#include "gameboard.h"
gameboard::gameboard(){

    Init_Video();
    Init_Image();
    Create_Windows();
    Main_Game();
    Main_Space();
    //Create_Map();
    Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,2,2048);
    Mix_Music *musica=Mix_LoadMUS("beat.wav");
    Mix_PlayMusic(musica,-1);
   // Init_Game();
};
void gameboard::Main_Game(){
    renderer = SDL_CreateRenderer(windows, -1, 0);
    image = IMG_Load("background.jpg");
    image2= IMG_Load("main/title.png");
    SDL_Surface* image3=IMG_Load("main/cuadro.png");

    texture = SDL_CreateTextureFromSurface(renderer, image);
    texture2= SDL_CreateTextureFromSurface(renderer,image2);
    SDL_Texture* texture3=SDL_CreateTextureFromSurface(renderer,image3);

    bool choices=true;
    SDL_Rect var_mov={470,330,340,70};
    SDL_Event event;
    while(choices){
        SDL_WaitEvent(&event);
        switch (event.type){
        /*case SDL_MOUSEMOTION:
            int mouseX = event.motion.x;
            int mouseY = event.motion.y;
            std::stringstream ss;
            ss << "X: " << mouseX << " Y: " << mouseY;
            SDL_SetWindowTitle(windows, ss.str().c_str());
            break;
        */
        case SDL_KEYDOWN:
            switch (event.key.keysym.sym){
                case SDLK_UP:    if(var_mov.y!=330) var_mov.y-=70; break;
                case SDLK_DOWN:  if(var_mov.y!=540) var_mov.y+=70; break;
                case SDLK_RETURN:
                    if(var_mov.y==330){
                       choices=false;
                    }
                    break;
            }break;
        }
        SDL_RenderCopy(renderer, texture, NULL, NULL);
        SDL_RenderCopy(renderer, texture2, NULL,NULL);
        SDL_RenderCopy(renderer,texture3,NULL,&var_mov);
        SDL_RenderPresent(renderer);
    }
    SDL_RenderClear(renderer);
    SDL_DestroyTexture(texture2);
    SDL_DestroyTexture(texture3);
}

void gameboard::Main_Space(){
    bool choices=true;
    SDL_Rect var_mov={150,250,210,320};
    SDL_Event event;
    SDL_Surface* image2=IMG_Load("naves/menu_naves.png");
    SDL_Surface* image3=IMG_Load("naves/circulo.png");
    SDL_Texture* texture2=SDL_CreateTextureFromSurface(renderer,image2);
    SDL_Texture* texture3=SDL_CreateTextureFromSurface(renderer,image3);

     while(choices){
        SDL_WaitEvent(&event);
        switch (event.type){
        case SDL_KEYDOWN:
            switch (event.key.keysym.sym){
                case SDLK_LEFT:    if(var_mov.x!=150) var_mov.x-=375; break;
                case SDLK_RIGHT:  if(var_mov.x!=900) var_mov.x+=375; break;
                case SDLK_RETURN:
                    if(var_mov.x==150) file_nave="naves/nave.png";
                    if(var_mov.x==525) file_nave="naves/nave2.png";
                    if(var_mov.x==900) file_nave="naves/nave3.png";
                    choices=false;
            }break;
        }
        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, texture, NULL, NULL);
        SDL_RenderCopy(renderer, texture2, NULL,NULL);
        SDL_RenderCopy(renderer,texture3,NULL,&var_mov);
        SDL_RenderPresent(renderer);
    }
    SDL_RenderClear(renderer);
    SDL_DestroyTexture(texture2);
    SDL_DestroyTexture(texture3);

}
void gameboard::Init_Video(){
    SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO);


}
void gameboard::Init_Image(){
    IMG_Init(IMG_INIT_JPG);
    IMG_Init(IMG_INIT_PNG);
}
void gameboard::Create_Windows(){
    windows= SDL_CreateWindow("SDL2 Displaying Image",
                                SDL_WINDOWPOS_UNDEFINED,
                                SDL_WINDOWPOS_UNDEFINED,
                                1280, 680, 0);
}
void gameboard::Create_Map(){
    renderer = SDL_CreateRenderer(windows, -1, 0);
    image = IMG_Load("background.jpg");
    texture = SDL_CreateTextureFromSurface(renderer, image);

}
/*
void gameboard::Init_Game(){
    nave space("nave.png",renderer);//init nave;
    ASTEROID_BELT asteroids_belt(4,renderer);
    SDL_Event event;

    bool quit=true;

    while(quit){
        space.controler(event,Get_Renderer());
         //finaliza control de teclas
        //renders
        SDL_RenderCopy(Get_Renderer(),Get_Texture(), NULL, NULL);
        SDL_RenderCopy(Get_Renderer(),Get_Texture(), NULL,space.movement());
        //SDL_RenderCopy(board.Get_Renderer(), luna.Get_Texture(),NULL, luna.movement());
        asteroids_belt.init_rainy(Get_Renderer(),space);
        space.shots_impact(Get_Renderer());
        SDL_RenderPresent(Get_Renderer());
        //Renders
    }
}
*/
