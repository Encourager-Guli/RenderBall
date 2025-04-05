#include "PBRRender.h"

PBRRender::PBRRender(QString& Albedo, QString& Normal, QString& ARM, QString& skybox, QWidget* parent) :QOpenGLWidget(parent)
{
	this->render = new PBR(Albedo.toStdString(), Normal.toStdString(), ARM.toStdString(), skybox.toStdString(), width(), height());
	this->timer = new QTimer(this);
	connect(timer, &QTimer::timeout, this, QOverload<>::of(&QOpenGLWidget::update));
}

PBRRender::~PBRRender()
{
	delete(timer);
	delete(render);
}

void PBRRender::initializeGL()
{
	render->init();
	timer->start(16);
}

void PBRRender::paintGL()
{
	render->paint();
}

void PBRRender::resizeGL(int w, int h)
{

}
