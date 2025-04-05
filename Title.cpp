#include "Title.h"

Title::Title(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	connect(ui.PhongButtom, &QPushButton::clicked, [this]()
		{
			this->hide();
			q = new PhongSetting();
			q->show();

		});
	connect(ui.PBRButtom, &QPushButton::clicked, [this]()
		{
			this->hide();
			q = new PBRSetting();
			q->show();

		});

}

Title::~Title()
{
	delete(q);
}
