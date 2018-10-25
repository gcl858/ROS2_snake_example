
/*
#download SDL2-2.0.8 ,install command... 
run "sudo ./configure; sudo make;sudo make install"

#run keyin demo 
cd ~/下載/SDL2-2.0.8/test
gcc -o keyEvent keyEvent.c -g -O2 -D_REENTRANT -I/usr/local/include/SDL2 -DHAVE_OPENGLES2 -DHAVE_OPENGL -g -lSDL2_test -L/usr/local/lib -Wl,-rpath,/usr/local/lib -Wl,--enable-new-dtags -lSDL2
./keyEvent
*/
#include <SDL2/SDL.h>
#include <stdbool.h>
int main(int argc, char* argv[])
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0) /* Prefer only events SDL_INIT_EVENTS */
    {
        SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
        return 1;
    }


    SDL_Window* gWindow = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 320, SDL_WINDOW_SHOWN ); 
/* I don't want this window! */

    /* While no quit */
    bool quit = false;

    //Event handler
    SDL_Event e;

    //While application is running
    while( !quit )
    {
        //Handle events on queue
        while( SDL_PollEvent( &e ) != 0 )
        {
            //User requests quit
            if( e.type == SDL_QUIT )
            {
                quit = true;
            }
            //User presses a key
            else if( e.type == SDL_KEYDOWN )
            {
                printf( "Key type: %d\n", e.key.keysym.sym );
                //Select surfaces based on key press
                switch( e.key.keysym.sym )
                {
                    case SDLK_UP:
                    printf( "UP!\n" );
                    break;

                    case SDLK_DOWN:
                    printf( "DOWN!\n" );
                    break;

                    case SDLK_LEFT:
                    printf( "LEFT!\n" );
                    break;

                    case SDLK_RIGHT:
                    printf( "RIGHT!\n" );
                    break;

                    default:
                    break;
                }
            }
        }
    }

    SDL_Quit();
    return 0;
}
