#ifndef TEXTINPUT_HPP
#define TEXTINPUT_HPP

#include "graphics.hpp"
#include "widgets.hpp"

class TextInput : public Widget
{
protected:
    std::string _content = "";
public:
    TextInput(Window * w,int x, int y, int sx, int sy, string content);
    virtual void draw() override;
    virtual void handle(genv::event ev) override;
    virtual std::string getText();    
};

#endif // TEXTINPUT_HPP
