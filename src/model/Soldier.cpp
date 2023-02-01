#include "model/Soldier.hpp"

Soldier::Soldier() {
    comingHome = false;
    dayBeforeComingHome = 100;
}
Action Soldier ::update(Map map) {
    if(isComingHome()){
        return Action::COMING_HOME;
    }
    else{
        dayBeforeComingHome -=1;
        return Action::PATROLLING;
    }
}

bool Soldier::isComingHome() {
    if(dayBeforeComingHome == 0){
        return true;
    }
    else{
        return false;
    }
}

Soldier::~Soldier() {}