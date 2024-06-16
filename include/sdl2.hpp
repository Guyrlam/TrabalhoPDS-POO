#ifndef SDL2_HPP
#define SDL2_HPP

#include <SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <string>

//Screen dimension constants
const int SCREEN_WIDTH = 740;
const int SCREEN_HEIGHT = 580;

//Button constants
const int BUTTON_WIDTH = 50;
const int BUTTON_HEIGHT = 100;
const int TOTAL_BUTTONS = 8;

//Container dimensions
const int CONTAINER_MARGIN = 10;
const int CONTAINER_WIDTH = (SCREEN_WIDTH - 3 * CONTAINER_MARGIN) / 2;
const int CONTAINER_HEIGHT = (SCREEN_HEIGHT - 2 * CONTAINER_MARGIN) / 2;

enum LButtonSprite
{
    BUTTON_SPRITE_MOUSE_OUT = 0,
    BUTTON_SPRITE_MOUSE_OVER_MOTION = 1,
    BUTTON_SPRITE_MOUSE_DOWN = 2,
    BUTTON_SPRITE_MOUSE_UP = 3,
    BUTTON_SPRITE_TOTAL = 4
};

//Texture wrapper class
class LTexture
{
public:
    //Initializes variables
    LTexture();

    //Deallocates memory
    ~LTexture();

    //Loads image at specified path
    bool loadFromFile(std::string path);

#if defined(SDL_TTF_MAJOR_VERSION)
    //Creates image from font string
    bool loadFromRenderedText(std::string textureText, SDL_Color textColor);
#endif

    //Deallocates texture
    void free();

    //Set color modulation
    void setColor(Uint8 red, Uint8 green, Uint8 blue);

    //Set blending
    void setBlendMode(SDL_BlendMode blending);

    //Set alpha modulation
    void setAlpha(Uint8 alpha);

    //Renders texture at given point
    void render(int x, int y, SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE);

    //Gets image dimensions
    int getWidth();
    int getHeight();

private:
    //The actual hardware texture
    SDL_Texture* mTexture;

    //Image dimensions
    int mWidth;
    int mHeight;
};

//The mouse button
class LButton
{
public:
    //Initializes internal variables
    LButton();

    //Sets top left position
    void setPosition(int x, int y);

    //Handles mouse event
    void handleEvent(SDL_Event* e);

    //Shows button sprite
    void render();

private:
    //Top left position
    SDL_Point mPosition;

    //Currently used global sprite
    LButtonSprite mCurrentSprite;
};


//Starts up SDL and creates window
bool init();

//Loads media
bool loadMedia();

//Frees media and shuts down SDL
void close();


extern SDL_Window* gWindow;
extern SDL_Renderer* gRenderer;
extern SDL_Rect gSpriteClips[BUTTON_SPRITE_TOTAL];
extern LTexture gButtonSpriteSheetTexture;
extern LTexture gBackgroundTexture;
extern LButton gButtons[TOTAL_BUTTONS];


#endif