#include "Leauge.hpp"
 
    Leauge& Leauge::operator*(){
        
        return (*this);

    }
    Leauge::~Leauge(){
        
        this->teams.clear();
        this->teams.shrink_to_fit();
    
    }
    vector<Team*> Leauge::GetTeams(){
        return this->teams;
    }
    void Leauge::SetTeam(vector<Team*> temsa){
         if (temsa.size()>MAXTEAM)
        {
            throw std::out_of_range("you limmit to 20 teams");
        }
        for (size_t i = temsa.size(); i < MAXTEAM; i++)
        {
            Team a;
            a.Random();
            temsa.push_back(&a);
        }
        
        this->teams=temsa;
    }
  
    map<int,Team*,greater<int>> Leauge::mostscores() const{
        map<int,Team*,greater<int>> comp;
        for (size_t i = 0; i < teams.size(); i++)
        {
            
            
            comp[this->teams.at(i)->Getwinpoits()]=this->teams.at(i);
        }
        return comp;

    }
    std::vector<std::pair<Team*, int>> Leauge::wins(int num) const{
        
        map<int,Team*,greater<int>> comp;
        for (size_t i = 0; i < this->teams.size(); i++)
        {
            comp[teams.at(i)->Getwins()]=teams.at(i);
        }
        if(num>MAXTEAM){throw std::out_of_range("there is only 20 teams");}
        std::vector<std::pair<Team*, int>> comp2;
        int i=0;
        for (auto it = comp.begin(); it != comp.end() && i<num; it++)
        {
            comp2.emplace_back(it->second, it->first);
            i++;
        }
        
        return comp2;
        


    }
    map<double,Team*,greater<double>> Leauge::morechanse() const{
        map<double,Team*,greater<double>> comp;
        for (size_t i = 0; i < this->teams.size(); i++)
        {
            comp[teams.at(i)->Getalnet()]=teams.at(i);
        }
        return comp;

    }
    map<int,Team*,greater<int>> Leauge::winsinarow() const{
        map<int,Team*,greater<int>> comp;
        for (size_t i = 0; i < this->teams.size(); i++)
        {
            comp[teams.at(i)->Getwinsrow()]=teams.at(i);
        }
        return comp;

    }
     map<int,Team*,greater<int>> Leauge::loseinarow() const{
        map<int,Team*,greater<int>> comp;
        for (size_t i = 0; i < this->teams.size(); i++)
        {
            comp[teams.at(i)->Getloserow()]=teams.at(i);
        }
        return comp;

    }
    map<int,Team*,greater<int>> Leauge::bestefresh() const{
        map<int,Team*,greater<int>> comp;
        for (size_t i = 0; i < this->teams.size(); i++)
        {
            comp[teams.at(i)->GetEfresh()]=teams.at(i);
        }
        return comp;
        
    }
    int Leauge::moregiveonget() const{
        int count=0;
        for (size_t i = 0; i < MAXTEAM; i++)
        {
            if(teams.at(i)->GetEfresh()>0){
                count++;
            }
        }
        return count;
        
    }
