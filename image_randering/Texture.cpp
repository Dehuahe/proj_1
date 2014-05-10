//
//  Texture.cpp
//  image_randering
//
//  Created by Vida Zhang on 10/5/14.
//  Copyright (c) 2014 Vida Zhang. All rights reserved.
//

#include "Texture.h"

using namespace std;

Texture::Texture(void * data, int w, int h, int format){
    glGenTextures(1, &textureID);
    glBindTexture(GL_TEXTURE_2D, textureID);
    
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, w, h, 0, format, GL_UNSIGNED_BYTE, data);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    
    glBindTexture(GL_TEXTURE_2D, 0);
}

/*
Texture* Texture::loadBMP(const char* filename){
    FILE * fp;
    fp=fopen(filename, "r");
    if(!fp){
        cout<<filename<<" BMP file could not be opened"<<endl;
        fclose(fp);
        return NULL;
    }
    char * headerField= new char[2];
    fread(headerField, 2, sizeof(char), fp);
    if (strcmp(headerField,"BM")) {
        delete []headerField;
        cout<<filename<<" not a BMP"<<endl;
        fclose(fp);
        return NULL;
    };
    
    fseek(fp, 0x000a, SEEK_SET);
    unsigned int bmpdataLocation;
    fread(&bmpdataLocation, 1, sizeof(unsigned int), fp);
    cout<<bmpdataLocation<<endl;
    
}
*/