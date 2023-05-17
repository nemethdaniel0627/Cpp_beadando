#include "board.hpp"
#include "tile.hpp"

using namespace genv;
using namespace std;

Board::Board(Window * w,int x, int y, int sx, int sy, int row, int col,
             std::vector<string> player_1, std::vector<string> player_2,std::function<string(int x, int y, int sx, int sy, int borderSize)> f)
    : Widget(w,x,y,sx,sy), _row(row), _col(col), _f(f), _player_1(player_1), _player_2(player_2), _playerName(_player_1[0])
{
    int gap = 1;
    int tileSize = (_size_x/_row);
    while (gap < 2 && (((tileSize-gap)*row + gap*((row+1))) <= _size_x)) {
        if ((((tileSize-gap)*row + gap*(row+1)) > _size_x)) tileSize--;
        else gap++;
    }
    _borderSize = gap+2;
    for (int r = 0; r < row; ++r) {
        int currentRow = _x+(tileSize*r);
        for (int c = 0; c < col; ++c) {

            int plusSizeX = gap+2;
            int plusSizeY = gap+2;
            //            if (c == col-1) {
            //                plusSizeY = 2*gap;
            //            }
            //            if (r == row-1) {
            //                plusSizeX = 2*gap;
            //            }

            int currentCol = _y+(tileSize*c);
            new Tile(_w,currentRow+gap+3, currentCol+gap+3,tileSize-plusSizeX+0, tileSize-plusSizeY+0,_size_y/_col,"",_f);
        }

    }
}

void Board::draw(){    
    gout << move_to(0,0) << color(0,0,0) << box(_w->getWindowX(),_w->getWindowY());
    gout.load_font("LiberationSans-Regular.ttf", 20);
    gout << move_to(10,10) << color(255,255,255) << text("Következő játékos: " + _playerName);
    gout << move_to(10,10+gout.cascent()+gout.cdescent()) << text(_player_1[0] + " : "+_player_1[2]+" - " + _player_2[2] + " : "+_player_2[0]);
    gout << move_to(_x,_y) << color(90,90,90) << box(_size_x, _size_y);
}

void Board::handle(genv::event ev){}

void Board::setPlayerName(string name) {
    _playerName = name;
}

