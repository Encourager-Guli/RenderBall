#pragma once

#include <QWidget>
#include "ui_PhongSetting.h"

class PhongSetting : public QWidget
{
	Q_OBJECT

public:
	QString diffuse, normal, highlight;
	PhongSetting(QWidget *parent = nullptr);
	~PhongSetting();
	void on_Select_path(QString& s, QLabel* Label);
	void start_render();
private:
	Ui::PhongSettingClass ui;
};
