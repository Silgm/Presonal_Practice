#include "user_main.h"

using namespace cl;
using namespace gm;

#define _WINDO

constexpr long WORLD_X = 25;
constexpr long WORLD_Y = 4;

constexpr long WORLD_WIDTH = 30;
constexpr long WORLD_HEIGHT = 20;



int user_main(int argc, char * argv[])
{
	CMainApp	mainApp(argc, argv);
	CLSysCtrl	ctrl;
	CLSysTimer	fpsTimer;

	CLImgPoint	ip(1, 1, L'■', CLImgPoint::COLOR_BWHITE);
	CLInterface world(WORLD_X, WORLD_Y, WORLD_WIDTH, WORLD_HEIGHT, true);
	std::condition_variable cvExit;
	std::mutex mutexIsRun;

	bool isRun = true;

	//设置标题 
	mainApp.setTitle(L"俄罗斯方块");
	mainApp.setLocaleLanguage("chs");
	mainApp.setCursor(false);
	mainApp.setCosoleSize(int(WORLD_HEIGHT * 1.5), WORLD_WIDTH * 4);


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
