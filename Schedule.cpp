#include "Schedule.hpp"
using namespace ex;
using namespace std;  
void Schedule::oreder(Leauge &play){
    vector<Team*> now=play.GetTeams();
    for (size_t i = 0; i < now.size(); i++)
    {
        for (size_t j = 0; j < now.size(); j++)
        {
            if(i!=j){
                Game first{};
                first.GameSet(now.at(i),now.at(j));
                Game second{};
                second.GameSet(now.at(j),now.at(i));
                first.play();
                second.play();
                // this->sesson.push_back(first);
                // this->sesson.push_back(second);
                
            }
        }
        
    }
    
}
