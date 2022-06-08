#pragma once
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <random>
#include <cmath>
#include "Team.hpp"
#include <iomanip>
using namespace std;
namespace ex{
    class Game
    {
    private:
        
        bool done;
        Team* home;
        Team* away;
        int scoresaway=0;
        int scoreshome=0;
        int const Bonus=10;
        
    public:
        Game(Team home,Team away);
        Game()=default;
        ~Game()=default;
        void play();

    };
    
   
    
}