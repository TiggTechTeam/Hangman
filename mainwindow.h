#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include<QKeyEvent>
#include<QVector>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    virtual void keyPressEvent(QKeyEvent *event);


private:
    Ui::MainWindow *ui;

    QString toGuess = "MANNA";
    QVector<QString> keyStrokes;



    int getNumberOfFaliures();
    void refreshWord();
    void refreshNumberOfFaliures();
};

#endif // MAINWINDOW_H
