#include "qmlbinding.h"
#include "auth.h"
#include <QtDeclarative>

#include <QDebug>

QmlBinding::QmlBinding()
{
	qDebug() << Q_FUNC_INFO;
}

void QmlBinding::registerTypes(const char *uri)
{
	Q_ASSERT(uri == QLatin1String("UbuntuOne"));
	qmlRegisterType<Auth>(uri, 0, 1, "Auth");
}

Q_EXPORT_PLUGIN2(qmlbinding, QmlBinding)
