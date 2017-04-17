#include "vnf.h"
#include <QApplication>
#include <QBitmap>
#include <QBrush>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QPalette>
#include <QPixmap>
#include <QVBoxLayout>


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{

    // Master Widget
    QWidget *mainView = new QWidget(this);
    this->setCentralWidget(mainView);

    // Master Organizer
    QVBoxLayout *masterLayout = new QVBoxLayout(this);

    // Set Background Image
    QPalette bgPalette = QPalette();
    bgPalette.setBrush(QPalette::Background, QBrush(QPixmap(":/Resources/bg.jpg")));
    this->setPalette(bgPalette);

    // Load Character Image
    QPixmap *charImg = new QPixmap(":/Resources/test.png");
    QHBoxLayout *cLayout = new QHBoxLayout(this);
    cLayout->setAlignment(Qt::AlignRight);
    QLabel *cimask = new QLabel();
    cimask->setPixmap(*charImg);
    cimask->setMask(charImg->mask());
    cLayout->addWidget(cimask);

    // Build Bottom Bar
    QVBoxLayout *bottomBox = new QVBoxLayout(this);

    // Build Options Bar
    QHBoxLayout *optionsBar = new QHBoxLayout(this);
    optionsBar->setAlignment(Qt::AlignRight);
    QPushButton *opt_Save = new QPushButton("Save");
    QPushButton *opt_Load = new QPushButton("Load");
    QPushButton *opt_Quit = new QPushButton("Quit");
    optionsBar->addWidget(opt_Save);
    optionsBar->addWidget(opt_Load);
    optionsBar->addWidget(opt_Quit);
    connect(opt_Quit, &QPushButton::clicked, qApp, &QApplication::quit);
    opt_Save->setFlat(true);
    opt_Load->setFlat(true);
    opt_Quit->setFlat(true);

    // Build Text Area
    QLabel *text = new QLabel("What do you want, Yosuke?");
    text->palette()->setColor(QPalette::WindowText, Qt::white);
    QHBoxLayout *textArea = new QHBoxLayout(this);
    textArea->setAlignment(Qt::AlignCenter);
    textArea->addWidget(text);
    
    // Set TextBox style
    QPalette taPalette = QPalette();
    taPalette.setBrush(QPalette::Background, QBrush(QPixmap(":/Resources/textbox.jpg")));
    textArea->setPalette(taPalette);

    // Combine the Pieces
    bottomBox->addItem(optionsBar);
    bottomBox->addItem(textArea);

    // Build Master Layout
    masterLayout->addItem(cLayout);
    masterLayout->addItem(bottomBox);
    this->centralWidget()->setLayout(masterLayout);

}
