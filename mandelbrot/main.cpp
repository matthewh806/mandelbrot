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

int max_iteration = 500;


template<typename T>
class window {
public:
    window(T x_min, T x_max, T y_min, T y_max): _x_min(x_min), _x_max(x_max), _y_min(y_min), _y_max(y_max) {}
    
    T width() const  { return _x_max - _x_min; }
    
    T height() const { return _y_max - _y_min; }
    
    T size() const { return width() * height(); }
    
    T x_min() const { return _x_min; }
    
    void x_min(T x_min) { _x_min = x_min; }
    
    T x_max() const { return _x_max; }
    
    void x_max(T x_max) { _x_max = x_max; }
    
    T y_min() const { return _y_min; }
    
    void y_min(T y_min) { _y_min = y_min; }
    
    T y_max() const  { return _y_max; }
    
    void y_max(T y_max) { _y_max = y_max; }
    
private:
    T _x_min, _x_max;
    T _y_min, _y_max;
};

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

void plot(window<int> &sc, std::vector<int> &points, int max_iter) {
    int set_count = std::count(points.begin(), points.end(), (max_iter));
    
    std::cout << "Num. points: " << points.size() << std::endl;
    std::cout << "Values in set: " << set_count << std::endl;
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
    window<int> scr(0, 4, 0, 4);
    
    // complex window:
    window<double> frac {-2, 2, -2, 2};
    
    draw_fractal(scr, frac, 500);
    
    return 0;
}
