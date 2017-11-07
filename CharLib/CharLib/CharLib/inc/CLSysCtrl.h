#ifndef _CLSYS_CTRL_H_
#define _CLSYS_CTRL_H_

#include "CLSys.h"

namespace cl {
	class CLSysCtrl : public CLSys
	{
		friend void thread_msg_listen(CLSysCtrl *pCtrl);
		friend void thread_msg_event(CLSysCtrl *pCtrl);
	public :
		using msg_type = long;

		typedef void(*event_type)();

		CLSysCtrl();
		virtual ~CLSysCtrl();
		void start_listen();
		void stop_listen();
		

		void connect_event(event_type ent);

		msg_type getMsg();

	private:
		bool m_listenStatus = false;
		event_type m_eventFunc = nullptr;
		//线程间通信队列
		std::queue<msg_type> m_msgQueue;
		std::mutex m_muQueue;
		std::condition_variable m_condQueueReady;

		std::thread *m_pListenThread = nullptr;
		std::thread *m_pEventThread = nullptr;
	};
}



#endif
