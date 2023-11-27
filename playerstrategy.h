#ifndef PLAYERSTRATEGY_H
#define PLAYERSTRATEGY_H

class Player;
class PlayerStrategy
{
    friend class Player;
public:
   virtual  void shot(Player& p1,Player & p) = 0;
};

#endif // PLAYERSTRATEGY_H
