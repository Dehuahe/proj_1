//
//  Keyboard.h
//  image_randering
//
//  Created by Vida Zhang on 10/5/14.
//  Copyright (c) 2014 Vida Zhang. All rights reserved.
//

#ifndef __image_randering__Keyboard__
#define __image_randering__Keyboard__

#include <iostream>
using namespace std;

class Keyboard{
public:
    static bool KEYS[256];
    static void keyDown(unsigned char key, int x, int y);
    static void keyUp(unsigned char key, int x, int y);
    
};

#endif /* defined(__image_randering__Keyboard__) */
