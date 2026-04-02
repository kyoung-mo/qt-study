#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWebEngineView>
#include <QLineEdit>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(const QUrl& url,
               QWidget *parent = nullptr);
    ~MainWindow();

protected slots:

    void adjustLocation();
    void changeLocation();
    void adjustTitle();
    void setProgress(int p);
    void finishLoading(bool);

    void viewSource();

    void highlightAllLinks();
    void removeGifImages();

private:
    QString jQuery;
    QWebEngineView *view;
    QLineEdit *locationEdit;
    int progress;

};
#endif // MAINWINDOW_H
