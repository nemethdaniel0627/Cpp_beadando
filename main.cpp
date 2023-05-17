#include "window.hpp"
#include <vector>
#include "gamemaster.hpp"

using namespace std;
using namespace genv;


int main()
{
    GameMaster g(800,800);


    g.event_loop();
    return 0;
}
