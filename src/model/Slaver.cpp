#include "model/Slaver.hpp"

Slaver::Slaver(){
    isCarringLarva = false;
}
Action Slaver ::update(Map map) {
    if(carringLarva()){
        return Action::CARRING_LARVA;
    }
   else{
       return Action::SEARCH_COLONY;
   }
}

bool Slaver ::carringLarva() {
    return isCarringLarva;
}

Slaver::~Slaver() {}