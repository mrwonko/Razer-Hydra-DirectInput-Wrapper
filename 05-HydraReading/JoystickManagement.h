#ifndef JOYSTICK_MANAGEMENT_H
#define JOYSTICK_MANAGEMENT_H

#include <Windows.h>
#include <string>
#include "ControllerMapping.h"
#include "JoystickState.h"



class JoystickManagement
{
public:
	static std::wstring GetDefaultIniFilename(const bool left);

	static std::wstring GetDefaultIniFilename(int side);
public:
	JoystickManagement();
	~JoystickManagement(void);

	enum returnValue
	{
		eSuccess,
		eError, //error occured, please abort
		eMessage, //please display this message, we can't continue but may in the future.
	};

	/** \brief Sets the active base to the first one connected
		\return Whether any bases are connected
		\note In debug mode, returns true and sets the active base to 0 if none are connected.
	**/
	const bool SetBase(std::string& error);

	/** \brief initializes the PPJoy devices
	**/
	const bool InitDevices(std::string& error);

	/** \brief First time loading - loads both mappings & origins
	**/
	const bool InitialLoad();

	static const int LEFT_CONTROLLER = 0;
	static const int RIGHT_CONTROLLER = 1;

	/**	\brief Checks if the controllers are correctly initalized (i.e. have been in the base once, but on different sides)
		and sets mLeftControllerIndex and mRightControllerIndex accordingly.
		\return Whether the controllers are correctly initialized
	**/
	const returnValue SetControllerIndices(std::string& message);

	ControllerMapping mControllerMappings[2]; // 0 = left, 1 = right

	/** \brief Updates the Hydra
	**/
	void Update();

	float mOrigins[2][3];

	const bool LoadOrigin(int side);
	const bool SaveOrigin(int side);
		
	static const unsigned int NUM_VIRTUAL_JOYSTICKS = 4;

	const bool Update(std::string& error);

	int mControllerIndices[2];
private:

	HANDLE mJoyHandles[NUM_VIRTUAL_JOYSTICKS];
	JoystickState mJoyStates[NUM_VIRTUAL_JOYSTICKS];
};

#endif