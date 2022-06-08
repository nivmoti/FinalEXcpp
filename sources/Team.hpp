#pragma once
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <ctime>
#include <unistd.h>
#include <random>
#include <algorithm>
using namespace std;
namespace ex
{
    class Team
    {
    private:
        string name;
        int maxname=10;
        double talent;
        int maxwins;
        int winpoints;
        int losepoints;
        int winsinarow;
        int wins;
        int loses;
        int losesinarow;
        int maxloses;
    public:
        // double talent;
        // int maxwins;
        // int winpoints;
        // int losepoints;
        // int winsinarow;
        // int wins;
        // int loses;
        // int losesinarow;
        // int maxloses;
        Team()=default;
        Team(string name,double num);
        Team(Team const &copy);
        Team& operator=(Team const copy);
        static string random_string();
        void win();
        void lose();
        double Getalnet();
        void scores(int shot,int get);
        void Random();
        int Getwinpoits(){return winpoints;}
        int Getwins(){return wins;}
        int Getwinsrow(){return maxwins;}
        int Getloserow(){return maxloses;}
        int GetEfresh(){return (this->winpoints-this->losepoints);}
        string Getname(){return this->name;}
        ~Team();
    };
        
    
} // namespace ex
