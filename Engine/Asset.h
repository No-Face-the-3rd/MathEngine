#pragma once

#ifndef ASSET_H
#define ASSET_H

#include "ResourceManager.h"
#include "SpriteRenderer.h"

class Asset
{
	Asset()
	{

	}
public:
	ResourceManager resourceManager;
	spriteRenderer spriteRenderer;

	void loadTexture(const std::string &name, const char *path);
	Texture2D getTexture(const std::string &name);

	void drawTexture(const std::string &name, const meow::mat3 &m = meow::mat3Identity());

	static Asset &instance()
	{
		static Asset i;
		return i;
	}

};
#endif
