#ifndef NUMBERINPUT_HPP
#define NUMBERINPUT_HPP

#include "widgets.hpp"
#include "graphics.hpp"
#include <functional>

class NumberInput : public Widget
{
    std::function<void()> _f;
    int _btn_x, _up_btn_y, _down_btn_y, _btn_size, _content, _min, _max;

public:
    NumberInput(Window * w,int x, int y, int sx, int sy, int min, int max, std::function<void()> f);
    virtual void draw() override;
    virtual void handle(genv::event ev) override;
    virtual int getValue();
};

#endif // NUMBERINPUT_HPP
