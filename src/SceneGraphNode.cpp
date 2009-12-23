/**
* @file SceneGraphNode.cpp
*/

#include "SceneGraphNode.hpp"

namespace peek {

	SceneGraphNode::SceneGraphNode() {
	}

	void SceneGraphNode::addChild(SceneGraphNodeBase::handle child) {
		this->children.push_back(child);
	}

	void SceneGraphNode::draw() const {
		for (SceneGraphNodeBase::list::const_iterator i = this->children.begin(); i < this->children.end(); ++i) {
			(*i)->draw();
		}
	}

	void SceneGraphNode::pick() const {
		for (SceneGraphNodeBase::list::const_iterator i = this->children.begin(); i < this->children.end(); ++i) {
			(*i)->pick();
		}
	}

}