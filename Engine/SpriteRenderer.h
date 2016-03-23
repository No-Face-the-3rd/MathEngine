#pragma once


#ifndef SPRITE_RENDERER_H
#define SPRITE_RENDERER_H

#include <GL/glew.h>

#include <Math/mat4.h>

#include "Texture.h"
#include "Shader.h"

class spriteRenderer
{
public:
	spriteRenderer(Shader &shaderIn);
	~spriteRenderer();

	void drawSprite(Texture2D &texture, meow::vec2 position, meow::vec2 size = meow::vec2{ 10,10 }, GLfloat rotate = 0.0f, meow::vec3 color = meow::vec3{ 1.0f,1.0f,1.0f });
private:
	Shader shader;
	GLuint quadVAO;

	void initRenderData();
};


#endif