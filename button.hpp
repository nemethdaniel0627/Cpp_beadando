#ifndef BUTTON_H
#define BUTTON_H

#include "widgets.hpp"
#include "graphics.hpp"
#include <functional>

using std::string;

class Button : public Widget
{
protected:
    bool _pressed = false;    
    string _content;
    std::function<void()> _f;
public:
    Button(Window * w,int x, int y, int sx, int sy, string content, std::function<void()> f);
    virtual void draw() override;
    virtual void handle(genv::event ev) override;
};

#endif // BUTTON_H
