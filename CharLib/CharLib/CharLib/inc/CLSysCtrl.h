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
		using event_type = std::function<void()>;

		enum enum_key
		{
			KEY_ESC = 27,
			KEY_UP = 72,
			KEY_DOWN = 80,
			KEY_LEFT = 75,
			KEY_RIGHT = 77
		};

		CLSysCtrl();
		virtual ~CLSysCtrl();
		void start_listen();
		void stop_listen();
		

		void connect_event(event_type ent);

		msg_type getMsg();

	private:
		bool m_listenStatus = false;
		event_type m_eventFunc;
		
		//通信队列
		std::queue<msg_type> m_msgQueue;
		std::mutex m_muQueue;
		std::mutex m_muListenStatus;
		std::condition_variable m_condQueueReady;

		std::thread *m_pListenThread = nullptr;
		std::thread *m_pEventThread = nullptr;
	};
}



#endif
