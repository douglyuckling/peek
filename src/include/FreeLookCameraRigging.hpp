/**
 * \file FreeLookCameraRigging.hpp
 * \author Douglas W. Paul
 *
 * Delcares the FreeLookCameraRigging class
 */

#pragma once

#include "CameraRigging.hpp"

namespace peek {

	/**
	 * A camera rigging that can translate and rotate freely in threespace.
	 */
	class FreeLookCameraRigging : public CameraRigging {
	public:

		/** Constructs a free camera rigging with the given attributes */
		FreeLookCameraRigging(Camera::handle camera, Point3d location, double yaw, double pitch);

		/** Destructor */
		virtual ~FreeLookCameraRigging();

		/** Initializes the modelview matrix based on the camera's pose */
		void initModelviewMatrix();

		/** Provides access to the camera being rigged */
		inline Camera *getCamera() { return this->camera.get(); }

		/** Provides access to the camera's location */
		inline Point3d getLocation() { return this->location; }

		/** Sets the location of the camera */
		inline void setLocation(Point3d location) { this->location = location; }

		/** Changes the location of the camera */
		void changeLocation(Vector3d deltaLocation);

		/** Provides access to the camera's yaw */
		inline double getYaw() { return this->yaw; }

		/** Changes the yaw of the camera */
		void changeYaw(double deltaYaw);

		/** Provides access to the camera's pitch */
		inline double getPitch() { return this->pitch; }

		/** Changes the pitch of the camera */
		void changePitch(double deltaPitch);

		typedef handle_traits<FreeLookCameraRigging>::handle_type handle;

	protected:

		/** The camera being rigged */
		Camera::handle camera;

		/** The location of the camera in worldspace */
		Point3d location;

		/** Yaw */
		double yaw;

		/** Pitch */
		double pitch;

	};

}