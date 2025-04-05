#include "PBRSetting.h"

PBRSetting::PBRSetting(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	connect(ui.select_Albedo, &QPushButton::clicked, [this]()
		{
			on_Select_path(Albedo, ui.Albedo_path);
		});
	connect(ui.select_Normal, &QPushButton::clicked, [this]()
		{
			on_Select_path(Normal, ui.Normal_path);
		});
	connect(ui.select_ARM, &QPushButton::clicked, [this]()
		{
			on_Select_path(ARM, ui.ARM_path);
		});
	connect(ui.select_skybox, &QPushButton::clicked, [this]()
		{
			on_Select_path(skybox, ui.skybox_path,QString("images(*.hdr);"));
		});
	connect(ui.start_render, &QPushButton::clicked, this, &PBRSetting::start_render);

}

PBRSetting::~PBRSetting()
{
	delete p;
}
void PBRSetting::on_Select_path(QString& s, QLabel* Label, QString format)
{
	s = QFileDialog::getOpenFileName(this,
		QStringLiteral("选择贴图文件"),
		"res/textures/textures",
		format);
	Label->setText(QStringLiteral("路径：") + s);
	if (s.isEmpty()) {
		QMessageBox::warning(this, "Warning!", "Failed to open the file");
	}
}

void PBRSetting::start_render()
{
	this->hide();
	p = new PBRRender(Albedo,Normal,ARM,skybox);
	p->show();
}
