#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QKeyEvent>
#include<iostream>
#include <QString>
#include <QCharRef>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    refreshWord();
    refreshNumberOfFaliures();

     ui->background->setPixmap(QPixmap(QString::fromUtf8(":/backgrounds/Hangman12.png")));
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    int numberOfFaliures = getNumberOfFaliures();
    if(numberOfFaliures == 12) {
        return;

    }
    QString input = event->text().toUpper();
    if(!input.isEmpty()){
        keyStrokes.append(input);
        refreshWord();
        refreshNumberOfFaliures();
        std::cout<< "Taste wurde gedrucht: "
                 << input.toStdString()
                 << std::endl;

    }
}
int MainWindow::getNumberOfFaliures(){

    int numberOfFaliures = 0;
    for(QString key : keyStrokes){
        if( !toGuess.contains(key.at(0))){
            numberOfFaliures++;

        }
    }
    return numberOfFaliures;
}
void MainWindow::refreshNumberOfFaliures(){

    int numberOfFaliures = getNumberOfFaliures();
    ui->numberofmistakes->setText(QString::number(numberOfFaliures));


    //Galgen Aktualisieren
    QVector<QString> images = {
       ":/backgrounds/Hangman01.png",
        ":/backgrounds/Hangman01.png",
        ":/backgrounds/Hangman02.png",
        ":/backgrounds/Hangman03.png",
        ":/backgrounds/Hangman04.png",
        ":/backgrounds/Hangman05.png",
        ":/backgrounds/Hangman06.png",
        ":/backgrounds/Hangman07.png",
        ":/backgrounds/Hangman08.png",
        ":/backgrounds/Hangman09.png",
        ":/backgrounds/Hangman10.png",
        ":/backgrounds/Hangman11.png",
        ":/backgrounds/Hangman12.png",


    };
    ui->background->setPixmap(
                QPixmap(images.at(numberOfFaliures)));
}

void MainWindow::refreshWord()
{

    int numberOfFaliuers = getNumberOfFaliures();

    QString output = "";
    for (int i = 0; i < toGuess.length(); i++) {
        if (i != 0) {
            output+=" ";
        }
        if(numberOfFaliuers == 12 || keyStrokes.contains(QString(toGuess[i]))){
            output+=toGuess[i];

        }else {
            output+="_";
        }
        output+="_";
    }
    ui->word->setText(output);
}

MainWindow::~MainWindow()
{
    delete ui;
}
