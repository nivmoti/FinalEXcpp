#pragma once
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include "Leauge.hpp"
#include "Game.hpp"
using namespace std;
namespace ex
{
    class Schedule
    {
    private:
    int maxteas=20;
        
    public:
        Schedule()=default;
        ~Schedule();
        static void oreder(Leauge &play);
    };
    
    
    
} // namespace ex
