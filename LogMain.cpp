# include "LogMain.h"

#include <qdatetime.h>
#include <qdir.h>
#include <qfile.h>
#include <qhash.h>
#include <qobject.h>

QFile* LogMain::logFile = Q_NULLPTR;
bool LogMain::isInit = false;
QHash<QtMsgType, QString>LogMain::contextNames = {
	{QtMsgType::QtDebugMsg,		" Debug  "},
	{QtMsgType::QtInfoMsg,		"  Info  "},
	{QtMsgType::QtWarningMsg,	"Warning "},
	{QtMsgType::QtCriticalMsg,	"Critical"},
	{QtMsgType::QtFatalMsg,		" Fatal  "}
};

void LogMain::init()
{
	if (isInit) 
	{
		return;
	}

	logFile = new QFile;
	logFile->setFileName("./LogTemplate.log");
	logFile->open(QIODevice::Append | QIODevice::Text);

	qInstallMessageHandler(LogMain::messageOutput);

	logFile->resize(0);

	LogMain::isInit = true;
}

void LogMain::clean()
{
	if (logFile != Q_NULLPTR)
	{
		logFile->close();
		delete logFile;
	}
}

void LogMain::messageOutput(QtMsgType type, const QMessageLogContext& context, const QString& msg)
{
	QString log = QObject::tr("%1 | %2 | %3 | %4 | %5 | %6\n").
		arg(QDateTime::currentDateTime().toString("dd-MM-yyyy hh:mm:ss")).
		arg(LogMain::contextNames.value(type)).
		arg(context.line).
		arg(QString(context.file).
			section('\\', -1)).			// File name without file path											
		arg(QString(context.function).
			section('(', -2, -2).		// Function name only
			section(' ', -1).
			section(':', -1)).
		arg(msg);

	logFile->write(log.toLocal8Bit());
	logFile->flush();
}
