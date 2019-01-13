//
//  window.h
//  mandelbrot
//
//  Created by Matthew on 11/01/2019.
//  Copyright © 2019 Matthew Harris. All rights reserved.
//

#ifndef window_h
#define window_h

template<typename T>
class window {
public:
    window(T x_min, T x_max, T y_min, T y_max): _x_min(x_min), _x_max(x_max), _y_min(y_min), _y_max(y_max) {}
    
    inline T width() const  { return _x_max - _x_min; }
    
    inline T height() const { return _y_max - _y_min; }
    
    inline T size() const { return width() * height(); }
    
    inline T x_min() const { return _x_min; }
    
    inline void x_min(T x_min) { _x_min = x_min; }
    
    inline T x_max() const { return _x_max; }
    
    inline void x_max(T x_max) { _x_max = x_max; }
    
    inline T y_min() const { return _y_min; }
    
    inline void y_min(T y_min) { _y_min = y_min; }
    
    inline T y_max() const  { return _y_max; }
    
    inline void y_max(T y_max) { _y_max = y_max; }
    
private:
    T _x_min, _x_max;
    T _y_min, _y_max;
};

#endif /* window_h */
