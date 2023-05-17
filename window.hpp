#ifndef WINDOW_H
#define WINDOW_H

#include "widgets.hpp"
#include <vector>

class Window
{
protected:
    int _XX = 400;
    int _YY = 400;
    std::vector<Widget *> widgets;
public:
    Window(int X, int Y);
    virtual ~Window(){}
    void event_loop();
    void registerWidget(Widget*w) {widgets.push_back(w);}
    int getWindowX();
    int getWindowY();
};

#endif // WINDOW_H
