#include <QCoreApplication>
#include <QIODevice>
#include <QDataStream>
#include <QDebug>

QByteArray encoding()
{
    quint32 value1 = 123;
    quint8  value2 = 124;
    quint32 value3 = 125;

    QByteArray outData;
    QDataStream outStream(&outData, QIODevice::WriteOnly);

    outStream << value1;
    outStream << value2;
    outStream << value3;

    qDebug() << "outData size : " << outData.size() << " Bytes";

    return outData;
}

void decoding(QByteArray _data)
{
    QByteArray inData = _data;

    quint32 inValue1 = 0;
    quint8  inValue2 = 0;
    quint32 inValue3 = 0;

    QDataStream inStream(&inData, QIODevice::ReadOnly);

    inStream >> inValue1; // 123
    inStream >> inValue2; // 124
    inStream >> inValue3; // 125

    qDebug("[First : %d] [Second : %d] [Third : %d]"
                , inValue1, inValue2, inValue3 );
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QByteArray encData = encoding();
    decoding(encData);

    return a.exec();
}
