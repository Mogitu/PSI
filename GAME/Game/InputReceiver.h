#ifndef __INPUT_RECEIVER_H__
#define __INPUT_RECEIVER_H__

#include <irrlicht.h>

using namespace irr;

class InputReceiver : public IEventReceiver
{
private:
	bool KeyIsDown[KEY_KEY_CODES_COUNT];
public:
	virtual bool OnEvent(const SEvent& event)
	{
		if (event.EventType == irr::EET_KEY_INPUT_EVENT)
			KeyIsDown[event.KeyInput.Key] = event.KeyInput.PressedDown;

		return false;
	}

	virtual bool IsKeyDown(EKEY_CODE keyCode) const
	{
		return KeyIsDown[keyCode];
	}

	InputReceiver()
	{
		for (u32 i = 0; i < KEY_KEY_CODES_COUNT; ++i)
		{
			KeyIsDown[i] = false;
		}
	}
};

#endif