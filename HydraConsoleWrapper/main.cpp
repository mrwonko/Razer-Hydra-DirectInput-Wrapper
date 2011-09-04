#include <iostream>
#include <string>
#include "JoystickManagement.h"
#include <cstdlib>
#include <sixense.h>
#include <Windows.h>
#include <SFML/System/Mutex.hpp>
#include <SFML/System/Thread.hpp>
#include <boost/bind.hpp>
#include <boost/ref.hpp>

bool g_Running = true;
sf::Mutex g_coutMutex;

void Error(const std::string& msg)
{
    g_coutMutex.Lock();
    std::cout<<msg<<std::endl;
    g_coutMutex.Unlock();
    g_Running = false;
}

void StartUpdating(JoystickManagement& jm)
{
    while(g_Running)
    {
        std::string message;
		//set correct base index
		if(!jm.SetBase(message))
		{
			Error(message);
			return;
		}
		//set correct controller indices
		switch(jm.SetControllerIndices(message) != JoystickManagement::eSuccess)
		{
			Error(message);
			return;
		}

		if(!jm.Update(message))
		{
			Error(message);
			return;
		}
        Sleep(16);
    }
}

struct sixenseAutoDeinit
{
    ~sixenseAutoDeinit() { sixenseExit(); }
};

int main()
{
    std::cout<<"Razer Hydra Console DirectInput Wrapper 0.4e\n\n"
    <<"Sends input to the virtual joysticks @ 60fps.\n"
    <<"Usually, the GUI program should satisfy your needs, but if it does not work for you, maybe this does.\n"<<std::endl;
    if(sixenseInit() != SIXENSE_SUCCESS)
    {
        std::cout<<"Could not initialize Sixense!"<<std::endl;
        system("PAUSE");
        return 0;
    }
    //this way I can't forget deinitializing - I just hope it won't be optimized away, I get a "warning: unused variable"
    sixenseAutoDeinit autoDeinit;

    JoystickManagement jm;
    std::string error;
    if(!jm.InitialLoad())
    {
        std::cout<<"Could not load settings!"<<std::endl;
        system("PAUSE");
        return 0;
    }

    if(!jm.InitDevices(error))
    {
        std::cout<<error<<std::endl;
        system("PAUSE");
        return 0;
    }

    //try and locate the Hydra - try multiple times because the SDK needs time to init
    for(int i = 0; i < 5; ++i)
    {
        std::cout<<"Searching base..."<<std::endl;
        if(jm.SetBase(error)) break;
        if(i == 4)
        {
            std::cout<<"Could not find base."<<std::endl;
            system("PAUSE");
            return 0;
        }
        Sleep(1000);
    }
    std::cout<<"Found it."<<std::endl;

    //start main program :)
    std::cout<<"Starting program."<<std::endl;
    sf::Thread thread(boost::bind(StartUpdating, boost::ref(jm)));
    thread.Launch();
    std::string input;
    while(input != "exit" && g_Running)
    {
        g_coutMutex.Lock();
        std::cout<<"Enter exit to exit."<<std::endl;
        g_coutMutex.Unlock();
        std::getline(std::cin, input);
    }
    g_Running = false;
    thread.Wait();

    return 0;
}
