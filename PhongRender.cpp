#include "PhongRender.h"
PhongRender::PhongRender(QString diffuse_path,QString normal_path,QString highlight_path, QWidget* parent):QOpenGLWidget(parent)
{

	this->render = new Phong(diffuse_path.toStdString(), normal_path.toStdString(), highlight_path.toStdString(),width(), height());
	this->timer= new QTimer(this);
	connect(timer, &QTimer::timeout, this, QOverload<>::of(&QOpenGLWidget::update));
}	

PhongRender::~PhongRender()
{
	delete(timer);
	delete(render);
}

void PhongRender::initializeGL()
{	
	render->init();
	timer->start(16);
}

void PhongRender::paintGL()
{
	render->paint();
}

void PhongRender::resizeGL(int w, int h)
{
}

