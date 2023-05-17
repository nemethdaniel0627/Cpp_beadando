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
public:
    GameMaster(int XX, int YY);
};

#endif // GAMEMASTER_HPP
