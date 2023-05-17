#include "button.hpp"

using namespace genv;
using namespace std;

Button::Button(Window * w,int x, int y, int sx, int sy, string content, std::function<void()> f) : Widget(w,x,y,sx,sy), _content(content), _f(f)
{        
}

void Button::draw() {
    if (_pressed)gout << move_to(_x,_y) << color(150,150,150) << box(_size_x,_size_y);
    else gout << move_to(_x,_y) << color(100,100,100) << box(_size_x,_size_y);
    if (_pressed) gout << move_to(_x+_borderSize,_y+_borderSize) << color(230,230,230) << box(_size_x-(2*_borderSize),_size_y-(2*_borderSize));
    else gout << move_to(_x+_borderSize,_y+_borderSize) << color(200,200,200) << box(_size_x-(2*_borderSize),_size_y-(2*_borderSize));
    gout.load_font("LiberationSans-Regular.ttf", 20);
    gout << move_to(((_x+_size_x/2)-gout.twidth(_content)/2), _y+_size_y/2-gout.cascent()+gout.cdescent()+_borderSize) << color(10,10,10) << text(_content);
//    string upArrow = "/\\";
//    string downArrow = "\\/";
//    gout.load_font("LiberationSans-Regular.ttf", 12);
//    gout << move_to(_btn_x,_up_btn_y) << color(100,100,100) << box(_btn_size-_borderSize,-(_size_y)/2+_borderSize+1);
//    gout << color(255,255,255) << move_to(_btn_x+(_btn_size/2)-(gout.twidth(upArrow)/2),_y+_size_y/4-gout.cascent()+gout.cdescent()+_borderSize*2) << text(upArrow);
//    gout << move_to(_btn_x,_down_btn_y) << color(100,100,100) << box(_btn_size-_borderSize,(_size_y)/2-_borderSize-1);
//    gout << color(255,255,255) << move_to(_btn_x+(_btn_size/2)-(gout.twidth(downArrow)/2),_y+(3*_size_y/4)-gout.cascent()+gout.cdescent()+_borderSize*2) << text(downArrow);
}


void Button::handle(event ev)
{
    if (ev.button == btn_left) {
        _pressed = true;
    }
    else if (_pressed && ev.button == -btn_left) {
        _f();
        _pressed = false;
    }
    _focused = true;
}
