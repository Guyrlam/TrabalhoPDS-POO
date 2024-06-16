#include "../include/sdl2.hpp"

// Inicializa as variáveis globais declaradas como extern
SDL_Window* gWindow = NULL;
SDL_Renderer* gRenderer = NULL;
SDL_Rect gSpriteClips[BUTTON_SPRITE_TOTAL];
LTexture gButtonSpriteSheetTexture;
LTexture gBackgroundTexture;
LButton gButtons[TOTAL_BUTTONS];

LTexture::LTexture()
{
    //Initialize
    mTexture = NULL;
    mWidth = 0;
    mHeight = 0;
}

LTexture::~LTexture()
{
    //Deallocate
    free();
}

bool LTexture::loadFromFile(std::string path)
{
    //Get rid of preexisting texture
    free();
    
    //The final texture
    SDL_Texture* newTexture = NULL;

    //Load image at specified path
    SDL_Surface* loadedSurface = IMG_Load(path.c_str());
    if (loadedSurface == NULL)
    {
        printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
    }
    else
    {
        //Color key image
        SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0, 0xFF, 0xFF));

        //Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
        if (newTexture == NULL)
        {
            printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
            system("pause");
        }
        else
        {
            //Get image dimensions
            mWidth = loadedSurface->w;
            mHeight = loadedSurface->h;
        }

        //Get rid of old loaded surface
        SDL_FreeSurface(loadedSurface);
    }

    //Return success
    mTexture = newTexture;
    return mTexture != NULL;
}


void LTexture::free()
{
    //Free texture if it exists
    if (mTexture != NULL)
    {
        SDL_DestroyTexture(mTexture);
        mTexture = NULL;
        mWidth = 0;
        mHeight = 0;
    }
}

void LTexture::setColor(Uint8 red, Uint8 green, Uint8 blue)
{
    //Modulate texture rgb
    SDL_SetTextureColorMod(mTexture, red, green, blue);
}

void LTexture::setBlendMode(SDL_BlendMode blending)
{
    //Set blending function
    SDL_SetTextureBlendMode(mTexture, blending);
}

void LTexture::setAlpha(Uint8 alpha)
{
    //Modulate texture alpha
    SDL_SetTextureAlphaMod(mTexture, alpha);
}

void LTexture::render(int x, int y, SDL_Rect* clip, double angle, SDL_Point* center, SDL_RendererFlip flip)
{
    //Set rendering space and render to screen
    SDL_Rect renderQuad = { x, y, mWidth, mHeight };

    //Set clip rendering dimensions
    if (clip != NULL)
    {
        renderQuad.w = clip->w;
        renderQuad.h = clip->h;
    }

    //Render to screen
    SDL_RenderCopyEx(gRenderer, mTexture, clip, &renderQuad, angle, center, flip);
}

int LTexture::getWidth()
{
    return mWidth;
}

int LTexture::getHeight()
{
    return mHeight;
}

LButton::LButton()
{
    mPosition.x = 0;
    mPosition.y = 0;

    mCurrentSprite = BUTTON_SPRITE_MOUSE_OUT;
}

void LButton::setPosition(int x, int y)
{
    mPosition.x = x;
    mPosition.y = y;
}

void LButton::handleEvent(SDL_Event* e)
{
    //If mouse event happened
    if (e->type == SDL_MOUSEMOTION || e->type == SDL_MOUSEBUTTONDOWN || e->type == SDL_MOUSEBUTTONUP)
    {
        //Get mouse position
        int x, y;
        SDL_GetMouseState(&x, &y);

        //Check if mouse is in button
        bool inside = true;

        //Mouse is left of the button
        if (x < mPosition.x)
        {
            inside = false;
        }
        //Mouse is right of the button
        else if (x > mPosition.x + BUTTON_WIDTH)
        {
            inside = false;
        }
        //Mouse above the button
        else if (y < mPosition.y)
        {
            inside = false;
        }
        //Mouse below the button
        else if (y > mPosition.y + BUTTON_HEIGHT)
        {
            inside = false;
        }

        //Mouse is outside button
        if (!inside)
        {
            mCurrentSprite = BUTTON_SPRITE_MOUSE_OUT;
        }
        //Mouse is inside button
        else
        {
            //Set mouse over sprite
            switch (e->type)
            {
            case SDL_MOUSEMOTION:
                mCurrentSprite = BUTTON_SPRITE_MOUSE_OVER_MOTION;
                break;

            case SDL_MOUSEBUTTONDOWN:
                mCurrentSprite = BUTTON_SPRITE_MOUSE_DOWN;
                break;

            case SDL_MOUSEBUTTONUP:
                mCurrentSprite = BUTTON_SPRITE_MOUSE_UP;
                break;
            }
        }
    }
}

