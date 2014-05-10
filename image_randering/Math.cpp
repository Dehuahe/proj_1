//
//  Math.cpp
//  image_randering
//
//  Created by Vida Zhang on 10/5/14.
//  Copyright (c) 2014 Vida Zhang. All rights reserved.
//

#include "Math.h"
#include <cmath>

double Math::degreesToRadiance(double degrees){
    return degrees * M_PI / 180;
}

double Math::dsin(double theta){
    return sin(degreesToRadiance(theta));
}

double Math::dcos(double theta){
    return cos(degreesToRadiance(theta));
}

