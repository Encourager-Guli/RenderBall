#pragma once

#include <QWidget>
#include "ui_PhongSetting.h"
#include <QFileDialog>   //文件对话框
#include <QMessageBox>
#include "PhongRender.h"
class PhongSetting : public QWidget
{
	Q_OBJECT

public:
	QString diffuse, normal, highlight;
	PhongSetting(QWidget *parent = nullptr);
	~PhongSetting();
	void on_Select_path(QString& s, QLabel* Label, QString format = "images(*.png );");
	void start_render();
private:
	Ui::PhongSettingClass ui;
	PhongRender* p;
};
