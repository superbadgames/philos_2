#pragma once

#include "pch.h"
#include "Tower/framework.h"
#include <GL/glew.h>
// TODO: Build Soil manually. This will help to clear up this ugly warning:
// SOIL.lib(image_DXT.obj) : warning LNK4099: PDB '' was not found with 'SOIL.lib(image_DXT.obj)' or at ''; linking object as if no debug info [H:\Layer8\Lateralus\Lateralus.vcxproj]
#include <SOIL/SOIL.h>
#include <stb_image.h>


namespace Tower
{
    class Texture
    {
    public:
        Texture(void);

        ~Texture(void);

        void Load(string filepath, bool generateMipMaps=true);

        void Activate(U32 texUnit=0);

        void Deactivate(U32 texUnit=0);

        void ClearTexture(void);

    private:
        GLuint _textureID;
        S32 _width;
        S32 _height;
        S32 _bitDepth;
    };
}