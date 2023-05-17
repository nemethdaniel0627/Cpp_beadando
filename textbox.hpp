#ifndef TEXTBOX_H
#define TEXTBOX_H

#include "graphics.hpp"
#include "widgets.hpp"

using std::string;

class Textbox: public Widget
{
protected:
    int _fontSize;
    string _content;
    bool _withBackground = false;
public:
    Textbox(Window * w,int x, int y, int sx, int sy, int fontSize, string content);
    Textbox(Window * w,int x, int y, int sx, int sy, int fontSize, string content, bool withBackground);
    virtual void draw() override;
    virtual void handle(genv::event ev) override;
    virtual string getContent();
    virtual void setContent(string text);
};

#endif // TEXTBOX_H
