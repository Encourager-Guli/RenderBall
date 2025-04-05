#pragma once
#include<glad/glad.h>
#include <iostream>
#include "Shader.h"
#include"Texture.h"
#include "Model.h"
#include"Camera.h"
#include "VAO.h"
#include<QTime>
class PBR
{
public:
	void init();
	void paint();
	PBR(std::string Albeo, std::string Normal, std::string ARM, std::string SkyBox, unsigned int width, unsigned int height);
	~PBR();
private:
	std::string Albedo, Normal, ARM, SkyBox;
	unsigned int width, height, irradianceMap, prefilterMap, brdfLUTTexture, envCubemap;
	Model* ball;
	Camera* camera;
	Shader* PBRShader,* skyboxShader;
	Texture* albedo, *normal, *arm,*skybox;
	VAO* cubeVAO;
};


