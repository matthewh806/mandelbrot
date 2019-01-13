//
//  fractal_plotter.hpp
//  mandelbrot
//
//  Created by Matthew on 11/01/2019.
//  Copyright © 2019 Matthew Harris. All rights reserved.
//

#ifndef fractal_plotter_hpp
#define fractal_plotter_hpp

#include <vector>
#include "window.h"

void plot(window<int> &scr, std::vector<int> &colors, int iter_max);

#endif /* fractal_plotter_hpp */
