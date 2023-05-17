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
    std::vector<string> _player_1;
    std::vector<string> _player_2;
    std::string _playerName = "";
public:
    Board(Window * w,int x, int y, int sx, int sy, int row, int col,
          std::vector<string> player_1,std::vector<string> player_2,std::function<string(int x, int y, int sx, int sy, int borderSize)> f);
    virtual void draw() override;
    virtual void handle(genv::event ev) override;
    void setPlayerName(std::string name);
};

#endif // BOARD_HPP
