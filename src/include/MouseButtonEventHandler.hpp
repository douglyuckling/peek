/**
* @file MouseButtonEventHandler.hpp
*/
#pragma once

#include "Peek_base.hpp"

namespace peek {

	/**
	* @interface MouseButtonEventHandler
	* @brief Handles mouse button events
	*/
	class MouseButtonEventHandler {
	public:

		/** Handles a mouse button event */
		virtual void handleMouseButtonEvent(const SDL_MouseButtonEvent &buttonEvent) = 0;

	};

}