//
//  main.cpp
//  mandelbrot
//
//  Created by Matthew Harris on 11/01/2019.
//  Copyright © 2019 Matthew Harris. All rights reserved.
//

#include <iostream>
#include <complex>
#include <vector>
#include "window.h"
#include "fractal_plotter.hpp"

// Check if a point is in the set or escapes
int escape(std::complex<double> c, int max_iter) {
    
    int iteration = 0;
    std::complex<double> z;
    
    while(abs(z) < 2 && iteration < max_iter) {
        // z_n+1 = z_n + c - mandelbrot
        z = z*z + c;
        iteration++;
    }
    
    return iteration;
}

std::complex<double> scale(window<int> &scr, window<double> &frac, std::complex<double> c) {
    double x = c.real() / (double)scr.width() * frac.width() + frac.x_min();
    double y = c.imag() / (double)scr.height() * frac.height() + frac.y_min();
    
    return std::complex<double> {x,y};
}

void draw_fractal(window<int> &scr, window<double> &frac, int max_iter) {
    
    std::vector<int> points(scr.size());
    int k = 0;
    
    for (int i = scr.y_min(); i < scr.y_max(); ++i) {
        for (int j = scr.x_min(); j < scr.x_max(); ++j) {
            std::complex<double> c{(double)j, (double)i};
            // scale into range of complex window
            c = scale(scr, frac, c);
            points[k] = escape(c, max_iter);
            
            k++;
        }
    }
    
    plot(scr, points, max_iter);
}

int main(int argc, const char * argv[]) {
    
    // image size
    window<int> scr(0, 600, 0, 600);
    
    // complex window:
    window<double> frac {-2.2, 1.2, -1.7, 1.7};
    
    draw_fractal(scr, frac, 500);
    
    return 0;
}
