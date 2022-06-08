#include "Leauge.hpp"
 
    Leauge::Leauge(Leauge const &copy){
        this->teams=copy.teams;
    }

    Leauge& Leauge::operator=(Leauge const &left){
        this->teams=left.teams;
        return (*this);

    }
    Leauge& Leauge::operator*(){
        
        return (*this);

    }
    void Leauge::SetTeam(vector<ex::Team> temsa){
         if (temsa.size()>maxteams)
        {
            throw std::out_of_range("you limmit to 20 teams");
        }
        for (size_t i = temsa.size(); i < maxteams; i++)
        {
            ex::Team a=ex::Team();
            a.Random();
            temsa.push_back(a);
        }
        
        this->teams=&temsa;
    }
    vector<ex::Team>* Leauge::GetTeams(){
        
        return (teams);
    }
    map<int,ex::Team,greater<int>> Leauge::mostscores() const{
        map<int,ex::Team,greater<int>> comp;
        for (size_t i = 0; i < this->teams->size(); i++)
        {
            comp[teams->at(i).Getwinpoits()]=teams->at(i);
        }
        return comp;

    }
    map<int,ex::Team,greater<int>> Leauge::wins(int num) const{
        map<int,ex::Team,greater<int>> comp;
        for (size_t i = 0; i < this->teams->size(); i++)
        {
            comp[teams->at(i).Getwins()]=teams->at(i);
        }
        if(num>maxteams){throw std::out_of_range("there is only 20 teams");}
        map<int,ex::Team,greater<int>> comp2;
        auto it=comp.begin();
        for (size_t i = 0; i < num; i++)
        {
            comp2[it->first]=it->second;
            it++;
            
        }
        return comp2;
        


    }
    map<double,ex::Team,greater<double>> Leauge::morechanse() const{
        map<double,ex::Team,greater<double>> comp;
        for (size_t i = 0; i < this->teams->size(); i++)
        {
            comp[teams->at(i).Getalnet()]=teams->at(i);
        }
        return comp;

    }
    map<int,ex::Team,greater<int>> Leauge::winsinarow() const{
        map<int,ex::Team,greater<int>> comp;
        for (size_t i = 0; i < this->teams->size(); i++)
        {
            comp[teams->at(i).Getwinsrow()]=teams->at(i);
        }
        return comp;

    }
     map<int,ex::Team,greater<int>> Leauge::loseinarow() const{
        map<int,ex::Team,greater<int>> comp;
        for (size_t i = 0; i < this->teams->size(); i++)
        {
            comp[teams->at(i).Getloserow()]=teams->at(i);
        }
        return comp;

    }
    map<int,ex::Team,greater<int>> Leauge::bestefresh() const{
        map<int,ex::Team,greater<int>> comp;
        for (size_t i = 0; i < this->teams->size(); i++)
        {
            comp[teams->at(i).GetEfresh()]=teams->at(i);
        }
        return comp;
        
    }
    int Leauge::moregiveonget() const{
        int count=0;
        for (size_t i = 0; i < maxteams; i++)
        {
            if(teams->at(i).GetEfresh()>0){
                count++;
            }
        }
        return count;
        
    }
