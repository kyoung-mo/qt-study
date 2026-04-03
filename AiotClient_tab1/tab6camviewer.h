#ifndef TAB6CAMVIEWER_H
#define TAB6CAMVIEWER_H

#include <QWidget>

namespace Ui {
class Tab6CamViewer;
}

class Tab6CamViewer : public QWidget
{
    Q_OBJECT

public:
    explicit Tab6CamViewer(QWidget *parent = nullptr);
    ~Tab6CamViewer();

private:
    Ui::Tab6CamViewer *ui;
};

#endif // TAB6CAMVIEWER_H
