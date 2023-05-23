#pragma once

#include <vector>
using namespace std;

#include "YoungNinja.hpp"
#include "TrainedNinja.hpp"
#include "OldNinja.hpp"
#include "Cowboy.hpp"

namespace ariel
{
    class Team 
    {
        private:
            vector<Character*> team;
            Character* leader;
        public:
            Team(Character*);
            
            virtual ~Team () 
            {
                for (size_t i = 0; i < team.size(); i++) 
                    {
                        delete team.at(i); 
                    }
            }

            void add(Character*);
            int stillAlive();

            virtual void attack(Team*);
            virtual void print();
    
            virtual Character* victim(Team *);

            vector<Character*>& getTeam();
            Character* getLeader();

            void setLeader(Character*);

    };
}