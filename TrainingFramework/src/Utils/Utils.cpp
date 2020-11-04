#include "Utils.h"
#include <random>

int randRange(int min, int max)
{
	static std::random_device rd;
	static std::mt19937 eng(rd());
	std::uniform_int_distribution<int> gen(min, max);
	return gen(eng);
}


void TimeSync::Register(int index, double timestamp)
{
    m_registers[index] = timestamp;
    m_currents[index] = 0;
}

void TimeSync::Update(double deltatime)
{
    std::for_each(m_currents.begin(), m_currents.end(), [&deltatime](auto& elm) {elm.second += deltatime; });
}

void TimeSync::changeStep(int index, double step)
{
    m_registers[index] = step;
    m_currents[index] = 0;
 }

bool TimeSync::getStep(int index)
{
    if (m_currents[index] >= m_registers[index])
    {
        m_currents[index] = 0;
        return true;
    }
    return false;
}
