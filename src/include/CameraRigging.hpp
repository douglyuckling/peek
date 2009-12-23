/**
 * \file CameraRigging.hpp
 * \author Douglas W. Paul
 *
 * Declares the CameraRigging interface
 */

#pragma once

#include "Camera.hpp"

namespace peek {

	/**
	 * \interface CameraRigging
	 * \brief An interface for camera riggings
	 *
	 * A camera rigging is a system which controls the movement of a camera.
	 */
	class CameraRigging {
	 public:

	  /** Initializes the modelview matrix based on the camera's pose */
	  virtual void initModelviewMatrix() = 0;

	  /** Provides access to the camera being rigged */
	  virtual Camera *getCamera() = 0;

	};

}