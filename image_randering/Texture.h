//
//  Texture.h
//  image_randering
//
//  Created by Vida Zhang on 10/5/14.
//  Copyright (c) 2014 Vida Zhang. All rights reserved.
//

#ifndef __image_randering__Texture__
#define __image_randering__Texture__

#include <iostream>
#include <openGL/gl.h>

using namespace std;

class Texture{
    unsigned int textureID;
public:
    Texture(void * data, int w, int h, int format);
    //static Texture* loadBMP(const char* filename);
};

#endif /* defined(__image_randering__Texture__) */
