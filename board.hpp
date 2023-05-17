#ifndef BOARD_HPP
#define BOARD_HPP

#include "window.hpp"
#include "widgets.hpp"
#include <functional>

class Board : public Widget
{
protected:
    int _row, _col;
    std::function<string(int x, int y, int sx, int sy, int borderSize)> _f;
public:
    Board(Window * w,int x, int y, int sx, int sy, int row, int col, std::function<string(int x, int y, int sx, int sy, int borderSize)> f);
    virtual void draw() override;
    virtual void handle(genv::event ev) override;
};

#endif // BOARD_HPP
