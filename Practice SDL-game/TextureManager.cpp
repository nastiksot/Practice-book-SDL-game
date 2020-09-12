#include "TextureManager.h"

bool TextureManager::load(string fileName, string id, SDL_Renderer* pRenderer)
{
    //load the image to the surface
    SDL_Surface* pTempSurface = IMG_Load(fileName.c_str());
     if (pTempSurface == 0) 
    {
       cout << "initialization surface failed" << endl;
        return false;
    }
    
        cout << "initialization surface success" << endl;
    //create texture from surface n image
    SDL_Texture* pTexture = SDL_CreateTextureFromSurface(pRenderer,pTempSurface);
    SDL_FreeSurface(pTempSurface);

    //everything is ok, add texture to map
    if (pTexture!=0)
    {
        m_textureMap[id] = pTexture;
        cout << "init image successful" << endl;
        return true;
    }
    cout << "smth went wrong" << endl;
    return false;
    }


void TextureManager::draw(string id, int x, int y, int width, int height, SDL_Renderer* pRenderer, SDL_RendererFlip flip)
{
    SDL_Rect srcRect;
    SDL_Rect destRect;
    
    //set start pos of animate img
    srcRect.x = 0;
    srcRect.y = 0;

    //set size of frame
    srcRect.w = srcRect.w = width;
    srcRect.h = srcRect.h = height;
    destRect.x = x;
    destRect.y = y;

    SDL_RenderCopyEx(pRenderer,m_textureMap[id],&srcRect,&destRect,0,0,flip);
}

void TextureManager::drawFrame(string id, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer* pRenderer, SDL_RendererFlip flip)
{

    SDL_Rect srcRect;
    SDL_Rect destRect;

    //set end pos of animate img
    srcRect.x = width*currentFrame;
    srcRect.y = height*(currentRow-1);
    //srcRect.y = height*currentRow-1;

    //set size of frame
    srcRect.w = srcRect.w = width;
    srcRect.h = srcRect.h = height;
    destRect.x = x;
    destRect.y = y;

    SDL_RenderCopyEx(pRenderer, m_textureMap[id], &srcRect, &destRect, 0, 0, flip);
}
