#ifndef EXAMPLECHECKBOX_HPP_INCLUDED
#define EXAMPLECHECKBOX_HPP_INCLUDED

#include "graphics.hpp"
#include "widgets.hpp"

class ExampleCheckBox : public Widget {
protected:
    bool _checked;
public:
    ExampleCheckBox(Window * w,int x, int y, int sx, int sy);
    virtual void draw() ;
    virtual void handle(genv::event ev);
    virtual bool is_checked() ;
};


#endif // EXAMPLECHECKBOX_HPP_INCLUDED
