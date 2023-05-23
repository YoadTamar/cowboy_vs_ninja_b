#include <iostream>

using namespace std;

#include "SmartTeam.hpp"

namespace ariel
{
    SmartTeam::SmartTeam(Character *leader) : Team(leader) {}

    Character* SmartTeam::ninja_victim(Ninja* ninja, Team* other)
    {
        double min_ninja = __DBL_MAX__;

        for (size_t i = 0; i < other->getTeam().size(); i++)    
        {
            if (other->getTeam().at(i)->isAlive() == true)
            {
                if (other->getTeam().at(i)->distance(ninja) < min_ninja)
                    min_ninja = other->getTeam().at(i)->distance(this->getLeader());
            }
        }
        for (size_t i = 0; i < other->getTeam().size(); i++)
        {
            if (other->getTeam().at(i)->isAlive() == true)
            {
                if (other->getTeam().at(i)->distance(ninja) == min_ninja)
                    return other->getTeam().at(i);
            }
        }
        
        return nullptr;
    }
    Character* SmartTeam::cowboy_victim(Team* other)
    {
        int min_hp = 150;
        for (size_t i = 0; i < other->getTeam().size(); i++)
        {
            if (other->getTeam().at(i)->isAlive() == true)
            {
                if (other->getTeam().at(i)->getHitPoints() < min_hp)
                    min_hp = other->getTeam().at(i)->getHitPoints();
            }
        }
        for (size_t i = 0; i < other->getTeam().size(); i++)
        {
            if (other->getTeam().at(i)->isAlive() == true)
            {
                if (other->getTeam().at(i)->getHitPoints() == min_hp)
                    return other->getTeam().at(i);
            }
        }
        return nullptr;
    }

    void SmartTeam::attack(Team *other) 
    {
        if(this->stillAlive() == 0)
            throw std::invalid_argument("no players alive");

        if(other == nullptr)
            throw std::invalid_argument("null team");

        if(other->stillAlive() == 0)
            throw std::runtime_error("dead team");

        if(other == this)
            throw std::invalid_argument("attack your team!");

        if (this->getLeader()->isAlive() == false)
            this->setLeader(victim(this));
        
        for(size_t i = 0; i < this->getTeam().size(); i++)
        {
            if(other->stillAlive() == 0)
                return;
            if(this->getTeam().at(i)->getType() == 2)
            {
                Ninja *c = static_cast<Ninja *>(this->getTeam().at(i));
                Character *target = ninja_victim(c,other);
                if(c->isAlive() == false)
                    continue;
                if(c->distance(target) <= 1)
                    c->slash(target);
                else
                    c->move(target);
            }
        }

        for(size_t i = 0; i < this->getTeam().size(); i++)
        {
            if(other->stillAlive() == 0)
                return;
            if(this->getTeam().at(i)->getType() == 1)
            {
                Cowboy *c = static_cast<Cowboy *>(this->getTeam().at(i));
                Character *target = cowboy_victim(other);
                if(c->isAlive() == false)
                    continue;
                if(c->hasboolets())
                    c->shoot(target);
                else
                    c->reload();
            }
        }
    }
    void SmartTeam::print() 
    {
        cout << "SMART TEAM:" << endl;

        string name = getLeader()->getName();

        cout << "the leader: " << name << endl;

        for(size_t i = 0; i < this->getTeam().size(); i++)
        {
            if(this->getTeam().at(i)->getType() == 1)
            {
                std::cout << this->getTeam().at(i)->print() << std::endl;
            }
        }
    }
}