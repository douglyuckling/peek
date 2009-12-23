/**
* @file ResizeEventHandler.hpp
*/
#pragma once

#include "Peek_base.hpp"

namespace peek {

	/**
	* @interface ResizeEventHandler
	* @brief Handles resize events
	*/
	class ResizeEventHandler {
	public:

		/** Handles a resize event */
		virtual void handleResizeEvent(int sizeX, int sizeY) = 0;

	};

}