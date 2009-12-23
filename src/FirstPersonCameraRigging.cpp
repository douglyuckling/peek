/**
 * \file FirstPersonCameraRigging.cpp
 * \author Douglas W. Paul
 *
 * Defines the behavior of the FirstPersonCameraRigging class.
 */

#include "Peek_base.hpp"
#include "FirstPersonCameraRigging.hpp"

/** Amount to move the camera in the x-direction */
#define X_STEP 0.25

/** Amount to move the camera in the y-direction */
#define Y_STEP X_STEP

/** Amount to move the camera in the z-direction */
#define Z_STEP 0.25

/** Sensitivity of the mouse for mouselook */
#define MOUSE_SENSITIVITY 0.1

/** Left-right turn interval (in degrees) */
#define TURN_STEP 12.5

namespace peek {
	
	FirstPersonCameraRigging::FirstPersonCameraRigging(Camera::handle camera, Point3d location, double yaw, double pitch) 
		: FreeLookCameraRigging(camera, location, yaw, pitch) {}

	FirstPersonCameraRigging::~FirstPersonCameraRigging() {}

	/*!
	 */
	void FirstPersonCameraRigging::moveForward() {
		// Generate a vector for the player's direction in the XY plane
		double x, y;
		x = cos(this->yaw*PI/180.0);
		y = sin(this->yaw*PI/180.0);
		// Add the vector (times a length multiplier) to the player's position
		this->location += Y_STEP * Vector3d(x, y, 0);
	}

	/*!
	 */
	void FirstPersonCameraRigging::moveBackward() {
		// Generate a vector for the player's direction in the XY plane
		double x, y;
		x = cos(this->yaw*PI/180.0);
		y = sin(this->yaw*PI/180.0);
		// Add the vector (times a length multiplier) to the player's position
		this->location -= Y_STEP * Vector3d(x, y, 0);
	}

	/*!
	 */
	void FirstPersonCameraRigging::moveLeft() {
		// Generate a vector for the player's direction in the XY plane
		double x, y;
		x = cos((this->yaw+90.0)*PI/180.0);
		y = sin((this->yaw+90.0)*PI/180.0);
		// Add the vector (times a length multiplier) to the player's position
		this->location += X_STEP * Vector3d(x, y, 0);
	}

	/*!
	 */
	void FirstPersonCameraRigging::moveRight() {
		// Generate a vector for the player's direction in the XY plane
		double x, y;
		x = cos((this->yaw-90.0)*PI/180.0);
		y = sin((this->yaw-90.0)*PI/180.0);
		// Add the vector (times a length multiplier) to the player's position
		this->location += X_STEP * Vector3d(x, y, 0);
	}

	/*!
	 */
	void FirstPersonCameraRigging::moveUp() {
	  this->location.z += Z_STEP;
	}

	/*!
	 */
	void FirstPersonCameraRigging::moveDown() {
		this->location.z -= Z_STEP;
	}

	/*!
	 */
	void FirstPersonCameraRigging::turnLeft() {
		this->yaw += TURN_STEP;
	}

	/*!
	 */
	void FirstPersonCameraRigging::turnRight() {
		this->yaw -= TURN_STEP;
	}

	/*!
	 * @param dX Change in x screen-coordinate (in pixels)
	 * @param dY Change in y screen-coordinate (in pixels)
	 */
	void FirstPersonCameraRigging::look(int dX, int dY) {
		this->yaw -= (float)dX * 0.1;
		this->pitch -= (float)dY * 0.1;
	}

}