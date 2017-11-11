#ifndef _CLSYS_TIMER_H_
#define _CLSYS_TIMER_H_

#include "CLSys.h"

namespace cl {
	class CLSysTimer : public CLSys
	{
		friend void thread_func(CLSysTimer *timer);
	public :
		using event_type = std::function<void()>;

		CLSysTimer();
		CLSysTimer(int timeMs, event_type task);
		virtual ~CLSysTimer();
		void setTimer(int timeMs, event_type task);
		void startTimer();
		void stopTimer();

	private:
		event_type m_eventFunc;
		int m_timeMs = 0;
		bool m_timeIsRun = false;
		std::thread *m_threadTimer = nullptr;
	};
}

#endif
