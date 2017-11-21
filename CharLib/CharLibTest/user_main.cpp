#include "user_main.h"

#include "CBlockManager.h"
#include "CText.h"

using namespace cl;
using namespace gm;

//#define _WINDO

constexpr long WORLD_X = 10;
constexpr long WORLD_Y = 4;

constexpr long WORLD_WIDTH = 13;
constexpr long WORLD_HEIGHT = 20;

constexpr int GAME_SPEED = 600;
constexpr int GAME_FSTIME = 50;


std::condition_variable cvExit;
std::mutex mutexIsRun;
std::mutex mutexWorld;
bool isRun = true;
bool inter = true;

void stopGame()
{
	if (inter)
	{
		std::unique_lock<std::mutex> locker(mutexIsRun);
		isRun = false;
		locker.unlock();

		inter = false;
		cvExit.notify_one();
	}
}

int user_main(int argc, char * argv[])
{
	//以下是系统管理
	CMainApp	mainApp(argc, argv);
	CLSysCtrl	ctrl;
	CLSysTimer	fpsTimer;
	CLSysTimer	gameTimer;

	CLInterface world(WORLD_X, WORLD_Y, WORLD_WIDTH, WORLD_HEIGHT, true);



	//以上是系统管理

	//以下是游戏元素
	//CBlock	blockTest;
	CBlockManager bm(WORLD_HEIGHT, WORLD_WIDTH);
	CText textGameOver(L"游戏结束", 2, 3, CLImgPoint::COLOR_LYELLOW);
	CText textStop(L"按任意键退出", 2, 5, CLImgPoint::COLOR_LYELLOW);

	//以上是游戏元素

	//设置标题 
	mainApp.setTitle(L"俄罗斯方块");
	mainApp.setLocaleLanguage("");
	mainApp.setCursor(false);
	mainApp.setCosoleSize(int(WORLD_HEIGHT * 1.5), WORLD_WIDTH * 4);

	ctrl.connect_event([&]() -> void {

		CLSysCtrl::msg_type msg = ctrl.getMsg();

		switch (msg)
		{
		case CLSysCtrl::KEY_UP:
			bm.changeActive();
			break;
		case CLSysCtrl::KEY_DOWN:
			bm.dropToEndActive();
			break;
		case CLSysCtrl::KEY_LEFT:
			bm.moveLeftActive();
			break;
		case CLSysCtrl::KEY_RIGHT:
			bm.moveRightActive();
			break;
		case CLSysCtrl::KEY_ESC:
			stopGame();
			break;
		default:
			break;
		}
	});

	fpsTimer.setTimer(GAME_FSTIME, [&]()->void {
		bm.flash();
		std::unique_lock<std::mutex> lock(mutexWorld);
		world.addImgPointGroup(bm.getImageGroup());
		world.render();
		world.clear();
		lock.unlock();
	});

	gameTimer.setTimer(GAME_SPEED, [&]()->void {
		if (bm.isEnd())
		{
			fpsTimer.stopTimer();//停止FPS帧率定时器的工作
			std::unique_lock<std::mutex> lock(mutexWorld);
			world.addImgPointGroup(textGameOver.getImageGroup());
			world.addImgPointGroup(textStop.getImageGroup());
			world.render();
			world.clear();
			lock.unlock();
			stopGame();
		}
		bm.dropActive();
	});

	ctrl.start_listen();
	fpsTimer.startTimer();
	gameTimer.startTimer();
	std::unique_lock<std::mutex> locker(mutexIsRun);
	cvExit.wait(locker, [&]()->bool {return !isRun; });

	fpsTimer.stopTimer();
	gameTimer.startTimer();
	ctrl.stop_listen();

	return EXIT_SUCCESS;
}
