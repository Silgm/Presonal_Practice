#include "user_main.h"


cl::CLSysCtrl	ctrl;
std::atomic<bool> isExit = false;

void event_msg()
{
	cl::CLSysCtrl::msg_type msg = ctrl.getMsg();
	if (msg)
	{
		std::wcout << msg << L" " << std::endl;
		if (msg == 27)
			isExit = true;
	}
}


void doSomething()
{
	static int cnt = 2000;
	--cnt;
	std::wcout << cnt << std::endl;
	if (cnt < 1)
		isExit = true;
}

int user_main(int argc, char * argv[])
{
	//cl::CLSysTimer timer, timer2;
	//timer.setTimer(10, doSomething);
	//timer.startTimer();

	//ctrl.connect_event(event_msg);
	//ctrl.start_listen();
	//while (1)
	//{
	//	THIS_THREAD_DELAY_S(1);
	//	if (isExit)
	//		break;
	//}
	//ctrl.stop_listen();
	////timer.stopTimer();
	return EXIT_SUCCESS;
}
