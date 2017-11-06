#include "CLSysCtrl.h"
namespace cl {


	CLSysCtrl::CLSysCtrl()
	{
		this->m_listenStatus = true;
	}

	CLSysCtrl::~CLSysCtrl()
	{

	}

	void CLSysCtrl::start_listen()
	{
		this->m_pListenThread = new std::thread(thread_msg_listen, this);
		this->m_pEventThread = new std::thread(thread_msg_event, this);



		this->m_listenStatus = true;
	}

	void CLSysCtrl::stop_listen()	
	{
		this->m_listenStatus = false;	//结束线程的循坏
		if (this->m_pListenThread == nullptr)
		{
			this->m_pListenThread->join();
			delete this->m_pListenThread;
			this->m_pListenThread = nullptr;
		}

		if (this->m_pEventThread == nullptr)
		{
			this->m_pEventThread->join();
			delete this->m_pEventThread;
			this->m_pEventThread = nullptr;
		}
	}

	void CLSysCtrl::connect_event(event_type ent)
	{
		this->m_eventFunc = ent;
	}

	CLSysCtrl::msg_type CLSysCtrl::getMsg()
	{
		if (m_msgQueue.empty())
		{
			return 0;
		}
		else
		{
			msg_type msg = this->m_msgQueue.front();
			this->m_msgQueue.pop();
			return msg;
		}
	}


	void thread_msg_listen(CLSysCtrl * pCtrl)
	{
		while (pCtrl->m_listenStatus)
		{
			CLSysCtrl::msg_type data = _getch();

			std::lock_guard<std::mutex> locker(pCtrl->m_muQueue);
			pCtrl->m_msgQueue.push(data);
			//locker.unlock();

			pCtrl->m_condQueueReady.notify_one();//通过条件通知其他等待的线程
		}
	}

	void thread_msg_event(CLSysCtrl * pCtrl)
	{
		while (pCtrl->m_listenStatus)
		{
			std::unique_lock<std::mutex> locker(pCtrl->m_muQueue);
			pCtrl->m_condQueueReady.wait(locker, [pCtrl]() -> bool {return !(pCtrl->m_msgQueue.empty()); });

			//执行事件
			if (pCtrl->m_eventFunc)
			{
				(pCtrl->m_eventFunc)();
			}
		}
	}
}


