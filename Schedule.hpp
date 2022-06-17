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
    constexpr int maxteas=20;
    class Schedule
    {
    private:
        
    public:
        Schedule()=default;
        Schedule(Schedule &sch)=default;
        Schedule(Schedule &&sch)=default;
        Schedule & operator= (Schedule &&) =default;
        Schedule& operator = (const Schedule& orgchart)=default;
        ~Schedule();
        static void oreder(Leauge &play);
    };
    
    
    
} // namespace ex
