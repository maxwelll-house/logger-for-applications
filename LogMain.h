#pragma once

#include <qdebug.h>
#include <qfile.h>
#include <qhash.h>

class LogMain {
private:
	static QFile* logFile;
	static bool isInit;
	static QHash <QtMsgType, QString> contextNames;
public:
	static void init();
	static void clean();
	static void messageOutput(QtMsgType type, const QMessageLogContext& context, const QString& msg);
};