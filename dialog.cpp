#include "dialog.h"
#include "ui_dialog.h"
#include <QFile>
#include <QTextStream>
#include <QIODevice>

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    connect(ui->but, SIGNAL(clicked()), this, SLOT(wrf()));
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::wrf()
{
    QFile file("text.txt");
    if (!file.open(QIODevice::WriteOnly))
    {
        qCritical() << file.errorString();
    }
    QTextStream stream(&file);
    QString text = ui->textEdit->toPlainText();
    stream << text;
    file.close();
}

