//
//  Mouse.h
//  image_randering
//
//  Created by Vida Zhang on 10/5/14.
//  Copyright (c) 2014 Vida Zhang. All rights reserved.
//

#ifndef __image_randering__Mouse__
#define __image_randering__Mouse__

#include <iostream>
using namespace std;

class Mouse{
public:
    static int lastX;
    static int lastY;
    static int currentX;
    static int currentY;
    static int deltaX;
    static int deltaY;
    static void move(int x, int y);
    static void update();
    
};
#endif /* defined(__image_randering__Mouse__) */
