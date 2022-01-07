#include "plugin.h"
#include <QQmlEngine>

QString KU_BluetoothMusic_Plugin::name() const
{
    return "BT Music";
}

QString KU_BluetoothMusic_Plugin::id() const
{
    return "karunit_bluetoothmusic";
}

KU::PLUGIN::PluginVersion KU_BluetoothMusic_Plugin::version() const
{
    return {1, 0, 0};
}

QString KU_BluetoothMusic_Plugin::license() const
{
    return "LGPL";
}

QString KU_BluetoothMusic_Plugin::icon() const
{
    return "multimedia-player";
}

bool KU_BluetoothMusic_Plugin::initialize()
{
    qmlRegisterSingletonInstance("KarunitPlugins", 1, 0, "KUPBluetoothMusicPluginConnector", this->pluginConnector);

    return true;
}

bool KU_BluetoothMusic_Plugin::stop()
{
    return true;
}

bool KU_BluetoothMusic_Plugin::loadSettings()
{
    return true;
}

bool KU_BluetoothMusic_Plugin::saveSettings()
{
    return KU::Settings::instance()->status() == QSettings::NoError;
}

KU_BluetoothMusic_PluginConnector* KU_BluetoothMusic_Plugin::getPluginConnector()
{
    if (this->pluginConnector == nullptr)
        this->pluginConnector = new KU_BluetoothMusic_PluginConnector;
    return qobject_cast<KU_BluetoothMusic_PluginConnector*>(this->pluginConnector);
}
