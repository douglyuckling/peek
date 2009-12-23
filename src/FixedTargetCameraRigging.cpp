/**
 * \file FixedTargetCameraRigging.cpp
 * \author Douglas W. Paul
 *
 * Defines the behavior of the FixedTargetCameraRigging class.
 */

#include "Peek_base.hpp"
#include "FixedTargetCameraRigging.hpp"

namespace peek {

	/**
	 * \param camera The camera to be rigged
	 * \param longitude The yaw of the camera
	 * \param latitude The pitch of the camera
	 * \param distance The distance from the camera to the origin
	 */
	FixedTargetCameraRigging::FixedTargetCameraRigging(Camera::handle camera, double longitude, double latitude, double distance) {
		this->camera = camera;
		this->longitude = longitude;
		this->latitude = latitude;
		this->distance = distance;
	}

	FixedTargetCameraRigging::~FixedTargetCameraRigging() {}

	void FixedTargetCameraRigging::initModelviewMatrix() {
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		glTranslated(0.0, 0.0, -this->distance);
		glRotated(this->latitude-90.0, 1.0, 0.0, 0.0);
		glRotated(-this->longitude-90.0, 0.0, 0.0, 1.0);
	}

	/**
	 * \param deltaLongitude Amount to change the longitude of the camera, in degrees
	 */
	void FixedTargetCameraRigging::changeLongitude(double deltaLongitude) {
		this->longitude += deltaLongitude;

		// Make sure the value is in the range [0, 360)...
		while (this->longitude < 0.0) {
			this->longitude += 360.0;
		}

		while (this->longitude >= 360.0) {
			this->longitude -= 360.0;
		}
	}

	/**
	 * \param deltaLatitude Amount to change the latitude of the camera, in degrees
	 */
	void FixedTargetCameraRigging::changeLatitude(double deltaLatitude) {
		this->latitude += deltaLatitude;

		// Make sure the value is in the range [-90, 90]...
		if (this->latitude > 90.0) {
			this->latitude = 90.0;
		}
		else if (this->latitude < -90.0) {
			this->latitude = -90.0;
		}
	}

	/**
	 * \param deltaDistance The amount to change the distance from the target, in units
	 */
	void FixedTargetCameraRigging::changeDistance(double deltaDistance) {
		this->distance += deltaDistance;

		// Make sure the value is in the range [0, inf)...
		if (this->distance < 0.0) {
			this->distance = 0.0;
		}
	}

}
