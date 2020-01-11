#ifndef MUSICCONTROLLER_H
#define MUSICCONTROLLER_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QSlider>
#include "bluetoothinterface.h"

class MusicController : public QWidget
{
    Q_OBJECT
private:
    KU::PLUGIN::MediaStatus status = KU::PLUGIN::MediaStatus::Error;
    QLabel* trackLabel;
    QPushButton* prevBtn;
    QPushButton* nextBtn;
    QPushButton* playBtn;
    QSlider* positionSlider;

public:
    MusicController(QWidget* parent = nullptr);

    void trackChanged(KU::PLUGIN::MediaTrack const& track);
    void nameChanged(QString const& name);
    void positionChanged(quint32 position);
    void repeatChanged(KU::PLUGIN::MediaRepeat repeat);
    void shuffleChanged(KU::PLUGIN::MediaShuffle shuffle);
    void statusChanged(KU::PLUGIN::MediaStatus status);

signals:
    void mediaPrevious();
    void mediaNext();
    void mediaPlay();
    void mediaPause();
};

#endif // MUSICCONTROLLER_H
