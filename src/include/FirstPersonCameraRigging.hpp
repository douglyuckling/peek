/**
 * \file FreeLookCameraRigging.hpp
 * \author Douglas W. Paul
 *
 * Delcares the FreeLookCameraRigging class
 */

#pragma once

#include "FreeLookCameraRigging.hpp"

namespace peek {

	/**
	 * A camera that can translate and rotate freely in threespace, much like a person
	 * can walk through the world and look around.
	 */
	class FirstPersonCameraRigging : public FreeLookCameraRigging {
	public:

		/** Constructs a free camera rigging with the given attributes */
		FirstPersonCameraRigging(Camera::handle camera, Point3d location, double yaw, double pitch);

		/** Destructor */
		virtual ~FirstPersonCameraRigging();

		/** Moves the camera forward */
		void moveForward();

		/** Moves the camera backward */
		void moveBackward();

		/** Moves the camera left */
		void moveLeft();

		/** Moves the camera right */
		void moveRight();

		/** Moves the camera up */
		void moveUp();

		/** Moves the camera down */
		void moveDown();

		/** Turns the camera left */
		void turnLeft();

		/** Turns the camera right */
		void turnRight();

		/** Uses changes in mouse coordinates to rotate the camera */
		void look(int dX, int dY);

		typedef handle_traits<FirstPersonCameraRigging>::handle_type handle;

	};
}