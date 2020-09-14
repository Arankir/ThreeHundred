#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <class/card.h>
#include <class/player.h>

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
    QList<Card> deck_;
    QList<Player> players_;
    Player currentPlayer_;

    //класс настроек

    //класс игры с модификациями

};
#endif // MAINWINDOW_H