void LButton::render()
{
    //Show current button sprite
    gButtonSpriteSheetTexture.render(mPosition.x, mPosition.y, &gSpriteClips[mCurrentSprite]);
}

bool init()
{
    //Initialization flag
    bool success = true;

    //Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
        system("pause");
        success = false;
    }
    else
    {
        //Set texture filtering to linear
        if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
        {
            printf("Warning: Linear texture filtering not enabled!");
        }

        //Create window
        gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if (gWindow == NULL)
        {
            printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
            system("pause");
            success = false;
        }
        else
        {
            //Create vsynced renderer for window
            gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
            if (gRenderer == NULL)
            {
                printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
                system("pause");
                success = false;
            }
            else
            {
                //Initialize renderer color
                SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

                //Initialize PNG loading
                int imgFlags = IMG_INIT_PNG;
                if (!(IMG_Init(imgFlags) & imgFlags))
                {
                    printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
                    success = false;
                }
            }
        }
    }

    return success;
}

#include <iostream>  // para std::cerr e std::endl
#include <stdexcept> // para std::runtime_error, se necessário

bool loadMedia()
{
    bool success = true;

    try
    {
        if (!gButtonSpriteSheetTexture.loadFromFile("./button.png"))
        {
            throw std::runtime_error("Failed to load button sprite texture!");
        }

        // Restante do código em caso de sucesso no carregamento

        for (int i = 0; i < BUTTON_SPRITE_TOTAL; ++i)
        {
            gSpriteClips[i].x = 0;
            gSpriteClips[i].y = i * 200;
            gSpriteClips[i].w = BUTTON_WIDTH;
            gSpriteClips[i].h = BUTTON_HEIGHT;
        }

        gButtons[0].setPosition(CONTAINER_MARGIN, CONTAINER_MARGIN);
        gButtons[1].setPosition(CONTAINER_MARGIN, CONTAINER_HEIGHT / 2 - BUTTON_HEIGHT / 2);
        gButtons[2].setPosition(CONTAINER_MARGIN, CONTAINER_HEIGHT - BUTTON_HEIGHT - CONTAINER_MARGIN);
        gButtons[3].setPosition(CONTAINER_MARGIN + CONTAINER_WIDTH / 2 - BUTTON_WIDTH / 2, CONTAINER_HEIGHT / 2 - BUTTON_HEIGHT / 2);

        gButtons[4].setPosition(CONTAINER_MARGIN + CONTAINER_WIDTH + CONTAINER_MARGIN, CONTAINER_MARGIN);
        gButtons[5].setPosition(CONTAINER_MARGIN + CONTAINER_WIDTH + CONTAINER_MARGIN, CONTAINER_HEIGHT / 2 - BUTTON_HEIGHT / 2);
        gButtons[6].setPosition(CONTAINER_MARGIN + CONTAINER_WIDTH + CONTAINER_MARGIN, CONTAINER_HEIGHT - BUTTON_HEIGHT - CONTAINER_MARGIN);
        gButtons[7].setPosition(CONTAINER_MARGIN + CONTAINER_WIDTH * 1.5 + CONTAINER_MARGIN - BUTTON_WIDTH / 2, CONTAINER_HEIGHT / 2 - BUTTON_HEIGHT / 2);
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception caught in loadMedia(): " << e.what() << std::endl;
        success = false;
    }
    catch (...) // Captura qualquer outra exceção não derivada de std::exception
    {
        std::cerr << "Unknown exception caught in loadMedia()" << std::endl;
        success = false;
    }

    return success;
}

void close()
{
    //Free loaded images
    gButtonSpriteSheetTexture.free();

    //Destroy window    
    SDL_DestroyRenderer(gRenderer);
    SDL_DestroyWindow(gWindow);
    gWindow = NULL;
    gRenderer = NULL;

    //Quit SDL subsystems
    IMG_Quit();
    SDL_Quit();
}
