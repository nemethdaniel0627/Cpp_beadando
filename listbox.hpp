#ifndef LISTBOX_H
#define LISTBOX_H

#include "widgets.hpp"
#include "graphics.hpp"

using std::string;
using std::vector;

class ListBox : public Widget
{
    vector<string> _datas;
    int _focusedItem, _scrollDir;
public:
    ListBox(Window * w,int x, int y, int sx, int sy, vector<string> datas);
    virtual void draw() override;
    virtual void handle(genv::event ev) override;
    virtual string getContent();
};

#endif // LISTBOX_H
