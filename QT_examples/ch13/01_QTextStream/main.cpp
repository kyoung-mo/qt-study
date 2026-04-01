#include <QCoreApplication>
#include <QIODevice>
#include <QTextStream>
#include <QDebug>

QByteArray writeData(QByteArray _data)
{
    QByteArray temp = _data;

    QByteArray outData;
    QTextStream outStream(&outData, QIODevice::WriteOnly);

    for(qsizetype i = 0 ; i < temp.size() ; i++) {
        outStream << temp.at(i);
    }

    outStream.flush();

    return outData;
}

void readData(QByteArray _data)
{
    QTextStream outStream(&_data, QIODevice::ReadOnly);

    QByteArray inData;
    for(qsizetype i = 0 ; i < _data.size() ; i++)
    {
        char data;
        outStream >> data;
        inData.append(data);
    }

    qDebug("READ DATA : [%s]", inData.data());
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QByteArray retData = writeData("Hello world."); // 12 Bytes
    qDebug() << "WRITE DATA size : " << retData.size() << " Bytes";

    readData(retData);

    return a.exec();
}
