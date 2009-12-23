/**
 * @file Material.hpp
 */
#pragma once

// Implementation dependencies
#include "Color.hpp"

namespace peek {

	class Material {
	public:
		inline Material() {this->shininess = 0.0;}
		inline Material(const Color ambient, const Color diffuse, const Color specular, const Color emission, float shininess) {
			this->ambient = ambient;
			this->diffuse = diffuse;
			this->specular = specular;
			this->emission = emission;
			this->shininess = shininess;
		}

		inline Color getAmbient() const { return this->ambient; }
		inline Color getDiffuse() const { return this->diffuse; }
		inline Color getSpecular() const { return this->specular; }
		inline Color getEmission() const { return this->emission; }
		inline float getShininess() const { return this->shininess; }

		inline void setAmbient(const Color &ambient) { this->ambient = ambient; }
		inline void setDiffuse(const Color &diffuse) { this->diffuse = diffuse; }
		inline void setSpecular(const Color &specular) { this->specular = specular; }
		inline void setEmission(const Color &emission) { this->emission = emission; }
		inline void setShininess(float shininess) { this->shininess = shininess; }

		static const Material DEFAULT;

	private:
		Color ambient;
		Color diffuse;
		Color specular;
		Color emission;
		float shininess;
	};

	void useMaterial(GLenum face, const Material &material);

}
