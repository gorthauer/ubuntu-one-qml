#ifndef AUTH_H
#define AUTH_H

#include <QObject>
#include <QWeakPointer>

class QAuthenticator;
class QNetworkReply;
class QNetworkAccessManager;
class QUrl;

namespace QOAuth {
class Interface;
}

class Notes;
class Account;
class AuthPrivate;
class Auth : public QObject
{
    Q_OBJECT
    
	Q_PROPERTY(QString machine READ machineName WRITE setMachineName NOTIFY machineNameChanged)
	Q_PROPERTY(bool hasToken READ hasToken)
	Q_PROPERTY(Notes *notes READ notes)
	Q_PROPERTY(Account *account READ account)
public:
    explicit Auth(QObject *parent = 0);
	void setMachineName(const QString &machine);
	QString machineName() const;
	bool hasToken() const;
	Notes *notes();
	Account *account();

	QNetworkReply *get(const QUrl &);
	QNetworkReply *put(const QUrl &, const QByteArray &data);
public slots:
	void requestToken(const QString &userName, const QString &password);
	void test();
signals:
	void receivedToken();
	void tokenRequestFailed();
	void machineNameChanged();
	void tokenRequested();
	void redirect(const QString &url);
private slots:
	void onAuthenticationRequired(QNetworkReply *reply, QAuthenticator *auth);
	void onAuthReplyFinished();
	void onConfirmReplyFinished();
	void onTestReplyFinished();
	void onReplyFinished(QNetworkReply*);
	void onApiRefsReceived();
protected:
	void getApiRefs();
private:
	QString m_machineName;
	QByteArray m_token;
	QByteArray m_tokenSecret;
	QNetworkAccessManager *m_manager;
	QOAuth::Interface *m_oauth;

	QWeakPointer<Notes> m_notes;
	QWeakPointer<Account> m_account;
};

#endif // AUTH_H
