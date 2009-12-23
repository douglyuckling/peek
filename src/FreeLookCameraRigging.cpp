/**
 * \file FreeLookCameraRigging.cpp
 * \author Douglas W. Paul
 *
 * Defines the behavior of the FreeLookCameraRigging class.
 */

#include "Peek_base.hpp"
#include "FreeLookCameraRigging.hpp"

namespace peek {

	FreeLookCameraRigging::FreeLookCameraRigging(Camera::handle camera, Point3d location, double yaw, double pitch) {
		this->camera = camera;
		this->location = location;
		this->yaw = yaw;
		this->pitch = pitch;
	}

	FreeLookCameraRigging::~FreeLookCameraRigging() {}

	void FreeLookCameraRigging::initModelviewMatrix() {
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		glRotated(-this->pitch, 1.0, 0.0, 0.0);
		glRotated(90.0-this->yaw, 0.0, 0.0, 1.0);
		glTranslated(-this->location.x, -this->location.y, -this->location.z);
	}

	/**
	 * \param deltaLocation Vector by which to change the location of the camera
	 */
	void FreeLookCameraRigging::changeLocation(Vector3d deltaLocation) {
		this->location += deltaLocation;
	}

	/**
	 * \param deltaYaw Amount to change the yaw of the camera, in degrees
	 */
	void FreeLookCameraRigging::changeYaw(double deltaYaw) {
		this->yaw += deltaYaw;

		// Make sure the value is in the range [0, 360)...
		while (this->yaw < 0.0) {
			this->yaw += 360.0;
		}

		while (this->yaw >= 360.0) {
			this->yaw -= 360.0;
		}
	}

	/**
	 * \param deltaPitch Amount to change the pitch of the camera, in degrees
	 */
	void FreeLookCameraRigging::changePitch(double deltaPitch) {
		this->pitch += deltaPitch;

		// Make sure the value is in the range [-90, 90]...
		if (this->pitch > 90.0) {
			this->pitch = 90.0;
		}
		else if (this->pitch < -90.0) {
			this->pitch = -90.0;
		}
	}

}