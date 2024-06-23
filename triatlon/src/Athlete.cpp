#include <cstdlib>
#include "Athlete.h"


Athlete::Athlete(int id) : id(id), speed(0.0f), position(0.0f), total_time(0.0f), current_stage(1) {}

void Athlete::setInitialSpeed(float min_speed, float max_speed)
{
    speed = min_speed + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (max_speed - min_speed)));
}

void Athlete::updateSpeed()
{
    if (current_stage == 2)
    {
        speed *= 3;
    }
    else if (current_stage == 3)
    {
        speed /= 3;
    }
}

void Athlete::updatePosition(float time_increment)
{
    position += speed * time_increment;
    total_time += time_increment;
}

void Athlete::advanceStage()
{
    current_stage++;
    total_time += 10; // 10 seconds delay at each stage transition
    updateSpeed();
}

bool Athlete::isFinished(float race_distance) const
{
    return position >= race_distance;
}

float Athlete::getPosition() const
{
    return position;
}

float Athlete::getTotalTime() const
{
    return total_time;
}

int Athlete::getId() const
{
    return id;
}

float Athlete::getSpeed() const
{
    return speed;
}

int Athlete::getCurrentStage() const
{
    return current_stage;
}
