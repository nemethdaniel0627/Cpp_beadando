#include "window.hpp"
#include "widgets.hpp"

using namespace genv;
using namespace std;

Window::Window(int X, int Y) : _XX(X), _YY(Y)
{
    gout.open(_XX,_YY);
    gout << font("LiberationSans-Regular.ttf", 40);
}

void Window::event_loop() {
    gout << move_to(0,0) << color(0,0,0) << box(_XX,_YY);
    for (Widget * w : widgets) {
        w->draw();
    }
    gout << refresh;
    event ev;
    int focus = -1;
    while(gin >> ev ) {
        if (ev.type == ev_mouse && ev.button==btn_left) {
            focus = -1;
            for (size_t i=0;i<widgets.size();i++) {
                if (widgets[i]->is_selected(ev.pos_x, ev.pos_y)) {
                        focus = i;                        
                }
            }
        }
        gout << move_to(0,0) << color(0,0,0) << box(_XX,_YY);
        if (focus!=-1) {
            widgets[focus]->handle(ev);
        }
        for (Widget * w : widgets) {
            w->draw();
        }
        if (ev.keycode == key_space) {
//            ofstream kf;
//            kf.open("aktualis.txt");
//            kf << widgets[focus]->getContent();
//            kf.close();
        }
        gout << refresh;
    }
}

int Window::getWindowX(){
    return _XX;
}

int Window::getWindowY(){
    return _YY;
}
