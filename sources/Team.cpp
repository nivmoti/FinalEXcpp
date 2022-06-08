#include "Team.hpp"
using namespace std;
using namespace ex;

    Team::Team(Team const &copy){
    this->talent=copy.talent;
    this->name=copy.name;
    this->maxwins=copy.maxwins;
    this->losepoints=copy.losepoints;
    this->winpoints=copy.winpoints;
    this->winsinarow=copy.winsinarow;
    this->wins=copy.wins;
    this->loses=copy.loses;
    this->losesinarow=copy.losepoints;
    this->maxloses=copy.maxloses;

    }
void Team::win(){
    this->wins++;
    this->winsinarow++;
    this->losesinarow=0;
    
    if(winsinarow>this->maxwins){
        this->maxwins=this->winsinarow;
    }
}
void Team::lose(){
    this->loses++;
    this->losesinarow++;
    this->winsinarow=0;
    if(this->losesinarow>this->maxloses){
        this->maxloses=this->losesinarow;
    }
}
void Team::scores(int shot,int get){
    this->winpoints+=shot;
     this->losepoints+=get;
}
double Team::Getalnet(){
    return this->talent;
}
void Team::Random(){
    srand( (unsigned)time( NULL ) );
    this->talent=(double)rand()/RAND_MAX;
    this->name=ex::Team::random_string();
    this->maxwins=0;
    this->losepoints=0;
    this->winpoints=0;
    this->winsinarow=0;
    this->wins=0;
    this->loses=0;
    this->losesinarow=0;
    this->maxloses=0;
}
    
Team::Team(string nam,double num)
    {
        if((num>1)||(num<0)){
            throw std::out_of_range("talent is between 0 to 1");
        }
        this->name=move(nam);
        this->talent=num;
        this->maxwins=0;
        this->losepoints=0;
        this->winpoints=0;
        this->winsinarow=0;
        this->wins=0;
        this->loses=0;
        this->losesinarow=0;
        this->maxloses=0;


    }
string Team::random_string(){
    std::string str("0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz");

    random_device rd;
    std::mt19937 generator(rd());
    

    shuffle(str.begin(), str.end(), generator);

     return str.substr(0, 10);
}
    
Team::~Team()
    {
    }