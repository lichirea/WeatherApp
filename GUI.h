#pragma once

#include <QApplication>
#include <string>
#include <qwidget.h>
#include <QApplication>
#include <QWidget>
#include <QLayout>
#include <QPushButton>
#include <QCheckBox>
#include <QLineEdit>
#include <QLabel>
#include <QString>
#include <QListWidget>
#include <QListWidgetItem>
#include <vector>
#include "Domain.h"
#include "FileRepo.h"


class GUI: public QWidget{
    Q_OBJECT
private:
    std::vector<TI> v;
    QListWidget* list;
    QSlider* slider;
    QCheckBox* foggy;
    QCheckBox* overcast;
    QCheckBox* sunny;
    QCheckBox* rain;
    QCheckBox* thunderstorm;
    QPushButton* reset;
    FileRepo f;
    int currentpp = 100;
    std::vector<std::string> states;
    void populate();
public slots:
    void update();
    void resetSlot();

public:

    GUI();
};