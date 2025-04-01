#pragma once

#include <QWidget>
#include "ui_Title.h"

class Title : public QWidget
{
	Q_OBJECT

public:
	Title(QWidget *parent = nullptr);
	~Title();

private:
	Ui::TitleClass ui;
};
