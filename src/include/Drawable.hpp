/**
* @file Drawable.hpp
*/
#pragma once

#include "Peek_base.hpp"

namespace peek {

	/**
	* @interface Drawable
	* @brief Something that is drawable
	*/
	class Drawable {
	public:

		/** Draws something */
		virtual void draw() = 0;

	};

}