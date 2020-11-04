#pragma once
#include <unordered_map>
#include <algorithm>

int randRange(int min, int max);

class TimeSync
{
private:
    // id, accumulator
    std::unordered_map<int, double> m_registers;
    std::unordered_map<int, double> m_currents;
public:
    void Register(int index, double timestamp);
    void Update(double deltatime);
    void changeStep(int index, double step);
    bool getStep(int index);
};