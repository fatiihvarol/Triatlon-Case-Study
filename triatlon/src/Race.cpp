#include "Race.h"
#include <iostream>
#include <limits>

Race::Race(int num_teams, int num_athletes_per_team)
{
    for (int i = 0; i < num_teams; ++i)
    {
        teams.emplace_back(i, num_athletes_per_team);
    }
}

void Race::initializeRace(float min_speed, float max_speed)
{
    for (auto &team : teams)
    {
        team.initializeAthletes(min_speed, max_speed);
    }
}

void Race::startRace()
{
    const float time_increment = 1.0f;
    bool race_finished = false;
    bool first_athlete_finished = false;
    float total_race_distance = race_distances[0] + race_distances[1] + race_distances[2];

    while (!race_finished)
    {
        race_finished = true;
        for (auto &team : teams)
        {
            for (auto &athlete : team.getAthletes())
            {
                if (!athlete.isFinished(total_race_distance))
                {
                    race_finished = false;
                    athlete.updatePosition(time_increment);

                    if (athlete.getCurrentStage() == 1 && athlete.getPosition() >= race_distances[0])
                    {
                        athlete.advanceStage();
                    }
                    else if (athlete.getCurrentStage() == 2 && athlete.getPosition() >= race_distances[0] + race_distances[1])
                    {
                        athlete.advanceStage();
                    }

                    if (!first_athlete_finished && athlete.isFinished(total_race_distance))
                    {
                        first_athlete_finished = true;
                        std::cout << "First athlete finished! Current positions of all athletes:\n";
                        displayResults();
                    }
                }
            }
        }
    }
}

void Race::displayResults() const
{
    for (const auto &team : teams)
    {
        for (const auto &athlete : team.getAthletes())
        {
            std::cout << "Athlete " << athlete.getId() << " in Team " << team.getId()
                      << " is at position " << athlete.getPosition() << " meters with total time "
                      << athlete.getTotalTime() << " seconds and current speed "
                      << athlete.getSpeed() << " m/s." << std::endl;
        }
    }
}

void Race::displayTeamResults() const
{
    for (const auto &team : teams)
    {
        float total_time = team.getTotalTeamTime();
        std::cout << "Team " << team.getId() << " finished in " << total_time << " seconds." << std::endl;
    }
}
