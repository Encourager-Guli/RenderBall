#include "PhongSetting.h"
#include <QFileDialog>   //文件对话框
#include <QMessageBox>
#include "PhongRender.h"
PhongSetting::PhongSetting(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	connect(ui.select_diffuse, &QPushButton::clicked, [this]()
		{
			on_Select_path(diffuse, ui.diffuse_path);
		});
	connect(ui.select_normal, &QPushButton::clicked, [this]()
		{
			on_Select_path(normal, ui.normal_path);
		});
	connect(ui.select_highlight, &QPushButton::clicked, [this]()
		{
			on_Select_path(highlight, ui.highlight_path);
		});
	connect(ui.start_render, &QPushButton::clicked, this, &PhongSetting::start_render);
}
	
PhongSetting::~PhongSetting()
{}

void PhongSetting::on_Select_path(QString &s,QLabel *Label)
{
	s = QFileDialog::getOpenFileName(this,
		QStringLiteral("选择贴图文件"),
		"C:/",
		tr("images(*.png *jpeg *bmp);"));
	Label->setText(QStringLiteral("路径：")+s);
	if (s.isEmpty()) {
		QMessageBox::warning(this, "Warning!", "Failed to open the file");
	}
}

void PhongSetting::start_render()
{
	this->hide();
	PhongRender* p = new PhongRender(diffuse,normal,highlight);
	p->show();

}
