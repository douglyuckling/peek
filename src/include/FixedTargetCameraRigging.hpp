/**
 * \file FixedTargetCameraRigging.hpp
 * \author Douglas W. Paul
 *
 * Delcares the FixedTargetCameraRigging class
 */

#pragma once

#include "CameraRigging.hpp"

namespace peek {

	/**
	 * A camera that always points towards the origin
	 *
	 * Imagine a sphere centered around the worldspace origin.  This camera is
	 * always on the surface of that sphere, pointing at the origin.  The camera's
	 * location on the sphere, as well as the radius of the sphere, can be
	 * adjusted.  Thus, this rigging has three degrees of freedom.
	 */
	class FixedTargetCameraRigging : public CameraRigging {
	public:

		/** Constructs a free camera rigging with the given attributes */
		FixedTargetCameraRigging(Camera::handle camera, double theta, double phi, double distance);

		/** Destructor */
		virtual ~FixedTargetCameraRigging();

		/** Initializes the modelview matrix based on the camera's pose */
		void initModelviewMatrix();

		/** Provides access to the camera being rigged */
		inline Camera *getCamera() { return this->camera.get(); }

		/** Changes the distance of the camera from its target */
		void changeDistance(double deltaDistance);

		/** Changes the longitude of the camera relative to its target */
		void changeLongitude(double deltaLongitude);

		/** Changes the latitude of the camera relative to its target */
		void changeLatitude(double deltaLatitude);

		/** Provides access to the camera's distance from its target */
		inline double getDistance() { return this->distance; }

		typedef handle_traits<FixedTargetCameraRigging>::handle_type handle;

	protected:

		/** The camera being rigged */
		Camera::handle camera;

		/** The longitude of the camera relative to its target, in degrees */
		double longitude;

		/** The latitude of the camera relative to its target, in degrees */
		double latitude;

		/** The distance from the camera to its target */
		double distance;

	};

}