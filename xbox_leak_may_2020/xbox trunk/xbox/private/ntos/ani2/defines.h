//
//	defines.h
//
///////////////////////////////////////////////////////////////////////////////
//  Copyright (C) 2001, Pipeworks Software Inc.
//				All rights reserved
#ifndef __DEFINES_H__
#define __DEFINES_H__


//#define FINAL_BUILD



const float DEMO_TOTAL_TIME = 8.0f;
const float FINAL_HOLD_TIME	= 2.0f;
const float FINISH_TRANSITION_TIME = 0.8f;

#define TEXT_ANIM_START_TIME                (DEMO_TOTAL_TIME - FINAL_HOLD_TIME)
const float TEXT_ANIM_LEN = 0.25f;


const float BLOB_STATIC_END_TIME = 0.6f;
#define OO_BLOB_STATIC_END_TIME				(1.0f / BLOB_STATIC_END_TIME)
#define BLOB_ZERO_INTENSE_END_TIME			(BLOB_STATIC_END_TIME + 0.5f)
const float BLOB_BASE_INTENSITY = 0.3f;

#define FINISH_START_TIME					(DEMO_TOTAL_TIME - FINAL_HOLD_TIME - FINISH_TRANSITION_TIME)
#define FINISH_STOP_TIME					(DEMO_TOTAL_TIME - FINAL_HOLD_TIME)
#define OO_FINISH_DELTA						(1.0f / FINISH_TRANSITION_TIME)

#define MAX_INTENSITY_TIME					(FINISH_START_TIME - 0.0f)
#define MAX_INTENSITY_DELTA					(MAX_INTENSITY_TIME - BLOB_ZERO_INTENSE_END_TIME)
#define OO_MAX_INTENSITY_DELTA				(1.0f / MAX_INTENSITY_DELTA)
const float DEMO_START_INTENSITY = 0.0f;


// For timing the blob pulses.
#define BLOB_PULSE_START					(BLOB_STATIC_END_TIME)
#define BLOB_PULSE_END						(FINISH_STOP_TIME - 0.4f)
#define BLOB_PULSE_ELAPSED					(BLOB_PULSE_END - BLOB_PULSE_START)

#define BLOB_JITTER_START					(BLOB_STATIC_END_TIME)
#define BLOB_JITTER_DELTA					(FINISH_START_TIME)
#define OO_BLOB_JITTER_DELTA				(1.0f / BLOB_JITTER_DELTA)


const float SCENE_ANIM_LEN = 4.5f;
#define SCENE_ANIM_START_TIME				(BLOB_STATIC_END_TIME + 0.25f)


const float START_PUSHOUT_RADIUS = 0.0f;
const float PUSHOUT_START_TIME = 0.5f;
const float PUSHOUT_DELTA = 2.7f;
#define OO_PUSHOUT_DELTA					(1.0f / PUSHOUT_DELTA)


#define SHIELD_FADE_IN_START_TIME			(BLOB_STATIC_END_TIME)
const float SHIELD_FADE_IN_DELTA = 1.2f;
#define OO_SHIELD_FADE_IN_DELTA				(1.0f / SHIELD_FADE_IN_DELTA)
#define SHIELD_FADE_OUT_START_TIME			(FINISH_START_TIME - 0.1f)
#define SHIELD_FADE_OUT_DELTA				(FINISH_TRANSITION_TIME * 0.2f)
#define OO_SHIELD_FADE_OUT_DELTA			(1.0f / SHIELD_FADE_OUT_DELTA)


#define GLOW_FADE_CIRCLE_START				(FINISH_START_TIME - 0.5f)
#define GLOW_FADE_CIRCLE_MUL				(1.0f / 0.3f)

#define GLOW_FADE_SCREEN_START				(GLOW_FADE_CIRCLE_START + 0.3f)
#define GLOW_FADE_SCREEN_MUL				(1.0f / 0.25f)


#define SLASH_GRADIENT_TRANSITION_START		(FINISH_START_TIME - 0.5f)
//MTS#define SLASH_GRADIENT_TRANSITION_END		(FINISH_STOP_TIME + 0.75f)
#define SLASH_GRADIENT_TRANSITION_END		(FINISH_STOP_TIME)
#define SLASH_GRADIENT_TRANSITION_MUL		(1.0f / (SLASH_GRADIENT_TRANSITION_END - SLASH_GRADIENT_TRANSITION_START))

#define SCENE_LO_DETAIL_START               (FINISH_START_TIME)

#ifdef STARTUPANIMATION
#define FINAL_BUILD
#endif // STARTUPANIMATION




#ifndef FINAL_BUILD

#define INCLUDE_PLACEMENT_DOODAD
#define INCLUDE_INPUT

#endif






#endif // __DEFINES_H__