#include "bluetoothmusicconnector.h"

void KU_BluetoothMusic_PluginConnector::pluginSlot(QString const& signal, QVariantMap const& data)
{
    if(signal == "trackChanged")
    {
        MediaTrack track;
        track.title = data["title"].toString();
        track.artist = data["artist"].toString();
        track.duration = data["duration"].toUInt();
        emit trackChanged(track);
    }

    if(signal == "nameChanged")
    {
        //void nameChanged(QString const& name);
    }

    if(signal == "positionChanged")
    {
        emit positionChanged(data["position"].toUInt());
    }

    if(signal == "repeatChanged")
    {
        //void repeatChanged(MediaRepeat repeat);
    }

    if(signal == "shuffleChanged")
    {
        //void shuffleChanged(MediaShuffle shuffle);
    }

    if(signal == "statusChanged")
    {
        emit statusChanged((MediaStatus)data["status"].toInt());
    }
}

void KU_BluetoothMusic_PluginConnector::mediaPreviousSlot()
{
    this->pluginSignal("mediaPrevious");
}

void KU_BluetoothMusic_PluginConnector::mediaNextSlot()
{
    this->pluginSignal("mediaNext");
}

void KU_BluetoothMusic_PluginConnector::mediaPlaySlot()
{
    this->pluginSignal("mediaPlay");
}

void KU_BluetoothMusic_PluginConnector::mediaPauseSlot()
{
    this->pluginSignal("mediaPause");
}
