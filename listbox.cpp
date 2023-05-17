#include "listbox.hpp"
#include <vector>
#include <cstdlib>

using namespace genv;
using namespace std;

ListBox::ListBox(Window * w,int x, int y, int sx, int sy, vector<string> datas) : Widget(w,x,y,sx,sy), _datas(datas)
{
    _focusedItem = -1;
    _scrollDir = 0;
}

void ListBox::handle(event ev){
    _focused = true;
    if (ev.button == btn_left) {
        int textStart = 0;
        for(size_t i = 0; i < _datas.size(); i++) {
            if (ev.pos_x>_x+_borderSize+3 && ev.pos_x<_x+_size_x-_borderSize && ev.pos_y>_y+textStart && ev.pos_y<_y+textStart+gout.cascent()){
                _focusedItem = i;
            }
            textStart += gout.cascent();
        }
    }
    if (ev.button == btn_wheeldown && _datas.size()*gout.cascent()-((-1)*_scrollDir*gout.cascent()) > _size_y) {
        _scrollDir--;
    }
    if (ev.button == btn_wheelup && _datas.size()*gout.cascent()-(_scrollDir*gout.cascent()) > _size_y && _scrollDir < 0) {
        _scrollDir++;
    }
}

void ListBox::draw() {
    if (_focused)gout << move_to(_x,_y) << color(40,40,255) << box(_size_x,_size_y);
    else gout << move_to(_x,_y) << color(150,150,150) << box(_size_x,_size_y);
    gout << move_to(_x+_borderSize,_y+_borderSize) << color(220,220,220) << box(_size_x-(2*_borderSize),_size_y-(2*_borderSize));

    int portion = (_size_y-_borderSize)/(_datas.size()+1);
    gout.load_font("LiberationSans-Regular.ttf", 20);
    int textStart = 0;
    if (_scrollDir > 0) {
        textStart = _scrollDir*gout.cascent();
    }
    else if (_scrollDir < 0) {
        textStart = _scrollDir*gout.cascent();
    }
    int scroolHeight = 0;
    for (int i = 0; i < _datas.size(); i++) {
        if (textStart >= 0 && textStart < _size_y) {
            if (i == _focusedItem) {
                gout << move_to(_x+_borderSize, _y+_borderSize+textStart) << color(100,100,255) << box(_size_x-_borderSize-20,gout.cascent());
            }
            gout << move_to(_x+_borderSize+3, _y+textStart) << color(10,10,10) << text(_datas[i]);
            scroolHeight += portion;
        }
        textStart += gout.cascent();
    }
    gout << move_to(_x+_size_x-20,_y+(abs(_scrollDir)*portion)+_borderSize) << color(0,0,100) << box(20-_borderSize,scroolHeight);
}


string ListBox::getContent() {
    return _datas[_focusedItem];
}
