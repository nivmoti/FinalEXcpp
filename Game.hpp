#pragma once
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <random>
#include <cmath>
#include "Team.hpp"
#include <iomanip>

constexpr int BONUS=10;
constexpr double AVARGE=80;

using namespace std;
namespace ex{
    class Game
    {
       
    private:
        
        bool done;
        Team* home;
        Team* away;
        int* scoresaway;
        int* scoreshome;
        Team* winner;
        
    public:
        void GameSet(Team* home,Team* away);
        Game(){}
        Game(Game &g)=default;
        Game(Game &&g)=default;
        Game & operator= (Game &&) =default;
        Game& operator = (const Game& orgchart)=default;
        Team* Thewinnner(){return this->winner;}
        
        ~Game();
        void play();

    };
    
   
    
}