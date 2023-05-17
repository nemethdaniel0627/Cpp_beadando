#include "numberinput.hpp"

using namespace genv;

NumberInput::NumberInput(Window * w,int x, int y, int sx, int sy, int min, int max, std::function<void()> f)
    : Widget(w,x,y,sx,sy), _f(f), _min(min), _max(max)
{
    _btn_size = 20;
    _btn_x = x+sx-_btn_size;
    _up_btn_y = y+(sy)/2-1;
    _down_btn_y = y+(sy)/2+1;
    _content = _min > 0 ? _min : 0;
}

void NumberInput::draw() {
    if (_focused)gout << move_to(_x,_y) << color(40,40,255) << box(_size_x,_size_y);
    else gout << move_to(_x,_y) << color(150,150,150) << box(_size_x,_size_y);
    gout << move_to(_x+_borderSize,_y+_borderSize) << color(220,220,220) << box(_size_x-(2*_borderSize),_size_y-(2*_borderSize));
    gout.load_font("LiberationSans-Regular.ttf", 20);
    gout << move_to(_x+_borderSize+3, _y+_size_y/2-gout.cascent()+gout.cdescent()+_borderSize) << color(10,10,10) << text(std::to_string(_content));
    string upArrow = "/\\";
    string downArrow = "\\/";
    gout.load_font("LiberationSans-Regular.ttf", 12);
    gout << move_to(_btn_x,_up_btn_y) << color(100,100,100) << box(_btn_size-_borderSize,-(_size_y)/2+_borderSize+1);
    gout << color(255,255,255) << move_to(_btn_x+(_btn_size/2)-(gout.twidth(upArrow)/2),_y+_size_y/4-gout.cascent()+gout.cdescent()+_borderSize*2) << text(upArrow);
    gout << move_to(_btn_x,_down_btn_y) << color(100,100,100) << box(_btn_size-_borderSize,(_size_y)/2-_borderSize-1);
    gout << color(255,255,255) << move_to(_btn_x+(_btn_size/2)-(gout.twidth(downArrow)/2),_y+(3*_size_y/4)-gout.cascent()+gout.cdescent()+_borderSize*2) << text(downArrow);
}


void NumberInput::handle(event ev)
{
    _focused = true;

    if (ev.keycode == key_up && _content < _max) {
        _content++;
    }
    else if (ev.keycode == key_down && _content > _min) {
        _content--;
    }
    if(ev.keycode == key_pgdn) {
        if (_content - 10 < _min)
            _content = _min;
        else
            _content -= 10;
    }
    else if (ev.keycode == key_pgup) {
        if (_content + 10 > _max)
            _content = _max;
        else
            _content += 10;
    }
    if (ev.button == btn_left) {
        if (ev.pos_x>_btn_x && ev.pos_x<_btn_x+_btn_size && ev.pos_y<_up_btn_y && ev.pos_y>_up_btn_y-((_size_y)/2+_borderSize+1) && _content < _max)
            _content++;
        else if(ev.pos_x>_btn_x && ev.pos_x<_btn_x+_btn_size && ev.pos_y>_up_btn_y && ev.pos_y<_up_btn_y+((_size_y)/2+_borderSize+1) && _content > _min)
            _content--;
    }
    _f();
}


int NumberInput::getValue() {
    return _content;
}

