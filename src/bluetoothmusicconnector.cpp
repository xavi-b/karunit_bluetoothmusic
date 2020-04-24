#include "bluetoothmusicconnector.h"

void KU_BluetoothMusic_PluginConnector::pluginSlot(QString const& signal, QVariantMap const& data)
{
    if(signal == "trackChanged")
    {
        //void trackChanged(MediaTrack const& track);
    }

    if(signal == "nameChanged")
    {
        //void nameChanged(QString const& name);
    }

    if(signal == "positionChanged")
    {
        //void positionChanged(quint32 position);
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
        //void statusChanged(MediaStatus status);
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
