/**
* @file SceneGraphLeaf.hpp
*/
#pragma once

#include "Peek_base.hpp"
#include "SceneGraphNodeBase.hpp"
#include "Model.hpp"
#include <handle_traits.hpp>
#include <list_traits.hpp>

namespace peek {

	/**
	* @brief A leaf in a scene graph
	*/
	class SceneGraphLeaf : public SceneGraphNodeBase {
	public:

		/** Constructor */
		SceneGraphLeaf(Model::handle model);

		/** Draws the leaf */
		virtual void draw() const;

		/** Draws the leaf for picking */
		virtual void pick() const;

		typedef handle_traits<SceneGraphLeaf>::handle_type handle;

		typedef list_traits<SceneGraphLeaf::handle>::list_type list;

	protected:

		Model::handle model;

	};

}