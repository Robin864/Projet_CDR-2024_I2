#include "Movement.h"
#include "Position.h"
#include "Pince.h"

class Strategy
{
private:

public:
    char team;
    Strategy();
    void teamSelection();
    void initialization();
    void game();
    void calibration();
    void movePlants();
    void goNearPlantsBasket();
    void pushPots();
    void goToPanelsWall();
    void movePanels();
    void goHome();
    void homologation();

// //Singleton
// public:
//     static inline Strategy& instance(){return m_instance;}
//     Strategy(const Strategy&) = delete;
//     Strategy(Strategy&&) = delete;
//     Strategy& operator=(const Strategy&) = delete;
//     Strategy& operator=(Strategy&&) = delete;
// private:
//     static Strategy m_instance;
};

// extern Movement& strat;