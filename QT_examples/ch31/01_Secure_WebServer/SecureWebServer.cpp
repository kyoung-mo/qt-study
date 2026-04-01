#include "SecureWebServer.h"
#include <QCoreApplication>
#include <QFile>
#include <QDebug>

#if QT_CONFIG(ssl)
#  include <QSslCertificate>
#  include <QSslKey>
#endif

SecureWebServer::SecureWebServer(QObject *parent)
    : QObject{parent}
{
    m_server.route("/", [] () {
        return "hello world";
    });


#if QT_CONFIG(ssl)
    const auto sslCertificateChain =
        QSslCertificate::fromPath(QStringLiteral(":/test.crt"));

    QFile privateKeyFile(QStringLiteral(":/test.key"));
    if (!privateKeyFile.open(QIODevice::ReadOnly)) {
        qDebug() << "Couldn't open file for reading: %1"
                 << privateKeyFile.errorString();
        return;
    }

    m_server.sslSetup(sslCertificateChain.front(),
                      QSslKey(&privateKeyFile, QSsl::Rsa));
    privateKeyFile.close();

    // [ URL ] https://127.0.0.1:8001
    const auto sslPort = m_server.listen(QHostAddress::Any, 8001);
    if (!sslPort)
        qDebug() << "Server failed to listen on a port.";

#else
    qDebug() <<"This Web Server does not support SSL.";
#endif

}

SecureWebServer::~SecureWebServer()
{
    deleteLater();
}

