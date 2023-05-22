#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_oodc.h"

class oodc : public QMainWindow
{
    Q_OBJECT

public:
    oodc(QWidget *parent = Q_NULLPTR);

private:
    Ui::oodcClass ui;
};
