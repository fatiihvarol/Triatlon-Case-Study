#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Race.h"

int main()
{
    srand(static_cast<unsigned int>(time(0))); // Random seed for speed initialization
    int num_teams = 300;
    int num_athletes_per_team = 3;
    float min_speed = 1.0f;
    float max_speed = 5.0f;

    Race triathlon(num_teams, num_athletes_per_team);
    triathlon.initializeRace(min_speed, max_speed);
    triathlon.startRace();
    triathlon.displayResults();
    triathlon.displayTeamResults();

    return 0;
}
