
#ifndef ANT_COLONY_SIMULATOR_COLONYEVOLUTIONEXPORTER_HPP
#define ANT_COLONY_SIMULATOR_COLONYEVOLUTIONEXPORTER_HPP

#include <fstream>

#define DEFAULT_FILE_NAME_EXPORT "evolution.txt"

class Colony;

class ColonyEvolutionExporter {
    private:
        std::ofstream fileIn;
        inline void next();
        inline void nextLine();
    public:
        explicit ColonyEvolutionExporter(std::string fileName);
        void update(Colony * colony);
        template<typename T> inline void append(T a);
        ~ColonyEvolutionExporter();
};


#endif //ANT_COLONY_SIMULATOR_COLONYEVOLUTIONEXPORTER_HPP
