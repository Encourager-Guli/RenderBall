
#include "PhongRender.h"
#include <Shader.h>
PhongRender::PhongRender(QString diffuse_path,QString normal_path,QString highlight_path, QWidget* parent):QOpenGLWidget(parent)
{

	this->render = new Phong(diffuse_path.toStdString(), normal_path.toStdString(), highlight_path.toStdString(),width(), height());
}

PhongRender::~PhongRender()
{
}

void PhongRender::initializeGL()
{	
	render->init();

}

void PhongRender::paintGL()
{
	render->paint();
}

void PhongRender::resizeGL(int w, int h)
{
}

