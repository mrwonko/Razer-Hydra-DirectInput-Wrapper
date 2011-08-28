/*
===========================================================================
Copyright (C) 2011 Willi Schinmeyer

This file is part of the Razer Hydra DirectInput Wrapper source code.

Razer Hydra DirectInput Wrapper source code is free software; you can redistribute it
and/or modify it under the terms of the GNU General Public License as
published by the Free Software Foundation; either version 2 of the License,
or (at your option) any later version.

Razer Hydra DirectInput Wrapper source code is distributed in the hope that it will be
useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Razer Hydra DirectInput Wrapper source code; if not, write to the Free Software
Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
===========================================================================
*/

#pragma once

#define	NUM_ANALOG	16		/* Number of analog values which we will provide */
#define	NUM_DIGITAL	16		/* Number of digital values which we will provide */

#pragma pack(push,1)		/* All fields in structure must be byte aligned. */

struct JoystickState
{
	unsigned long	Signature;				/* Signature to identify packet to PPJoy IOCTL */
	char			NumAnalog;				/* Num of analog values we pass */
	long			Analog[NUM_ANALOG];		/* Analog values */
	char			NumDigital;				/* Num of digital values we pass */
	char			Digital[NUM_DIGITAL];	/* Digital values */
};

#pragma pack(pop)