cmake_minimum_required(VERSION 3.10)

set(PROJECT_NAME FKD_Racing)
project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 17)

find_package(SFML 2.5 
  COMPONENTS 
    system window graphics network audio REQUIRED)

add_executable(${PROJECT_NAME} 
  source/main.cpp
  source/Game.h
  source/Game.cpp
  source/Car.h
  source/Car.cpp
  source/Enemy.h
  source/Enemy.cpp
  source/Draw.cpp
  source/Update.cpp
  source/EnemySystem.h
  source/EnemySystem.cpp
  source/ScoreSystem.h
  source/ScoreSystem.cpp
  source/MenuSystem.h
  source/MenuSystem.cpp
  source/Choice.h
)

target_link_libraries(${PROJECT_NAME} sfml-graphics)
