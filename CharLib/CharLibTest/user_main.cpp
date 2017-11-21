#include "user_main.h"

#include "CBlockManager.h"

using namespace cl;
using namespace gm;

//#define _WINDO

constexpr long WORLD_X = 25;
constexpr long WORLD_Y = 4;

constexpr long WORLD_WIDTH = 30;
constexpr long WORLD_HEIGHT = 20;

constexpr int GAME_SPEED = 500;
constexpr int GAME_FSTIME = 50;

int user_main(int argc, char * argv[])
{
	//以下是系统管理
	CMainApp	mainApp(argc, argv);
	CLSysCtrl	ctrl;
	CLSysTimer	fpsTimer;
	CLSysTimer	gameTimer;

	CLInterface world(WORLD_X, WORLD_Y, WORLD_WIDTH, WORLD_HEIGHT, true);
	std::condition_variable cvExit;
	std::mutex mutexIsRun;

	bool isRun = true;
	//以上是系统管理

	//以下是游戏元素
	//CBlock	blockTest;
	CBlockManager bm;
	//以上是游戏元素

	//设置标题 
	mainApp.setTitle(L"俄罗斯方块");
	mainApp.setLocaleLanguage("");
	mainApp.setCursor(false);
	mainApp.setCosoleSize(int(WORLD_HEIGHT * 1.5), WORLD_WIDTH * 4);

	ctrl.connect_event([&]() -> void {
		static bool inter = true;
		CLSysCtrl::msg_type msg = ctrl.getMsg();

		switch (msg)
		{
		case CLSysCtrl::KEY_UP:

			bm.changeActive();
			break;
		case CLSysCtrl::KEY_DOWN:
			bm.freezeActive();
			break;
		case CLSysCtrl::KEY_LEFT:

			bm.moveLeftActive();
			break;
		case CLSysCtrl::KEY_RIGHT:
			bm.moveRightActive();

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

	fpsTimer.setTimer(GAME_FSTIME, [&]()->void {
		bm.flash();
		world.addImgPointGroup(bm.getImageGroup());
		world.render();
		world.clear();
	});

	gameTimer.setTimer(GAME_SPEED, [&]()->void {

		bm.moveDropActive();
	});

	ctrl.start_listen();
	fpsTimer.startTimer();
	gameTimer.startTimer();
	std::unique_lock<std::mutex> locker(mutexIsRun);
	cvExit.wait(locker, [&isRun]()->bool {return !isRun; });

	fpsTimer.stopTimer();
	gameTimer.startTimer();
	ctrl.stop_listen();

	return EXIT_SUCCESS;
}
