#ifndef GAMEMASTER_HPP
#define GAMEMASTER_HPP

#include "numberinput.hpp"
#include "button.hpp"
#include "window.hpp"
#include "textinput.hpp"
#include "textbox.hpp"
#include "board.hpp"

class GameMaster: public Window
{
protected:
    NumberInput * nm1;
    NumberInput * nm2;
    Button * btn;
    TextInput * ti;
    TextInput * ti2;
    Textbox * tb;
    Board * br;
    bool _player = false;
    std::vector<string> player_1;
    std::vector<string> player_2;
public:
    GameMaster(int XX, int YY);
    void winning(std::vector<string>& currPlayer);
};

#endif // GAMEMASTER_HPP
