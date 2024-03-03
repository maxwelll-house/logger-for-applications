#include "LoggerForApplications.h"
#include "LogMain.h"

LoggerForApplications::LoggerForApplications(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    QObject::connect(ui.debugButton, &QPushButton::clicked, this, &LoggerForApplications::onDebug);
    QObject::connect(ui.infoButton, &QPushButton::clicked, this, &LoggerForApplications::onInfo);
    QObject::connect(ui.warningButton, &QPushButton::clicked, this, &LoggerForApplications::onWarning);
    QObject::connect(ui.criticalButton, &QPushButton::clicked, this, &LoggerForApplications::onCritical);
    QObject::connect(ui.fatalButton, &QPushButton::clicked, this, &LoggerForApplications::onFatal);

}

LoggerForApplications::~LoggerForApplications()
{}

void LoggerForApplications::onDebug()
{
    qDebug() << "Debug ";
}

void LoggerForApplications::onInfo()
{
    qInfo() << "Info ";
}

void LoggerForApplications::onWarning()
{
    qWarning() << "Warning ";
}

void LoggerForApplications::onCritical()
{
    qCritical() << "Critical ";
}

void LoggerForApplications::onFatal()
{
    qFatal("FATAL! ");
}
