#pragma once
#include "PBR.h"
#include <QOpenGLWidget>
#include<QTimer>

class PBRRender :public QOpenGLWidget
{
	Q_OBJECT
public:

	PBRRender(QString &Albedo, QString& Normal, QString& ARM, QString& skybox, QWidget* parent = nullptr);
	~PBRRender();
protected:
	virtual void initializeGL() override;
	virtual void paintGL() override;
	virtual void resizeGL(int w, int h) override;
private:
	PBR* render;
	QTimer* timer;


};

