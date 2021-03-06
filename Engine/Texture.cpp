#include "Texture.h"

Texture2D::Texture2D() :width(0), height(0), internalFormat(GL_RGB), imageFormat(GL_RGB), wrapS(GL_REPEAT), wrapT(GL_REPEAT), filterMin(GL_LINEAR), filterMax(GL_LINEAR)
{
	glGenTextures(1, &this->ID);
}

void Texture2D::generate(GLuint widthIn, GLuint heightIn, unsigned char* data)
{
	width = widthIn;
	height = heightIn;

	glBindTexture(GL_TEXTURE_2D, this->ID);
	glTexImage2D(GL_TEXTURE_2D, 0, internalFormat, width, height, 0, imageFormat, GL_UNSIGNED_BYTE, data);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, wrapS);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, wrapT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, filterMin);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, filterMax);

	glBindTexture(GL_TEXTURE_2D, 0);
}

void Texture2D::bind() const
{
	glBindTexture(GL_TEXTURE_2D, this->ID);
}