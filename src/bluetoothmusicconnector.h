#ifndef BLUETOOTHMUSICCONNECTOR_H
#define BLUETOOTHMUSICCONNECTOR_H

#include "plugininterface.h"
#include "mediadefines.h"

class KU_BluetoothMusic_PluginConnector : public KU::PLUGIN::PluginConnector
{
    Q_OBJECT
public:
    virtual void pluginSlot(QString const& signal, QVariantMap const& data) override;

    void mediaPreviousSlot();
    void mediaNextSlot();
    void mediaPlaySlot();
    void mediaPauseSlot();

signals:
    void trackChanged(MediaTrack const& track);
    void nameChanged(QString const& name);
    void positionChanged(quint32 position);
    void repeatChanged(MediaRepeat repeat);
    void shuffleChanged(MediaShuffle shuffle);
    void statusChanged(MediaStatus status);
};

#endif // BLUETOOTHMUSICCONNECTOR_H
