#include "Title.h"
#include"PhongSetting.h"
Title::Title(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	connect(ui.PhongButtom, &QPushButton::clicked, [this]()
		{
			this->hide();
			PhongSetting* p = new PhongSetting();
			p->show();

		});
}

Title::~Title()
{}
