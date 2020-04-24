#ifndef MUSICCONTROLLER_H
#define MUSICCONTROLLER_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QSlider>
#include "mediadefines.h"

class MusicController : public QWidget
{
    Q_OBJECT
private:
    MediaStatus status = MediaStatus::Error;
    QLabel* trackLabel;
    QPushButton* prevBtn;
    QPushButton* nextBtn;
    QPushButton* playBtn;
    QSlider* positionSlider;

public:
    MusicController(QWidget* parent = nullptr);

    void changeTrack(MediaTrack const& track);
    void changeName(QString const& name);
    void changePosition(quint32 position);
    void changeRepeat(MediaRepeat repeat);
    void changeShuffle(MediaShuffle shuffle);
    void changeStatus(MediaStatus status);

signals:
    void mediaPreviousSignal();
    void mediaNextSignal();
    void mediaPlaySignal();
    void mediaPauseSignal();
};

#endif // MUSICCONTROLLER_H
