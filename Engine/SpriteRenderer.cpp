#include "SpriteRenderer.h"


spriteRenderer::spriteRenderer(Shader &shaderIn)
{
	shader = shaderIn;
	initRenderData();
}


spriteRenderer::~spriteRenderer()
{
	glDeleteVertexArrays(1, &this->quadVAO);
}

void spriteRenderer::drawSprite(Texture2D & texture, meow::vec2 position, meow::vec2 size, GLfloat rotate, meow::vec3 color)
{
	shader.use();
	meow::mat4 model;
	model = model * meow::translate(meow::vec3{ position.x, position.y, 0.0f });

	model = model * meow::translate(meow::vec3{ 0.5f * size.x, 0.5f * size.y, 0.0f });
	model = model * meow::rotate(meow::vec3{ 0.0f, 0.0f, 1.0f }, rotate);
	model = model * meow::translate(meow::vec3{ -0.5f * size.x, -0.5f * size.y, 0.0f });

	model = model * meow::scale(meow::vec3{ size.x, size.y, 1.0f });

	shader.setMatrix4("model", model);

	shader.setVector3f("spriteColor", color);

	glActiveTexture(GL_TEXTURE0);
	texture.bind();

	glBindVertexArray(quadVAO);
	glDrawArrays(GL_TRIANGLES, 0, 6);
	glBindVertexArray(0);
}

void spriteRenderer::initRenderData()
{
	GLuint VBO;
	GLfloat vertices[] = { 0.0f, 1.0f,0.0f,1.0f,1.0f,0.0f,1.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,1.0f,0.0f,1.0f,1.0f,1.0f,1.0f,1.0f,1.0f,0.0f,1.0f,0.0f };

	glGenVertexArrays(1, &this->quadVAO);
	glGenBuffers(1, &VBO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindVertexArray(quadVAO);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), (GLvoid*)0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}
