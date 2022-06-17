#pragma once
#include "Team.hpp"
#include <map>
using namespace std;
using namespace ex;
constexpr int MAXTEAM=20;

class Leauge {
private:
vector<Team*> teams;
public:

	Leauge()=default;
    Leauge(Leauge &leg)=default;
    Leauge(Leauge &&leg)=default;
    Leauge & operator= (Leauge &&) =default;
    Leauge& operator = (const Leauge& orgchart)=default;
    Leauge& operator*();
    void SetTeam(vector<Team*> temsa);
    vector<Team*> GetTeams();
    map<int,Team*,greater<int>>  bestefresh() const;
    std::vector<std::pair<Team*, int>> wins(int  num) const;
    map<int,Team*,greater<int>> winsinarow() const;
    map<int,Team*,greater<int>> loseinarow() const;
    map<double,Team*,greater<double>> morechanse() const;
    map<int,Team*,greater<int>>  mostscores() const;
    int moregiveonget() const;

    ~Leauge();
};
