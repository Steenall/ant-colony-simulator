#include "export/ColonyEvolutionExporter.hpp"
#include "model/Colony.hpp"

template<typename T> inline void ColonyEvolutionExporter::append(T a)
{
    fileIn << a;
}

ColonyEvolutionExporter::ColonyEvolutionExporter(const std::string filename) {
    fileIn = std::ofstream(filename);
    fileIn << "DAY;TOTAL_ANT;WORKER_TOTAL;WORKER_MINOR;WORKER_MAJOR;SCOUT_TOTAL;SCOUT_MINOR;SCOUT_MAJORITY;SOLDIER;FOOD_QUANTITY" << std::endl;
}

inline void ColonyEvolutionExporter::next() {
    fileIn << ';';
}

inline void ColonyEvolutionExporter::nextLine() {
    fileIn << std::endl;
}

void ColonyEvolutionExporter::update(Colony * colony) {
    //Ajout des jours
    append(colony->getDay());
    next();
    //Ajout du total de fourmis
    append((unsigned) colony->getAnts().size());
    next();
    //Ajout du total de fourmis ouvrière
    int workerTotal = 0;
    int workerMinor = 0;
    int workerMajor = 0;
    int scoutTotal = 0;
    int scoutMinor = 0;
    int scoutMajor = 0;
    int soldierTotal = 0;
    for (Ant * ant : colony->getAnts()) {
        //Use dynamic cast
        if (dynamic_cast<Worker *>(ant) != nullptr) {
            workerTotal++;
            if (dynamic_cast<Worker *>(ant)->isMinor()) {
                workerMinor++;
            } else {
                workerMajor++;
            }
        } else if (dynamic_cast<Scout *>(ant) != nullptr) {
            scoutTotal++;
            if (dynamic_cast<Scout *>(ant)->isMinor()) {
                scoutMinor++;
            } else {
                scoutMajor++;
            }
        } else if (dynamic_cast<Soldier *>(ant) != nullptr) {
            soldierTotal++;
        }
    }
    //Ajout du nombre de fourmis ouvrière
    append(workerTotal);
    next();
    //Ajout du nombre de fourmis ouvrière mineurs
    append(workerMinor);
    next();
    //Ajout du nombre de fourmis éclaireuses
    append(scoutTotal);
    next();
    //Ajout du nombre de fourmis éclaireuses mineurs
    append(scoutMinor);
    next();
    //Ajout du nombre de fourmis soldat
    append(soldierTotal);
    next();
    //Ajout de la quantité de nourriture
    append(colony->getFoodQuantity());
    nextLine();

}

ColonyEvolutionExporter::~ColonyEvolutionExporter() {
    fileIn.close();
}