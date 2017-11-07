#include "user_main.h"

gm::CMainApp	*mainApp;
cl::CLSysCtrl	ctrl;

void event_msg()
{
	cl::CLSysCtrl::msg_type msg = ctrl.getMsg();
	if (msg)
		std::cout << msg << std::endl;
}

int user_main(int argc, char * argv[])
{
	mainApp = new gm::CMainApp(argc, argv);
	
	mainApp->setTitle(L"CharLib≤‚ ‘");

	ctrl.connect_event(event_msg);
	ctrl.start_listen();
	Sleep(-1);

	ctrl.stop_listen();

	delete mainApp;

	return EXIT_SUCCESS;
}
