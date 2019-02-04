#include "pch.h"
#include "TextureService.h"

#define STB_IMAGE_IMPLEMENTATION
#include <stb/stb_image.h>

void TextureService::LoadAll()
{
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	_brick = Load(_config->BrickTexturePath);
	_sand = Load(_config->SandTexturePath);
	_marble = Load(_config->MarbleTexturePath);
	_asphalt = Load(_config->AsphaltTexturePath);
}

unsigned TextureService::Load(std::string filepath)
{
	int width = 0;
	int height = 0;
	int channels = 3;
	stbi_uc* image = stbi_load(filepath.c_str(), &width, &height, &channels, 3);

	_logger->Debug("Loaded image %1% into memory [%2% x %3%]",
	               {filepath, std::to_string(width), std::to_string(height)});

	if (image != nullptr)
	{
		unsigned int textureId;
		glGenTextures(1, &textureId);
		glBindTexture(GL_TEXTURE_2D, textureId);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);

		_logger->Debug("Loaded texture [id: %1%] with %2%", {std::to_string(textureId), filepath});
		stbi_image_free(image);
		return textureId;
	}
	else
	{
		_logger->Warn("Failed to load %1%", {filepath});
		return 0;
	}
}
