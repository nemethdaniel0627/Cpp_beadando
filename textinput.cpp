#include "textinput.hpp"
#include "graphics.hpp"

using namespace genv;

TextInput::TextInput(Window * w,int x, int y, int sx, int sy, string content) : Widget(w,x, y, sx, sy), _content(content)
{
    _focused = false;
}

void TextInput::draw() {
    if (_focused)gout << move_to(_x,_y) << color(40,40,255) << box(_size_x,_size_y);
    else gout << move_to(_x,_y) << color(150,150,150) << box(_size_x,_size_y);
    gout << move_to(_x+2,_y+2) << color(220,220,220) << box(_size_x-4,_size_y-4);
    gout.load_font("LiberationSans-Regular.ttf", 20);
    gout << move_to(_x+_borderSize+3, _y+_size_y/2-gout.cascent()+gout.cdescent()+_borderSize) << color(10,10,10) << text(_content);
}

string TextInput::getText() {
    return _content;
}

void TextInput::handle(event ev)
{
    if (ev.keycode) {
        _content += ev.keyutf8;
    }
    if (ev.keycode == key_backspace) {
        if (!_content.empty()) {
            _content = _content.substr(0,_content.size()-1);
        }
    }
    _focused = true;
}

