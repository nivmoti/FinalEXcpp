#include "Team.hpp"
#include <iostream>
#include <map>
using namespace std;

class Leauge {
private:
int maxteams=20;
public:
    vector<ex::Team>* teams;
	Leauge()=default;
    Leauge(Leauge const &copy);

    Leauge& operator=(Leauge const &left);
    Leauge& operator*();
    void SetTeam(vector<ex::Team> temsa);
    vector<ex::Team>* GetTeams();
    map<int,ex::Team,greater<int>>  bestefresh() const;
    map<int,ex::Team,greater<int>> wins(int  num) const;
    map<int,ex::Team,greater<int>> winsinarow() const;
    map<int,ex::Team,greater<int>> loseinarow() const;
    map<double,ex::Team,greater<double>> morechanse() const;
    map<int,ex::Team,greater<int>>  mostscores() const;
    int moregiveonget() const;

    ~Leauge()=default;
};
