#ifndef ATHLETE_H
#define ATHLETE_H

class Athlete
{
private:
    int id;
    float speed;
    float position;
    float total_time;
    int current_stage;

public:
    Athlete(int id);

    void setInitialSpeed(float min_speed, float max_speed);
    void updateSpeed();
    void updatePosition(float time_increment);
    void advanceStage();
    bool isFinished(float race_distance) const;

    float getPosition() const;
    float getTotalTime() const;
    int getId() const;
    float getSpeed() const;
    int getCurrentStage() const;
};

#endif // ATHLETE_H
