#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btnCancel_clicked();

    void on_btnDownload_clicked();

    void on_cbApp_toggled(bool checked);

    void on_cbRes_toggled(bool checked);

private:
    Ui::MainWindow *ui;

public:
    bool isAppChecked;//App选中
    bool isResChecked;//Res选中
};

#endif // MAINWINDOW_H
