/**
* @file SceneGraphNode.hpp
*/
#pragma once

#include "Peek_base.hpp"
#include "SceneGraphNodeBase.hpp"
#include <handle_traits.hpp>
#include <list_traits.hpp>

namespace peek {

	/**
	* @brief A node in a scene graph
	*/
	class SceneGraphNode : public SceneGraphNodeBase {
	public:

		/** Constructor */
		SceneGraphNode();

		/** Adds a child to the node */
		void addChild(SceneGraphNodeBase::handle child);

		/** Draws the leaf */
		virtual void draw() const;

		/** Draws the leaf for picking */
		virtual void pick() const;

		typedef handle_traits<SceneGraphNode>::handle_type handle;

		typedef list_traits<SceneGraphNode::handle>::list_type list;

	protected:

		SceneGraphNodeBase::list children;

	};

}