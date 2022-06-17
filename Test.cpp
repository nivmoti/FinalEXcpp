#include "doctest.h"
#include <iostream>
#include <stdexcept>
#include <vector>
using namespace std;
#include "Game.hpp"
#include "Leauge.hpp"
#include "Team.hpp"
#include "Schedule.hpp"
using namespace ex;
TEST_CASE("cannot play twice"){
    string nam1="aa";
    string nam2="bb";
    Team* a=new Team(nam1,0.0);
    Team* b=new Team(nam2,0.0);
    string nam3="dai kvar";
    CHECK_THROWS(Team* c=new Team(nam3,-9.0));
    CHECK_THROWS(Team* c=new Team(nam3,10.0));
    Game h{};
    h.GameSet(a,b);
    CHECK_NOTHROW(h.play());
    CHECK_THROWS(h.play());
    CHECK(a->GetEfresh()!=0);
    CHECK(b->GetEfresh()!=0);
    Team* won=h.Thewinnner();
    CHECK(won->Getloserow()==0);
    CHECK(won->Getwinpoits()>0);
    CHECK(won->Getwins()==1);
    CHECK(won->Getwinsrow()>0);
}
TEST_CASE("make a rando team"){
    Team a;
    CHECK_NOTHROW(a.Random());
    CHECK(!(a.Getname().empty()));
    CHECK(a.Getalnet()>=0.0);
    string ch=a.Getname();
    double d=a.Getalnet();
    CHECK(ch==a.Getname());
    CHECK(d==a.Getalnet());
}
TEST_CASE("cannot play over 20 teams"){
    string a="A";
    double num=0.5;
    vector<Team*> tea;
    for (size_t i = 0; i < 30; i++)
    {
        Team temp(a,num);
        tea.push_back(&temp);
        a+='A';

    }
    Leauge liga;
    CHECK_THROWS(liga.SetTeam(tea));
    vector<Team*> teaj;
    Leauge al;
    CHECK_NOTHROW(al.SetTeam(teaj));//make a 20 random teams
    CHECK(al.GetTeams().size()==20);

    
    
}
TEST_CASE("Check static"){
    vector<Team*> teaj;
    Leauge al;
    al.SetTeam(teaj);
    map<double,Team*,greater<double>> first=al.morechanse();
    vector<double> che;
    for (auto it = first.begin(); it !=first.end(); it++)
    {
        che.push_back(it->first);
    }
    for (size_t i = 0; i+1 < che.size(); i++)
    {
        CHECK(che.at(i)<=che.at(i+1));
    }
     map<int,Team*,greater<int>> second=al.loseinarow();
    vector<int> ce;
    for (auto it = second.begin(); it !=second.end(); it++)
    {
        ce.push_back(it->first);
    }
    for (size_t i = 0; i+1 < che.size(); i++)
    {
        CHECK(ce.at(i)<=ce.at(i+1));
    }
    second.clear();
    second=al.bestefresh();
   ce.clear();
    for (auto it = second.begin(); it !=second.end(); it++)
    {
        ce.push_back(it->first);
    }
    for (size_t i = 0; i+1 < ce.size(); i++)
    {
        CHECK(ce.at(i)<=ce.at(i+1));
    }
    second.clear();
       second=al.mostscores();
       ce.clear();
    
    for (auto it = second.begin(); it !=second.end(); it++)
    {
        ce.push_back(it->first);
    }
    for (size_t i = 0; i+1 < ce.size(); i++)
    {
        CHECK(ce.at(i)<=ce.at(i+1));
    }
    second.clear();
    std::vector<std::pair<Team*, int>> winners;
    std::vector<std::pair<Team*, int>> check;
      CHECK_THROWS (winners=al.wins(30));
      CHECK_NOTHROW(winners=al.wins(5));
       ce.clear();
    
    
    for (size_t i = 0; i+1 < winners.size(); i++)
    {
        CHECK(winners.at(i).first<=winners.at(i+1).first);
    }
    second.clear();
       second=al.winsinarow();
       ce.clear();
    
    for (auto it = second.begin(); it !=second.end(); it++)
    {
        ce.push_back(it->first);
    }
    for (size_t i = 0; i+1 < ce.size(); i++)
    {
        CHECK(ce.at(i)<=ce.at(i+1));
    }
    int num=al.moregiveonget();
    CHECK(num>=0);
    
    
}
