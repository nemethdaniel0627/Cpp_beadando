#include "textbox.hpp"
#include "graphics.hpp"

using namespace genv;
using namespace std;


Textbox::Textbox(Window * w,int x, int y, int sx, int sy, int fontSize, string content)
    : Widget(w,x, y, sx, sy), _fontSize(fontSize),_content(content) {}


Textbox::Textbox(Window * w,int x, int y, int sx, int sy, int fontSize, string content, bool withBackground)
    : Widget(w,x, y, sx, sy), _fontSize(fontSize),_content(content), _withBackground(withBackground) {}


void Textbox::draw() {
    if (_withBackground) gout << move_to(_x,_y) << color(0,0,0) << box(_size_x,_size_y);
    gout << move_to(_x,_y);
    gout.load_font("LiberationSans-Regular.ttf", _fontSize);
    gout << color(255,255,255);
    gout << text(_content);
    gout << color(0,0,0);
}

void Textbox::setContent(string text) {
    _content = text;
}

void Textbox::handle(event ev)
{

}

string Textbox::getContent() {
    return _content;
}
