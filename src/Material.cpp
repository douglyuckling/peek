/**
* @file Material.cpp
*/

#include "Peek_base.hpp"
#include "Material.hpp"

namespace peek {

	void useMaterial(GLenum face, const Material &material) {
		glMaterialfv(face, GL_AMBIENT, material.getAmbient().c);
		glMaterialfv(face, GL_DIFFUSE, material.getDiffuse().c);
		glMaterialfv(face, GL_SPECULAR, material.getSpecular().c);
		glMaterialfv(face, GL_EMISSION, material.getEmission().c);
		glMaterialf(face, GL_SHININESS, material.getShininess());
	}

	const Material Material::DEFAULT(Color(0.2f, 0.2f, 0.2f), Color(0.9f, 0.9f, 0.9f),
									 Color(1.0f, 1.0f, 1.0f), Color(0.0f, 0.0f, 0.0f), 40.0f);

}