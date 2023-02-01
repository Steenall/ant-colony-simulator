cmake_minimum_required(VERSION 3.23)
project(ant_colony_simulator)

set(CMAKE_CXX_STANDARD 14)

add_executable(ant_colony_simulator
        src/main.cpp src/model/Ant.cpp include/model/Ant.hpp include/model/Action.hpp include/model/TypeOfChunk.hpp include/model/Direction.hpp src/model/Map.cpp include/model/Map.hpp src/model/Chunk.cpp include/model/Chunk.hpp src/model/Colony.cpp include/model/Colony.hpp src/model/ColonyAnt.cpp include/model/ColonyAnt.hpp src/model/Queen.cpp include/model/Queen.hpp src/model/Worker.cpp include/model/Worker.hpp src/model/Soldier.cpp include/model/Soldier.hpp src/model/Scout.cpp include/model/Scout.hpp src/model/Slaver.cpp include/model/Slaver.hpp src/export/ColonyEvolutionExporter.cpp include/export/ColonyEvolutionExporter.hpp src/GameEngine.cpp include/GameEngine.hpp src/util/MapBuilder.cpp include/util/MapBuilder.hpp src/view/sfml/SFMLGameEngine.cpp include/view/sfml/SFMLGameEngine.hpp src/view/sfml/SFMLEventHandler.cpp include/view/sfml/SFMLEventHandler.hpp src/model/Game.cpp include/model/Game.hpp include/model/Coordinate.hpp src/model/Direction.cpp)

include_directories(include)

set(SFML_DIR "C:/SFML-2.5.1/lib/cmake/SFML")
find_package(SFML 2.5.1 COMPONENTS graphics audio REQUIRED)
target_link_libraries(ant_colony_simulator sfml-graphics sfml-audio)
file(COPY resources DESTINATION ${CMAKE_BINARY_DIR})