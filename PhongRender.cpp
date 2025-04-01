#include "PhongRender.h"

PhongRender::PhongRender(QString diffuse_path,QString normal_path,QString highlight_path, QWidget* parent)
{

}

PhongRender::~PhongRender()
{
}

void PhongRender::initializeGL()
{	

}

void PhongRender::paintGL()
{

}

void PhongRender::resizeGL(int w, int h)
{
	this->glViewport(0, 0, w, h);
}
