#pragma once

#ifndef GAME_H
#define GAME_H

#include <GL/GL.h>
#include <GLFW/glfw3.h>

#include <vector>

enum gameStateEnum { SPLASH, MENU_INIT, MENU, PLAY_INIT, PLAY, PAUSE, LOSE };

class Game
{
public:
	gameStateEnum gs;
	GLuint width, height;
	GLboolean keys[1024], keysProcessed[1024], mouse[3], mouseProcessed[3], shouldClose;

	Game();
	Game(GLuint widthIn, GLuint heightIn);
	~Game();


	void init();

	void processInput(GLfloat dt);
	void update(GLfloat dt);
	void render();
};




#endif