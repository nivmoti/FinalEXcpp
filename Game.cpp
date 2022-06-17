#include "Game.hpp"
using namespace ex;
using namespace std;
void Game::GameSet(Team *hom,Team *awa){
        this->home=hom;
        this->away=awa;
        done=false;

}
Game::~Game(){
    this->away->~Team();
    this->home->~Team();
    delete this->scoresaway;
    delete this->scoreshome;
    delete this->winner;
}

void Game::play(){
    if(done){
        throw std::out_of_range("played already");
    }
    std::random_device rd{};
    std::mt19937 gen{rd()};
    std::normal_distribution<> d{AVARGE,3};
    this->scoresaway=new int;
    this->scoreshome=new int;
    (*this->scoresaway)=(int)round(d(gen));
    (*this->scoreshome)=(int)round(d(gen));
    (*this->scoresaway)=(*this->scoresaway)+((int)(this->away->Getalnet()*BONUS));
    *this->scoreshome=(*this->scoreshome)+((int)(this->home->Getalnet()*BONUS));
    this->home->scores(*this->scoreshome,*this->scoresaway);
    this->away->scores(*this->scoresaway,*this->scoreshome);
    if (this->scoresaway>this->scoreshome)
    {
        this->away->win();
        this->home->lose();
        this->winner=this->away;
    }
    else{
        this->home->win();
        this->away->lose();
        this->winner=this->home;
    }
      
   
  
    
    done=true;

}


