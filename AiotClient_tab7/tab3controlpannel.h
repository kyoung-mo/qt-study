#ifndef TAB3CONTROLPANNEL_H
#define TAB3CONTROLPANNEL_H

#include <QWidget>
#include <QPalette>

namespace Ui {
class Tab3ControlPannel;
}

class Tab3ControlPannel : public QWidget
{
    Q_OBJECT

public:
    explicit Tab3ControlPannel(QWidget *parent = nullptr);
    ~Tab3ControlPannel();

private slots:
    void on_pPBlamp_clicked(bool checked);
    void on_pPBplug_clicked(bool checked);

public slots:
    void tab3RecvDataSlot(QStringList&);

private:
    Ui::Tab3ControlPannel *ui;
    QPalette paletteOn;
    QPalette paletteOff;

signals:
    void socketSendDataSig(QString);
};

#endif // TAB3CONTROLPANNEL_H
