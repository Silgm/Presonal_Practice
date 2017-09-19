#ifndef _SYS_CLOCK_H_
#define _SYS_CLOCK_H_

#include "GameSystemObject.h"

namespace sg {
	class CSysClock : public CGameSystemObject {

	public:
		using TypeClkTime = clock_t;
		CSysClock();
		virtual ~CSysClock();

		bool start();
		bool stop();

		void clearTimer();
		TypeClkTime getTime_fromStart();
		TypeClkTime getTime_fromStartToFinish();
		TypeClkTime getClock();
		
	private:
		TypeClkTime m_start;
		TypeClkTime m_finish;
		bool m_isRun;

	};
}


#endif
