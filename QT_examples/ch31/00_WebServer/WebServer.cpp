#include "WebServer.h"
#include <qloggingcategory.h>
#include <QJsonObject>
#include <QDebug>

using namespace Qt::StringLiterals;

WebServer::WebServer(QObject *parent)
    : QObject{parent}
{
    // [ URL ] http://127.0.0.1:8000
    m_server.route("/", [] () {
        return "Hello world";
    });

    // [ URL ] http://127.0.0.1:8000/who/
    m_server.route("/who", [] () {
        return "I am a Web server";
    });


    // [ URL ] http://127.0.0.1:8000/hello/2/
    m_server.route("/hello/<arg>/", [=] (qint32 id, const QHttpServerRequest &req) {

        QString hostStr = hostName(req) + u"/hello id ---> %1"_s.arg(id);
        return hostStr;
    });

    // [ URL ] http://127.0.0.1:8000/hello_json
    m_server.route("/hello_json", [] () {
        QJsonObject jsonObj;
        jsonObj["key1"] = "value1";
        jsonObj["key2"] = "value2";
        jsonObj["key3"] = "value3";

        return jsonObj;
    });

    // [ URL ] http://127.0.0.1:8000/args_req?myname=Dae jin, Kim&nation=South Korea
    m_server.route("/args_req", [] (const QHttpServerRequest &req) {
        QString filter;
        QTextStream result(&filter);
        for (auto pair : req.query().queryItems()) {
            if (!filter.isEmpty())
                result << "\n";
            result << pair.first << "=" << pair.second;
        }
        QLoggingCategory::setFilterRules(filter);

        return filter;
    });

    //m_server.listen(QHostAddress::LocalHost, 8000);
    m_server.listen(QHostAddress::Any, 8000);
}

QString WebServer::hostName(const QHttpServerRequest &request)
{
    return QString::fromLatin1(request.value("Host"));
}

WebServer::~WebServer()
{
    deleteLater();
}
