#include <QApplication>

#include <QtXml>
#include <QtDebug>

void retrievElements(QDomElement root, QString tag, QString att)
{
    QDomNodeList nodes = root.elementsByTagName(tag);

    qDebug() << "Node counts = " << nodes.count();
    for(int i = 0; i < nodes.count(); i++)
    {
        QDomNode elm = nodes.at(i);
        if(elm.isElement())
        {
            QDomElement e = elm.toElement();
            qDebug() << "Attribute : " << e.attribute(att);
        }
    }
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QDomDocument document;
    QFile file(":/dom.xml");
    if(!file.open(QIODevice::ReadOnly
                  | QIODevice::Text)) {
        qDebug() << "Failed to open file.";
        return -1;
    } else {
        if(!document.setContent(&file)) {
            qDebug() << "Failed to reading.";
            return -1;
        }
        file.close();
    }

    QDomElement root =
            document.firstChildElement();

    retrievElements(root, "KR", "Name");
    qDebug() << "Reading finished";

    return a.exec();
}
