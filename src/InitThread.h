//
// Created by Shinelon on 2019/1/2.
//

#ifndef SUPERSERIALPORT_INITTHREAD_H
#define SUPERSERIALPORT_INITTHREAD_H

#include <QThread>


class InitThread : public QThread {
Q_OBJECT
public:
    InitThread(QObject *parent, const QString &dataSource, QList<QByteArray> *lines);

    void run() override ;

signals:
    //signals通过moc自动生成，不可以自己创建实现！！！
    //Signals are automatically generated by the moc and must not be implemented in the .cpp file.
    //T hey can never have return types (i.e. use void).
    void initFinished();

private:
    QString dataSource;//数据源
    QList<QByteArray>* lines;//所有行数据
};


#endif //SUPERSERIALPORT_INITTHREAD_H
