#ifndef MAINDIALOG_H
#define MAINDIALOG_H

#include <QDialog>
#include <QDebug>
#include <QFile>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QtCore/QUrl>
#include <QtWidgets/QMessageBox>
#include <QtCore/QDir>
#include <QProgressDialog>
#include <QProcess>
#include "thread.h"
//#include "lib/JlCompress.h"

namespace Ui {
    class MainDialog;
}

/**
 * 下载信息封装
 */
struct EncapUrl {
    QString appUrl;
    QString cfgUrl;
    QString envUrl;
};

class ProgressDialog : public QProgressDialog {
Q_OBJECT

public:
    explicit ProgressDialog(const QUrl &url, QWidget *parent = nullptr);

public slots:
    void networkReplyProgress(qint64 bytesRead, qint64 totalBytes);
};

class MainDialog : public QDialog {
Q_OBJECT

public:
    explicit MainDialog(QWidget *parent = nullptr);

    explicit MainDialog(QPair<QString, QString> taskEntity, QWidget *parent = nullptr);

    ~MainDialog();

    void startDownload();

    void doInstall();


private:
    Ui::MainDialog *ui;
    QPair<QString, QString> taskEntity;
    QNetworkAccessManager *manager;
    QNetworkReply* reply;
    QString filename;

    QString saveFileName(const QUrl &url);
    bool saveToDisk(const QString &filename, QIODevice *data);
    void doQuit();



private slots:

    void replyFinished(QNetworkReply *);

    bool isHttpRedirect(QNetworkReply *reply);

    void cancelDownload();

    void installFinish();
};

#endif // MAINDIALOG_H
