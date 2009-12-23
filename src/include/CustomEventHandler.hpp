/**
* @file CustomEventHandler.hpp
*/
#pragma once

#include "Peek_base.hpp"

namespace peek {

	/**
	* @interface CustomEventHandler
	* @brief Handles custom events
	*/
	class CustomEventHandler {
	public:

		/** Handles a custom event */
		virtual void handleCustomEvent(int customEvent) = 0;

	};

}