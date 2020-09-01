#include "musiccontroller.h"

MusicController::MusicController(QWidget* parent)
    : QWidget(parent)
{
    QVBoxLayout* layout = new QVBoxLayout;

    this->trackLabel = new QLabel;
    this->trackLabel->setAlignment(Qt::AlignCenter);
    layout->addWidget(this->trackLabel, 1);

    QHBoxLayout* controlsLayout = new QHBoxLayout;

    controlsLayout->addStretch(1);
    this->prevBtn = new QPushButton(QIcon::fromTheme("media-skip-backward"), "");
    this->prevBtn->setFixedSize(50, 50);
    controlsLayout->addWidget(this->prevBtn);
    this->playBtn = new QPushButton(QIcon::fromTheme("media-playback-start"), "");
    this->playBtn->setFixedSize(50, 50);
    controlsLayout->addWidget(this->playBtn);
    this->nextBtn = new QPushButton(QIcon::fromTheme("media-skip-forward"), "");
    this->nextBtn->setFixedSize(50, 50);
    controlsLayout->addWidget(this->nextBtn);
    controlsLayout->addStretch(1);

    layout->addLayout(controlsLayout);

    this->positionSlider = new QSlider;
    this->positionSlider->setOrientation(Qt::Horizontal);
    this->positionSlider->setDisabled(true);
    layout->addWidget(this->positionSlider);

    this->setLayout(layout);

    connect(this->prevBtn, &QPushButton::clicked, this, &MusicController::mediaPreviousSignal);
    connect(this->nextBtn, &QPushButton::clicked, this, &MusicController::mediaNextSignal);
    connect(this->playBtn, &QPushButton::clicked, this, [=]()
    {
        if(this->status == MediaStatus::Error)
            return;

        if(this->status == MediaStatus::Playing)
        {
            this->changeStatus(MediaStatus::Paused);
            emit mediaPauseSignal();
        }
        else
        {
            this->changeStatus(MediaStatus::Playing);
            emit mediaPlaySignal();
        }
    });
}

void MusicController::changeTrack(MediaTrack const& track)
{
    this->trackLabel->setText(track.title + "\n" +
                              track.artist + "\n");

    this->positionSlider->setMaximum(track.duration);
}

void MusicController::changeName(QString const& name)
{

}

void MusicController::changePosition(quint32 position)
{
    this->positionSlider->setValue(position);
}

void MusicController::changeRepeat(MediaRepeat repeat)
{

}

void MusicController::changeShuffle(MediaShuffle shuffle)
{

}

void MusicController::changeStatus(MediaStatus status)
{
    this->status = status;

    if(status == MediaStatus::Playing)
        this->playBtn->setIcon(QIcon::fromTheme("media-playback-pause"));
    else
        this->playBtn->setIcon(QIcon::fromTheme("media-playback-start"));
}
