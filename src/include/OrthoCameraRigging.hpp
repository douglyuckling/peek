/**
 * \file OrthoCameraRigging.hpp
 * \author Douglas W. Paul
 *
 * Declares the OrthoCameraRigging interface
 */

#pragma once

#include "CameraRigging.hpp"
#include "OrthographicCamera.hpp"

namespace peek {

	/**
	 * \interface OrthoCameraRigging
	 * \brief An interface for riggings for orthographic cameras
	 */
	class OrthoCameraRigging : public virtual CameraRigging {
	 public:

	  /** Provides access to the orthographic camera being rigged */
	  virtual OrthographicCamera *getOrthoCamera() = 0;

	};

}