#include "CLSysClock.h"

namespace cl
{
	CLSysClock::CLSysClock()
	{
	}
	CLSysClock::~CLSysClock()
	{
	}
	void CLSysClock::start()
	{
		this->m_startTime = clock();
	}
	void CLSysClock::stop()
	{
		this->m_stopTime = clock();
	}
	clock_t CLSysClock::getTime()
	{
		return this->m_stopTime - this->m_startTime;
	}
	clock_t CLSysClock::getTimeFromStart()
	{
		return clock() - this->m_startTime;
	}
}

