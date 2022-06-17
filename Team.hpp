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
    static size_t const maxname=10;
    class Team
    {
        
    private:
        string name;
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
        Team(string &name,double const &num);
        Team(Team &copy);
        Team(Team &&copy)=default;
        Team & operator= (Team &&) =default;
        Team& operator = (const Team& orgchart)=default;
        Team& operator*(){
            return (*this);
        }
        static string random_string();
        void win();
        void lose();
        double  Getalnet() const;
        void scores(int shot,int get);
        void Random();
        int  Getwinpoits()const {return winpoints;}
        int  Getwins() const{return wins;}
        int  Getwinsrow() const{return maxwins;}
        int  Getloserow() const {return maxloses;}
        int  GetEfresh() const {return (this->winpoints-this->losepoints);}
        string Getname() const {return this->name;}
        ~Team();
    };
        
    
} // namespace ex
