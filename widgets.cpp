#include "widgets.hpp"
#include "window.hpp"

using namespace genv;
using namespace std;

Widget::Widget(Window * w,int x, int y, int sx, int sy) : _w(w), _x(x), _y(y), _size_x(sx), _size_y(sy)
{
    _w->registerWidget(this);
}

bool Widget::is_selected(int mouse_x, int mouse_y) 
{
    _focused = false;
    return mouse_x>_x && mouse_x<_x+_size_x && mouse_y>_y && mouse_y<_y+_size_y;
}

bool Widget::isSameWidget(int x, int y, int sx, int sy) {
    return x == _x && y == _y && sx == _size_x && sy == _size_y;
}

Widget * Widget::getWidget(int x, int y, int sx, int sy) {
    if (isSameWidget(x,y,sx,sy))
        return this;
}

string Widget::getContent() {
    return "";
}
