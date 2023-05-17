#ifndef TILE_HPP
#define TILE_HPP

#include "textbox.hpp"
#include "functional"

class Tile : public Textbox
{
protected:
    std::function<string(int x, int y, int sx, int sy, int borderSize)> _f;
    string _nextChar = "";
public:
    Tile(Window * w,int x, int y, int sx, int sy, int fontSize, string content, std::function<string(int x, int y, int sx, int sy, int borderSize)> f);
    virtual void draw() override;
    virtual void handle(genv::event ev) override;
};

#endif // TILE_HPP
