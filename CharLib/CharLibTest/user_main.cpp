#include "user_main.h"

using namespace cl;
using namespace gm;
int user_main(int argc, char * argv[])
{
	CMainApp	mainApp(argc, argv);
	CLSysCtrl	ctrl;
	CLSysTimer	fpsTimer;

	CLImgPoint	ip(1, 1, L'¡ö', CLImgPoint::COLOR_BWHITE);
	CLInterface world(0, 0, 20, 20);
	std::condition_variable cvExit;
	std::mutex mutexIsRun;

	bool isRun = true;
	
	mainApp.setTitle(L"¶íÂÞË¹·½¿é");
	mainApp.setLocaleLanguage("chs");

	ctrl.connect_event([&]() -> void {
		static bool inter = true;
		CLSysCtrl::msg_type msg = ctrl.getMsg();

		switch (msg)
		{
		case CLSysCtrl::KEY_UP:
			ip.moveUp();
			break;
		case CLSysCtrl::KEY_DOWN:
			ip.moveDown();
			break;
		case CLSysCtrl::KEY_LEFT:
			ip.moveLeft();
			break;
		case CLSysCtrl::KEY_RIGHT:
			ip.moveRight();
			break;
		case CLSysCtrl::KEY_ESC:
			if (inter)
			{
				std::unique_lock<std::mutex> locker(mutexIsRun);
				isRun = false;
				locker.unlock();

				inter = false;
				cvExit.notify_one();
			}
			break;
		default:
			break;
		}
	});

	fpsTimer.setTimer(30, [&]()->void {
		world.addImgPoint(ip);
		world.render();
		world.clear();
	});

	ctrl.start_listen();
	fpsTimer.startTimer();

	std::unique_lock<std::mutex> locker(mutexIsRun);
	cvExit.wait(locker, [&isRun]()->bool {return !isRun; });
	fpsTimer.stopTimer();
	ctrl.stop_listen();


	return EXIT_SUCCESS;
}
