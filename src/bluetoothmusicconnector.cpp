#include "bluetoothmusicconnector.h"

void KU_BluetoothMusic_PluginConnector::pluginSlot(QString const& signal, QVariantMap const& data)
{
    if (signal == "trackChanged")
    {
        this->track    = data["title"].toString() + "\n" + data["artist"].toString();
        this->duration = data["duration"].toUInt();
        emit trackChanged();
    }

    if (signal == "nameChanged")
    {
        // void nameChanged(QString const& name);
    }

    if (signal == "positionChanged")
    {
        this->position = data["position"].toUInt();
        emit positionChanged();
    }

    if (signal == "repeatChanged")
    {
        // void repeatChanged(MediaRepeat repeat);
    }

    if (signal == "shuffleChanged")
    {
        // void shuffleChanged(MediaShuffle shuffle);
    }

    if (signal == "statusChanged")
    {
        this->status = (MediaStatus)data["status"].toInt();
        emit statusChanged();
    }
}

void KU_BluetoothMusic_PluginConnector::mediaPrevious()
{
    this->pluginSignal("mediaPrevious");
}

void KU_BluetoothMusic_PluginConnector::mediaNext()
{
    this->pluginSignal("mediaNext");
}

void KU_BluetoothMusic_PluginConnector::mediaPlay()
{
    this->pluginSignal("mediaPlay");
}

void KU_BluetoothMusic_PluginConnector::mediaPause()
{
    this->pluginSignal("mediaPause");
}
