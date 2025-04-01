#pragma once
#include <QOpenGLWidget>
#include <QOpenGLFunctions>
class PhongRender :public QOpenGLWidget, protected QOpenGLFunctions
{
	Q_OBJECT
public:
	PhongRender(QString diffuse_path, QString normal_path, QString highlight_path, QWidget* parent = nullptr);
	~PhongRender();
protected:
	virtual void initializeGL() override;
	virtual void paintGL() override;
	virtual void resizeGL(int w, int h) override;
};