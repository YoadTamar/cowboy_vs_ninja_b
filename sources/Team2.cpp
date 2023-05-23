#include <iostream>

using namespace std;

#include "Team2.hpp"

namespace ariel
{
    Team2::Team2(Character *leader) : Team(leader){}

    void Team2::attack(Team *other) 
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

        Character *other_victim = this->victim(other);

        for(size_t i = 0; i < this->getTeam().size(); i++)
        {
            if(other->stillAlive() == 0)
                return;

            if(other_victim->isAlive() == false)
                other_victim = victim(other);

            if(this->getTeam().at(i)->getType() == 1)
            {
                Cowboy *c = static_cast<Cowboy *>(this->getTeam().at(i));
                if(c->isAlive() == false)
                    continue;
                if(c->hasboolets() == false)
                    c->reload();
                else
                    c->shoot(other_victim);
            }
        }

        for(size_t i = 0; i < this->getTeam().size(); i++)
        {
            if(other->stillAlive() == 0)
                return;

            if(other_victim->isAlive() == false)
                other_victim = victim(other);

            if(this->getTeam().at(i)->getType() == 2)
            {
                Ninja *c = static_cast<Ninja *>(this->getTeam().at(i));

                if(c->isAlive() == false)
                    continue;
                if(c->distance(other_victim) <= 1)
                    c->slash(other_victim);
                else
                    c->move(other_victim);
            }
        }

    }

    Character* Team2::victim(Team *other)
    {
        double minToLeader = __DBL_MAX__;
        for (size_t i = 0; i < other->getTeam().size(); i++)
        {
            if (other->getTeam().at(i)->isAlive() == true)
            {
                if (other->getTeam().at(i)->distance(this->getLeader()) < minToLeader)
                    minToLeader = other->getTeam().at(i)->distance(this->getLeader());
            }
        }
        for (size_t i = 0; i < other->getTeam().size(); i++)
        {
            if (other->getTeam().at(i)->isAlive() == true)
            {
                if (other->getTeam().at(i)->distance(this->getLeader()) == minToLeader)
                    return other->getTeam().at(i);
            }
        }
        return nullptr;
    }

    void Team2::print()
    {
        cout << "TEAM2:" << endl;

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
