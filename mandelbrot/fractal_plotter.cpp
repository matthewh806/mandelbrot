//
//  fractal_plotter.cpp
//  mandelbrot
//
//  Created by Matthew on 11/01/2019.
//  Copyright © 2019 Matthew Harris. All rights reserved.
//

#include "fractal_plotter.hpp"
#include <FreeImage.h>

const int N = 256;
const int N3 = N * N * N;

std::tuple<int, int, int> get_rgb_piecewise_linear(int n, int iter_max) {
    double t = (double)n/(double)iter_max;
    
    n = (int) ( t * (double)N3 );
    
    int b = n / (N*N);
    int nn = n - b * N * N;
    int r = nn / N;
    int g = nn - r * N;
    
    return std::tuple<int, int, int>(r, g, b);
}

void plot(window<int> &scr, std::vector<int> &colors, int iter_max) {
    FreeImage_Initialise();
    
    FIBITMAP *bitmap = FreeImage_Allocate(scr.width(), scr.height(), 32);
    
    int k = 0;
    for(int i = scr.y_min(); i < scr.y_max(); i++) {
        for(int j = scr.x_min(); j < scr.x_max(); j++) {
            int n = colors[k];
            
            auto rgb = get_rgb_piecewise_linear(n, iter_max);
            
            RGBQUAD col;
            col.rgbRed = std::get<0>(rgb);
            col.rgbBlue = std::get<1>(rgb);
            col.rgbGreen = std::get<2>(rgb);
            
            FreeImage_SetPixelColor(bitmap, j, i, &col);
            k++;
        }
    }
    
    FreeImage_Save(FIF_PNG, bitmap, "mandelbrot.png");
    
    FreeImage_Unload(bitmap);
    FreeImage_DeInitialise();
}
