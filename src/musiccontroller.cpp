#include "musiccontroller.h"

MusicController::MusicController(QWidget* parent)
    : QWidget(parent)
{
    QVBoxLayout* layout = new QVBoxLayout;

    this->setFont(QFont("FontAwesome"));

    this->trackLabel = new QLabel;
    this->trackLabel->setAlignment(Qt::AlignCenter);
    layout->addWidget(this->trackLabel, 1);

    QHBoxLayout* controlsLayout = new QHBoxLayout;

    controlsLayout->addStretch(1);
    this->prevBtn = new QPushButton("\uf359");
    this->prevBtn->setFixedSize(50, 50);
    controlsLayout->addWidget(this->prevBtn);
    this->playBtn = new QPushButton("\uf144");
    this->playBtn->setFixedSize(50, 50);
    controlsLayout->addWidget(this->playBtn);
    this->nextBtn = new QPushButton("\uf35a");
    this->nextBtn->setFixedSize(50, 50);
    controlsLayout->addWidget(this->nextBtn);
    controlsLayout->addStretch(1);

    layout->addLayout(controlsLayout);

    this->positionSlider = new QSlider;
    this->positionSlider->setOrientation(Qt::Horizontal);
    layout->addWidget(this->positionSlider);

    this->setLayout(layout);

    connect(this->prevBtn, &QPushButton::clicked, this, &MusicController::mediaPrevious);
    connect(this->nextBtn, &QPushButton::clicked, this, &MusicController::mediaNext);
    connect(this->playBtn, &QPushButton::clicked, this, [=]()
    {
        if(this->status == KU::PLUGIN::MediaStatus::Error)
            return;

        if(this->status == KU::PLUGIN::MediaStatus::Playing)
        {
            this->statusChanged(KU::PLUGIN::MediaStatus::Paused);
            emit mediaPause();
        }
        else
        {
            this->statusChanged(KU::PLUGIN::MediaStatus::Playing);
            emit mediaPlay();
        }
    });
}

void MusicController::trackChanged(KU::PLUGIN::MediaTrack const& track)
{
    this->trackLabel->setText(track.title + "\n" +
                              track.artist + "\n");

    this->positionSlider->setMaximum(track.duration);
}

void MusicController::nameChanged(QString const& name)
{

}

void MusicController::positionChanged(quint32 position)
{
    this->positionSlider->setValue(position);
}

void MusicController::repeatChanged(KU::PLUGIN::MediaRepeat repeat)
{

}

void MusicController::shuffleChanged(KU::PLUGIN::MediaShuffle shuffle)
{

}

void MusicController::statusChanged(KU::PLUGIN::MediaStatus status)
{
    this->status = status;

    if(status == KU::PLUGIN::MediaStatus::Playing)
        this->playBtn->setText("\uf28b");
    else
        this->playBtn->setText("\uf144");
}
