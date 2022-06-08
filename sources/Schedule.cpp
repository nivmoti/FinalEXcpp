#include "Schedule.hpp"
using namespace ex;
using namespace std;  
Schedule::~Schedule(){
}
void Schedule::oreder(Leauge &play){
    for (size_t i = 0; i < 20; i++)
    {
        for (size_t j = 0; j < 20; j++)
        {
            if(i!=j){
                Game first(play.teams->at(i),play.teams->at(j));
                Game second(play.teams->at(j),play.teams->at(i));
                first.play();
                second.play();
                // this->sesson.push_back(first);
                // this->sesson.push_back(second);
                
            }
        }
        
    }
    
}