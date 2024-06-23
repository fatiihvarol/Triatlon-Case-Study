#ifndef RACE_H
#define RACE_H

#include <vector>
#include "Team.h"

class Race
{
private:
    std::vector<Team> teams;
    const float race_distances[3] = {5000.0f, 40000.0f, 10000.0f};

public:
    Race(int num_teams, int num_athletes_per_team);

    void initializeRace(float min_speed, float max_speed);
    void startRace();
    void displayResults() const;
    void displayTeamResults() const;
};

#endif // RACE_H
