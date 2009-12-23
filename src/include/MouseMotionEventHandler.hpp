/**
* @file MouseMotionEventHandler.hpp
*/
#pragma once

#include "Peek_base.hpp"

namespace peek {

	/**
	* @interface MouseMotionEventHandler
	* @brief Handles mouse motion events
	*/
	class MouseMotionEventHandler {
	public:

		/** Handles a mouse motion event */
		virtual void handleMouseMotionEvent(const SDL_MouseMotionEvent &motionEvent) = 0;

	};

}