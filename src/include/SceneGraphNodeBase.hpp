/**
* @file SceneGraphNodeBase.hpp
*/
#pragma once

#include "Peek_base.hpp"
#include "Object.hpp"
#include <handle_traits.hpp>
#include <list_traits.hpp>

namespace peek {

	/**
	* @brief The base class for a node in a scene graph
	*/
	class SceneGraphNodeBase : public Object {
	public:

		/** Draws the node */
		virtual void draw() const = 0;

		/** Draws the node for picking */
		virtual void pick() const = 0;

		typedef handle_traits<SceneGraphNodeBase>::handle_type handle;

		typedef list_traits<SceneGraphNodeBase::handle>::list_type list;

	};

}