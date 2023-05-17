#include "gamemaster.hpp"
#include "iostream"
using namespace std;
using namespace genv;

GameMaster::GameMaster(int XX, int YY) : Window(XX,YY) {
    string title = "Amőba 3000";
    tb = new Textbox(this,_XX/2-gout.twidth(title)/2, _YY/4, gout.twidth(title), 40, 40, title);
    tb = new Textbox(this,_XX/2-(gout.twidth("Játékos 1 neve:"))/2, _YY/3+50, 100, 30, 20, "Játékos 1 neve:");
    ti = new TextInput(this,_XX/2+5, _YY/3+50, 150, 30,"Játékos 1");
    tb = new Textbox(this,_XX/2-(gout.twidth("Játékos 2 neve:"))/2, _YY/3+90, 100, 30, 20, "Játékos 2 neve:");
    ti2 = new TextInput(this,_XX/2+5, _YY/3+90, 150, 30,"Játékos 2");
    const int minSize = 15;
    string explain = ("Az amőba mérete: " + to_string(minSize) + "X" + to_string(minSize));
    tb = new Textbox(this,_XX/2-gout.twidth(title)/2, _YY/3+200, 100, 30, 20, explain);
    nm1 = new NumberInput(this,_XX/2-100/2, _YY/3+150, 100, 30,minSize,30, [&,this](){
        tb->setContent("Az amőba mérete: " + to_string(nm1->getValue()) + "X" + to_string(nm1->getValue()));
    });

    string btnText = "Játék indítása";
    btn = new Button(this,_XX/2-gout.twidth(btnText)/2, _YY/2+100, gout.twidth(btnText), 50,btnText,[this](){
        br = new Board(this,800/2-500/2, 800/2-500/2, 500, 500,nm1->getValue(),nm1->getValue(), [this](int x, int y, int sx, int sy, int borderSize) {
            _player = !_player;
            string selChar = _player ? "O" :"X";
            int match = 0;
            int dir = 1;

            vector<Widget *>tmpWidgets = widgets;
            for (int axis = 0; axis < 4 && match != 4; ++axis) {
                if (axis < 2) match = 0;
                dir *= -1;
                int tmpX = x;
                int tmpY = y;
                for (int r = 0; r < 4; ++r) {
                    if (axis < 2) tmpX += dir*((sx)+(2*borderSize));
                    else tmpY += dir*((sy)+(2*borderSize));
                    int i = 0;
                    bool found = false;
                    while (!found && i < tmpWidgets.size()-1) {
                        if (tmpWidgets[i]->isSameWidget(tmpX,tmpY,sx,sy))
                            if (tmpWidgets[i]->getContent() == selChar) {
                                match++;
                                found = true;
                            }
                        i++;

                    }
                }
                if (match == 4) {
                    cout << "Win" << endl;
                    for (int i = 0; i < widgets.size(); i++) {
                        if (widgets[i] == br) {
                            widgets.erase(widgets.begin()+i, widgets.end());
                        }
                    }
                    string winner = selChar == "O" ? ti->getText() : ti2->getText();
                    string title2 = "A nyerő játékos: " + winner;
                    tb = new Textbox(this,_XX/2-gout.twidth(title2)/2, _YY/4, gout.twidth(title2), 40, 40, title2, true);
                }
            }
            match = 0;
            for (int diagonals = 0; diagonals < 4 && match != 4; ++diagonals) {
                int dirX = 1;
                int dirY = 1;
                if (diagonals == 1 || diagonals == 2)
                    dirX *= -1;
                if (diagonals == 1 || diagonals == 3)
                    dirY *= -1;
                if (dirX != dirY && diagonals == 2)
                    match = 0;
                int tmpX = x;
                int tmpY = y;
                for (int r = 0; r < 4; ++r) {
                    tmpX += dirX*((sx)+(2*borderSize));
                    tmpY += dirY*((sy)+(2*borderSize));
                    int i = 0;
                    bool found = false;
                    while (!found && i < tmpWidgets.size()-1) {
                        if (tmpWidgets[i]->isSameWidget(tmpX,tmpY,sx,sy))
                            if (tmpWidgets[i]->getContent() == selChar) {
                                match++;
                                found = true;
                            }
                        i++;

                    }
                }
                if (match == 4) {
                    cout << "Win" << endl;
                    for (int i = 0; i < widgets.size(); i++) {
                        if (widgets[i] == br) {
                            widgets.erase(widgets.begin()+i, widgets.end());
                        }
                    }
                    string winner = selChar == "O" ? ti->getText() : ti2->getText();
                    string title2 = "A nyero jatekos: " + winner;
                    tb = new Textbox(this,_XX/2-gout.twidth(title2)/2, _YY/4, gout.twidth(title2), 40, 40, title2, true);
                }
            }
//            if ()
            return selChar;
        });
    });
}
