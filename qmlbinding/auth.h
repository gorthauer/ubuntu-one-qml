#ifndef AUTH_H
#define AUTH_H

#include <QObject>

class QAuthenticator;
class QNetworkReply;
class QNetworkAccessManager;
class KQOAuthManager;
class KQOAuthRequest;

class AuthPrivate;
class Auth : public QObject
{
    Q_OBJECT
    
	Q_PROPERTY(QString userName READ userName WRITE setUserName NOTIFY userNameChanged)
	Q_PROPERTY(QString machine READ machineName WRITE setMachineName NOTIFY machineNameChanged)
	Q_PROPERTY(QString password READ password WRITE setPassword NOTIFY passwordChanged)
public:
    explicit Auth(QObject *parent = 0);
	void setUserName(const QString &name);
	QString userName() const;
	void setMachineName(const QString &machine);
	QString machineName() const;
	void setPassword(const QString &password);
	QString password() const;
public slots:
	void login();
signals:
	void success();
	void failed();
	
	void userNameChanged();
	void machineNameChanged();
	void passwordChanged();
private slots:
	void authenticationRequired(QNetworkReply *reply,QAuthenticator *auth);
	void authReplyFinished();
private:
	QString m_userName;
	QString m_machineName;
	QString m_password;

	//KQOAuthManager *m_manager;
	//KQOAuthRequest *m_request;
	QNetworkAccessManager *m_manager;
};

#endif // AUTH_H
