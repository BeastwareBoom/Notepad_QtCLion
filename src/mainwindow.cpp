#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //禁用窗口大小调节和最大化按钮
    setWindowFlags(windowFlags()& ~Qt::WindowMaximizeButtonHint);
    setFixedSize(this->width(), this->height());

    //文件选择窗口
    fileDialog = new QFileDialog(this);
    fileDialog->setFileMode(QFileDialog::Directory);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete fileDialog;
}

void MainWindow::on_btnCancel_clicked()
{
    qDebug()<<"Cancel click";
    close();
}

void MainWindow::on_btnDownload_clicked()
{
    qDebug()<<"Download click";

    if(!isCfgChecked&&!isAppChecked){
        //全都未选中
        return;
    }

    //app选中
    if(isAppChecked){

    }

    //res选中
    if(isCfgChecked){

    }
}

void MainWindow::on_cbApp_toggled(bool checked)
{
    isAppChecked = checked;
    qDebug()<<"App "<<checked;
}

void MainWindow::on_cbCfg_toggled(bool checked)
{
    isCfgChecked=checked;
    qDebug()<<"Cfg "<<checked;

}

void MainWindow::on_cbScene_toggled(bool checked)
{
    isSceneChecked=checked;
    qDebug()<<"Scene "<<checked;
}

void MainWindow::on_tbAppPath_clicked()
{
//    qDebug()<<"AppPath clicked ";

    fileDialog->show();

    if(fileDialog->exec()){
        appPath = fileDialog->selectedFiles()[0];
            qDebug()<<appPath;
            ui->lbAppPath->setText(appPath);
        ui->lbAppPath->setStyleSheet("color: black;");
    }
}

void MainWindow::on_tbCfgPath_clicked()
{
//    qDebug()<<"CfgPath clicked ";
    fileDialog->show();

    if(fileDialog->exec()){
        cfgPath = fileDialog->selectedFiles()[0];
        qDebug()<<cfgPath;
        ui->lbCfgPath->setText(cfgPath);
        ui->lbCfgPath->setStyleSheet("color: black;");
    }
}

void MainWindow::on_tbScenePath_clicked()
{
    fileDialog->show();

    if(fileDialog->exec()){
        scenePath = fileDialog->selectedFiles()[0];
        qDebug()<<scenePath;
        ui->lbScenePath->setText(scenePath);
        ui->lbScenePath->setStyleSheet("color: black;");
    }
}


