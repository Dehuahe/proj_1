//
//  Keyboard.cpp
//  image_randering
//
//  Created by Vida Zhang on 10/5/14.
//  Copyright (c) 2014 Vida Zhang. All rights reserved.
//

#include "Keyboard.h"

bool Keyboard::KEYS[256];

void Keyboard::keyDown(unsigned char key, int x, int y){
    KEYS[key] = true;
}

void Keyboard::keyUp(unsigned char key, int x, int y){
    KEYS[key] = false;
}