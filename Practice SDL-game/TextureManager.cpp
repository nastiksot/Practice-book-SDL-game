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

void TextureManager::draw(string id, int x, int y, int width, int height, SDL_Renderer* pRenderer, SDL_RendererFlip)
{
}

void TextureManager::drawFrame(string id, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer* pRenderer, SDL_RendererFlip)
{
}
