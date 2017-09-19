#include "SysClock.h"

namespace sg {



	CSysClock::CSysClock()
		: m_start(0), m_finish(0), m_isRun(false)
	{
	}

	CSysClock::~CSysClock()
	{
	}

	bool CSysClock::start()
	{
		m_isRun = true;
		m_start = clock();
		return m_isRun;
	}

	bool CSysClock::stop()
	{
		if (m_isRun) {
			m_isRun = false;
			m_finish = clock();
			return true;
		}
		return false;
	}

	void CSysClock::clearTimer()
	{
		m_finish = 0;
		m_start = 0;
	}

	CSysClock::TypeClkTime CSysClock::getTime_fromStart()
	{
		return (clock() - m_start);
	}

	CSysClock::TypeClkTime CSysClock::getTime_fromStartToFinish()
	{
		return m_finish - m_start;
	}

	CSysClock::TypeClkTime CSysClock::getClock()
	{
		return clock();
	}

}



