#include "tile.hpp"

using namespace std;
using namespace genv;

Tile::Tile(Window * w,int x, int y, int sx, int sy, int fontSize, string content, std::function<string(int x, int y, int sx, int sy, int borderSize)> f)
    : Textbox(w,x, y, sx, sy, fontSize, content), _f(f)
{

}

void Tile::draw(){
    gout << move_to(_x,_y) << color(30,30,30) << box(_size_x, _size_y);
    gout << move_to(_x+((_size_x-gout.twidth(_content))/2),_y-gout.cdescent()/2);
    gout.load_font("LiberationSans-Regular.ttf", _fontSize);
    gout << color(255,255,255);
    gout << text(_content);
    gout << color(0,0,0);
}

void Tile::handle(genv::event ev){
    if (ev.button == btn_left) {
        _content = _f(_x,_y, _size_x, _size_y,_borderSize);
    }
}
