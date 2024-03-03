#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_LoggerForApplications.h"

class LoggerForApplications : public QMainWindow
{
    Q_OBJECT

public:
    LoggerForApplications(QWidget *parent = nullptr);
    ~LoggerForApplications();

    void onDebug();
    void onInfo();
    void onWarning();
    void onCritical();
    void onFatal();
private:
    Ui::LoggerForApplicationsClass ui;
};
