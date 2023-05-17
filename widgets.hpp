#ifndef WIDGETS_HPP_INCLUDED
#define WIDGETS_HPP_INCLUDED

#include "graphics.hpp"

using std::string;

class Window;

class Widget {
protected:
    Window* _w;
    int _x, _y, _size_x, _size_y, _size;    
    bool _focused;
    int _borderSize = 2;
public:
    Widget(Window * w,int x, int y, int sx, int sy);
    virtual bool is_selected(int mouse_x, int mouse_y);
    virtual void draw() = 0;
    virtual void handle(genv::event ev) = 0;
    virtual bool isSameWidget(int x, int y, int sx, int sy);
    virtual Widget * getWidget(int x, int y, int sx, int sy);
    virtual string getContent();
};

#endif // WIDGETS_HPP_INCLUDED
