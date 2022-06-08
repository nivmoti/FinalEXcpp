#include "Game.hpp"
using namespace ex;
using namespace std;
Game::Game(Team hom,Team awa){
        this->home=&hom;
        this->away=&awa;
        done=false;

}

void Game::play(){
    if(done){
        throw std::out_of_range("played already");
    }
    std::random_device rd{};
    std::mt19937 gen{rd()};
    std::normal_distribution<> d{80,3};
    this->scoreshome=round(d(gen));
    this->scoresaway=round(d(gen));
    this->scoresaway=this->scoresaway+((int)(this->away->Getalnet()*Bonus));
    this->scoreshome=this->scoreshome+((int)(this->home->Getalnet()*Bonus));
    this->home->scores(this->scoreshome,this->scoresaway);
    this->away->scores(this->scoresaway,this->scoreshome);
    Team* win=nullptr;
    Team* lose=nullptr;
    if (this->scoresaway>this->scoreshome)
    {
        win=this->away;
        lose=this->home;
        win->win();
        lose->lose();
    }
    else{
        win=this->home;
        lose=this->away;
        win->win();
        lose->lose();
        
    }
  
    
    done=true;

}

