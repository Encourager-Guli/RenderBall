#pragma once
#include<glad/glad.h>
#include <iostream>
#include "Shader.h"
#include"Texture.h"
#include "Model.h"
#include"Camera.h"
class Phong
{
public:
	void init();
	void paint();


	Phong(std::string d, std::string n, std::string s,unsigned int width,unsigned int height);
	~Phong();
private:
	std::string diffuse, normal, specular;
	unsigned int width, height;
	Camera camera;
	Model* ball;
	Shader* phong_shader;
};


