/**
* @file SceneGraphLeaf.cpp
*/

#include "SceneGraphLeaf.hpp"

namespace peek {

	SceneGraphLeaf::SceneGraphLeaf(Model::handle model) {
		this->model = model;
	}

	void SceneGraphLeaf::draw() const {
		this->model->draw();
	}

	void SceneGraphLeaf::pick() const {
		this->model->pick();
	}

}