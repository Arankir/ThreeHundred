#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <class/card.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void initDeck();
    void shuffleDeck();

private:
    Ui::MainWindow *ui;
    QVector<Card> deck_;

};
#endif // MAINWINDOW_H
