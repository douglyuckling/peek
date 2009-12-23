/**
 * @file Light.hpp
 */
#pragma once

// Implementation dependencies
#include "Geometry.hpp"
#include "Color.hpp"

namespace peek {

	class Light {
	public:
		inline Light(const Point3f location, const Color ambient, const Color diffuse, const Color specular) {
			this->location = location;
			this->ambient = ambient;
			this->diffuse = diffuse;
			this->specular = specular;
		}

		inline Point3f getLocation() const { return this->location; }
		inline Color getAmbient() const { return this->ambient; }
		inline Color getDiffuse() const { return this->diffuse; }
		inline Color getSpecular() const { return this->specular; }

		inline void setLocation(const Point3f &location) { this->location = location; }
		inline void setAmbient(const Color &ambient) { this->ambient = ambient; }
		inline void setDiffuse(const Color &diffuse) { this->diffuse = diffuse; }
		inline void setSpecular(const Color &specular) { this->specular = specular; }

	private:
		Point3f location;
		Color ambient;
		Color diffuse;
		Color specular;
	};

	void initLight(GLenum lightNum, const Light &light);

}
