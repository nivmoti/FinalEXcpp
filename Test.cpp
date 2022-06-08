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
    Team a("aa",0.2);
    Team b("bb",0.0);
    Game h(a,b);
    CHECK_NOTHROW(h.play());
    CHECK_THROWS(h.play());
}
TEST_CASE("make a rando team"){
    Team a;
    CHECK_NOTHROW(a.Random());
    CHECK(!(a.Getname().empty()));
    CHECK(a.Getalnet()>=0.0);
}
TEST_CASE("cannot play over 20 teams"){
    string a="A";
    double num=0.5;
    vector<Team> tea;
    for (size_t i = 0; i < 30; i++)
    {
        Team temp(a,num);
        tea.push_back(temp);
        a+='A';

    }
    Leauge liga;
    CHECK_THROWS(liga.SetTeam(tea));
    vector<Team> teaj;
    Leauge al;
    CHECK_NOTHROW(al.SetTeam(teaj));//make a 20 random teams
    CHECK(al.GetTeams()->size()==20);



}
TEST_CASE("Check static"){
    vector<Team> teaj;
    Leauge al;
    al.SetTeam(teaj);
    map<double,Team,greater<double>> first=al.morechanse();
    vector<double> che;
    for (auto it = first.begin(); it !=first.end(); it++)
    {
        che.push_back(it->first);
    }
    for (size_t i = 0; i+1 < che.size(); i++)
    {
        CHECK(che.at(i)<=che.at(i+1));
    }
     map<int,Team,greater<int>> second=al.loseinarow();
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
      CHECK_THROWS (second=al.wins(30));
      CHECK_NOTHROW(second=al.wins(5));
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
