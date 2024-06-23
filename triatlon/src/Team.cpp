#include "Team.h"
#include "Athlete.h"

Team::Team(int team_id, int num_athletes) : team_id(team_id)
{
    for (int i = 0; i < num_athletes; ++i)
    {
        athletes.emplace_back(i);
    }
}

void Team::initializeAthletes(float min_speed, float max_speed)
{
    for (auto &athlete : athletes)
    {
        athlete.setInitialSpeed(min_speed, max_speed);
    }
}

std::vector<Athlete> &Team::getAthletes()
{
    return athletes;
}

const std::vector<Athlete> &Team::getAthletes() const
{
    return athletes;
}

int Team::getId() const
{
    return team_id;
}

float Team::getTotalTeamTime() const
{
    float total_time = 0;
    for (const auto &athlete : athletes)
    {
        total_time += athlete.getTotalTime();
    }
    return total_time;
}
