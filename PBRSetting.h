#pragma once

#include <QWidget>
#include "ui_PBRSetting.h"
#include <QFileDialog>   //文件对话框
#include <QMessageBox>
#include "PBRRender.h"
class PBRSetting : public QWidget
{
	Q_OBJECT

public:
	
	PBRSetting(QWidget *parent = nullptr);
	~PBRSetting();
	void on_Select_path(QString& s, QLabel* Label, QString format = "images(*.png);");
	void start_render();
private:
	Ui::PBRSettingClass ui;
	QString Albedo, Normal, ARM, skybox;
	PBRRender* p;
};
