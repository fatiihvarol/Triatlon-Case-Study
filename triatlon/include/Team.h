#ifndef TEAM_H
#define TEAM_H

#include <vector>
#include "Athlete.h"

class Team
{
private:
    int team_id;
    std::vector<Athlete> athletes;

public:
    Team(int team_id, int num_athletes);

    void initializeAthletes(float min_speed, float max_speed);
    std::vector<Athlete> &getAthletes();
    const std::vector<Athlete> &getAthletes() const;
    int getId() const;
    float getTotalTeamTime() const;
};

#endif // TEAM_H
