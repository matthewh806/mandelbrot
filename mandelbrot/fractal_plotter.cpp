//
//  fractal_plotter.cpp
//  mandelbrot
//
//  Created by Matthew on 11/01/2019.
//  Copyright © 2019 Matthew Harris. All rights reserved.
//

#include "fractal_plotter.hpp"
#include <FreeImage.h>

void plot(window<int> &scr, std::vector<int> &colors, int iter_max) {
    FreeImage_Initialise();
    
    FIBITMAP *bitmap = FreeImage_Allocate(scr.width(), scr.height(), 32);
    
    int k = 0;
    for(int i = scr.y_min(); i < scr.y_max(); i++) {
        for(int j = scr.x_min(); j < scr.x_max(); j++) {
            int n = colors[k];
            
            bool black = n == iter_max;
            
            RGBQUAD col;
            col.rgbRed = black ? 0:255;
            col.rgbBlue = black ? 0:255;
            col.rgbGreen = black ? 0:255;
            
            FreeImage_SetPixelColor(bitmap, j, i, &col);
            k++;
        }
    }
    
    FreeImage_Save(FIF_PNG, bitmap, "mandelbrot.png");
    
    FreeImage_Unload(bitmap);
    FreeImage_DeInitialise();
}
