/**
* @file KeyEventHandler.hpp
*/
#pragma once

#include "Peek_base.hpp"

namespace peek {

	/**
	* @interface KeyEventHandler
	* @brief Handles keyboard events
	*/
	class KeyEventHandler {
	public:

		/** Handles a keyboard event */
		virtual void handleKeyEvent(const SDL_KeyboardEvent &keyEvent, int x, int y) = 0;

	};

}