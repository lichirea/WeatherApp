
#include "GUI.h"

void GUI::populate() {
    if (this->list->count() > 0)
        this->list->clear();

    for (int i = 0; i < this->v.size(); i++)
    {
        TI g = this->v[i];
        if(g.pp < this->currentpp){

            bool ok = false;
            if(states.empty()){
                ok = true;
            }
            else{
                for(int j = 0; j < this->states.size(); j++){
                    if(g.desc == states[j])
                        ok = true;
                }
            }

            if(ok){
                QString itemInList = QString::fromStdString(g.to_str());
                QFont font{ "Verdana", 15 };
                auto* item = new QListWidgetItem{ itemInList };
                item->setFont(font);
                this->list->addItem(item);
            }
        }
    }

    // set the selection on the first item in the list
    if (v.size() > 0)
        this->list->setCurrentRow(0);
}

GUI::GUI() {

    this->f.read(this->v);

    auto* layout = new QHBoxLayout{ this };
    list = new QListWidget{};
    list->setSelectionMode(QAbstractItemView::SingleSelection);
    layout->addWidget(list);

    slider = new QSlider{};
    slider->setMinimum(0);
    slider->setMaximum(100);
    slider->setSingleStep(1);
    slider->setValue(100);
    slider->setTickPosition(QSlider::TicksBothSides);
    slider->setTickInterval(5);
    layout->addWidget(slider);

    auto* buttons = new QWidget;
    auto* buttonlayout = new QVBoxLayout{buttons};
    foggy = new QCheckBox("foggy");
    overcast = new QCheckBox("overcast");
    sunny = new QCheckBox("sunny");
    rain = new QCheckBox("rain");
    thunderstorm = new QCheckBox("thunderstorm");
    buttonlayout->addWidget(foggy);
    buttonlayout->addWidget(overcast);
    buttonlayout->addWidget(sunny);
    buttonlayout->addWidget(rain);
    buttonlayout->addWidget(thunderstorm);
    reset = new QPushButton("RESET");
    buttonlayout->addWidget(reset);

    layout->addWidget(buttons);



    // connections
    QObject::connect(this->slider, &QSlider::valueChanged,
                     this, &GUI::update);
    QObject::connect(this->foggy, &QCheckBox::stateChanged,
                     this, &GUI::update);
    QObject::connect(this->overcast, &QCheckBox::stateChanged,
                     this, &GUI::update);
    QObject::connect(this->sunny, &QCheckBox::stateChanged,
                     this, &GUI::update);
    QObject::connect(this->rain, &QCheckBox::stateChanged,
                     this, &GUI::update);
    QObject::connect(this->thunderstorm, &QCheckBox::stateChanged,
                     this, &GUI::update);
    QObject::connect(this->reset, &QPushButton::clicked,
                     this, &GUI::resetSlot);
    populate();
}

void GUI::update() {
    this->currentpp = this->slider->value();
    states.clear();
    if(foggy->isChecked()) states.emplace_back("foggy");
    if(overcast->isChecked()) states.emplace_back("overcast");
    if(sunny->isChecked()) states.emplace_back("sunny");
    if(rain->isChecked()) states.emplace_back("rain");
    if(thunderstorm->isChecked()) states.emplace_back("thunderstorm");
    populate();

}

void GUI::resetSlot() {
    foggy->setCheckState(Qt::Unchecked);
    overcast->setCheckState(Qt::Unchecked);
    sunny->setCheckState(Qt::Unchecked);
    rain->setCheckState(Qt::Unchecked);
    thunderstorm->setCheckState(Qt::Unchecked);
    currentpp = 100;
    slider->setValue(currentpp);
    update();
}


