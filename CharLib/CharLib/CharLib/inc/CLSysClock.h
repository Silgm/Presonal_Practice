#ifndef _CLSYS_CLOCK_H_
#define _CLSYS_CLOCK_H_

#include "CLSys.h"

namespace cl
{
	class CLSysClock : public CLSys
	{
	public :
		CLSysClock();
		virtual ~CLSysClock();
		void start();
		void stop();
		clock_t getTime();
		clock_t getTimeFromStart();
	private:
		clock_t m_startTime = 0;
		clock_t m_stopTime = 0;
	};
}


#endif
