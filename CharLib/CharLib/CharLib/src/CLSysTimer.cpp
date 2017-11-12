#include "CLSysTimer.h"

namespace cl
{
	CLSysTimer::CLSysTimer()
	{
	}
	CLSysTimer::CLSysTimer(int time_ms, event_type task)
	{
		this->setTimer(time_ms, task);
	}
	CLSysTimer::~CLSysTimer()
	{
		this->stopTimer();
	}

	void CLSysTimer::setTimer(int time_ms, event_type task)
	{
		this->m_timeMs = time_ms;
		this->m_eventFunc = task;
	}

	void CLSysTimer::startTimer()
	{
		this->m_timeIsRun = true;
		this->m_threadTimer = new std::thread(thread_func, this);
	}
	void CLSysTimer::stopTimer()
	{
		this->m_timeIsRun = false;
		if (this->m_threadTimer != nullptr)
		{
			if (this->m_threadTimer->joinable())
				this->m_threadTimer->join();
			delete this->m_threadTimer;
			this->m_threadTimer = nullptr;
		}
	}
	void thread_func(CLSysTimer * timer)
	{
		while (timer->m_timeIsRun)
		{
			timer->m_eventFunc();
			THIS_THREAD_DELAY_MS(timer->m_timeMs);
		}
	}
}
