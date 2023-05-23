#include <iostream>

using namespace std;

#include "Team.hpp"

namespace ariel
{
    Team::Team(Character *leader)
    {
        if(leader->getTeam() == true)
            throw runtime_error("already in team!");

        this->leader = leader;
        this->team.push_back(leader);
        leader->setTeam(true);
    }

    void Team::add(Character *member)
    {
        if (member->getTeam() == true)
            throw runtime_error("already in a team!");

        else if (this->team.size() == 10)
            throw runtime_error("Team is full!");

        team.push_back(member);

        member->setTeam(true);
    }

    Character* Team::victim(Team *other)
    {
        double minToLeader = __DBL_MAX__;
        
        for (size_t i = 0; i < other->team.size(); i++)
        {
            if (other->team.at(i)->isAlive() == true && other->team.at(i)->getType() == 1)
            {
                if (other->team.at(i)->distance(this->leader) < minToLeader)
                    minToLeader = other->team.at(i)->distance(this->leader);
            }
        }

        for (size_t i = 0; i < other->team.size(); i++)
        {
            if (other->team.at(i)->isAlive() == true && other->team.at(i)->getType() == 2)
            {
                if (other->team.at(i)->distance(this->leader) < minToLeader)
                    minToLeader = other->team.at(i)->distance(this->leader);
            }
        }

        for (size_t i = 0; i < other->team.size(); i++)
        {
            if (other->team.at(i)->isAlive() == true && other->team.at(i)->getType() == 1)
            {
                if (other->team.at(i)->distance(this->leader) == minToLeader)
                    return other->team.at(i);
            }
        }

        for (size_t i = 0; i < other->team.size(); i++)
        {
            if (other->team.at(i)->isAlive() == true && other->team.at(i)->getType() == 2)
            {
                if (other->team.at(i)->distance(this->leader) == minToLeader)
                    return other->team.at(i);
            }
        }

        return nullptr;
    }

    void Team::attack(Team *other) 
    {
        if(this->stillAlive() == 0)
            throw std::invalid_argument("no players alive");

        if(other == nullptr)
            throw std::invalid_argument("null team");

        if(other->stillAlive() == 0)
            throw std::runtime_error("dead team");

        if(other == this)
            throw std::invalid_argument("attack your team!");

        if (this->leader->isAlive() == false)
            this->leader = victim(this);

        Character *other_victiom = this->victim(other);

        for(size_t i = 0; i < this->team.size(); i++)
        {
            if(other->stillAlive() == 0)
                return;

            if(other_victiom->isAlive() == false)
                other_victiom = victim(other);

            if(this->team.at(i)->getType() == 1)
            {
                Cowboy *c = static_cast<Cowboy *>(this->team.at(i));
                if(c->isAlive() == false)
                    continue;
                if(c->hasboolets() == false)
                    c->reload();
                else
                    c->shoot(other_victiom);
            }
        }

        for(size_t i = 0; i < this->team.size(); i++)
        {
            if(other->stillAlive() == 0)
                return;

            if(other_victiom->isAlive() == false)
                other_victiom = victim(other);

            if(this->team.at(i)->getType() == 2)
            {
                Ninja *c = static_cast<Ninja *>(this->team.at(i));

                if(c->isAlive() == false)
                    continue;
                if(c->distance(other_victiom) <= 1)
                    c->slash(other_victiom);
                else
                    c->move(other_victiom);
            }
        }

    }

    int Team::stillAlive()
    {
        int alive = 0;

        for (size_t i = 0; i < this->team.size(); i++)
        {
            if (this->team.at(i)->isAlive() == true)
                alive++;
        }

        return alive;

    }
    
    vector<Character *>& Team::getTeam()
    {
        return this->team;
    }


    Character* Team::getLeader()
    {
        return this->leader;
    }

    void Team::setLeader(Character* leader)
    {
        this->leader = leader;
    }

    void Team::print()
    {
        cout << "TEAM:" << endl;

        string name = this->leader->getName();

        cout << "the leader: " << name << endl;

        for(size_t i = 0; i < this->team.size(); i++)
        {
            if(this->team.at(i)->getType() == 1)
            {
                std::cout << this->team.at(i)->print() << std::endl;
            }
        }

        // print all ninjas
        for(size_t i = 0; i < this->team.size(); i++)
        {
            if(this->team.at(i)->getType() == 2)
            {
                std::cout << this->team.at(i)->print() << std::endl;
            }
        }
    }
}
