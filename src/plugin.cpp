#include "plugin.h"

QString KU_BluetoothMusic_Plugin::name() const
{
    return "BT Music";
}

QString KU_BluetoothMusic_Plugin::id() const
{
    return "bt.music";
}

KU::PLUGIN::PluginVersion KU_BluetoothMusic_Plugin::version() const
{
    return { 1, 0, 0 };
}

QString KU_BluetoothMusic_Plugin::license() const
{
    return "LGPL";
}

QIcon KU_BluetoothMusic_Plugin::icon() const
{
    return QIcon::fromTheme("multimedia-player");
}

bool KU_BluetoothMusic_Plugin::initialize()
{
    this->musicControllerWidget = new MusicController;

    this->pluginConnector = new KU_BluetoothMusic_PluginConnector;
    this->setPluginConnector(this->pluginConnector);

    QObject::connect(this->pluginConnector, &KU_BluetoothMusic_PluginConnector::trackChanged,
                     this->musicControllerWidget, &MusicController::changeTrack);
    QObject::connect(this->pluginConnector, &KU_BluetoothMusic_PluginConnector::nameChanged,
                     this->musicControllerWidget, &MusicController::changeName);
    QObject::connect(this->pluginConnector, &KU_BluetoothMusic_PluginConnector::positionChanged,
                     this->musicControllerWidget, &MusicController::changePosition);
    QObject::connect(this->pluginConnector, &KU_BluetoothMusic_PluginConnector::repeatChanged,
                     this->musicControllerWidget, &MusicController::changeRepeat);
    QObject::connect(this->pluginConnector, &KU_BluetoothMusic_PluginConnector::shuffleChanged,
                     this->musicControllerWidget, &MusicController::changeShuffle);
    QObject::connect(this->pluginConnector, &KU_BluetoothMusic_PluginConnector::statusChanged,
                     this->musicControllerWidget, &MusicController::changeStatus);
    QObject::connect(this->musicControllerWidget, &MusicController::mediaPreviousSignal,
                     this->pluginConnector, &KU_BluetoothMusic_PluginConnector::mediaPreviousSlot);
    QObject::connect(this->musicControllerWidget, &MusicController::mediaNextSignal,
                     this->pluginConnector, &KU_BluetoothMusic_PluginConnector::mediaNextSlot);
    QObject::connect(this->musicControllerWidget, &MusicController::mediaPlaySignal,
                     this->pluginConnector, &KU_BluetoothMusic_PluginConnector::mediaPlaySlot);
    QObject::connect(this->musicControllerWidget, &MusicController::mediaPauseSignal,
                     this->pluginConnector, &KU_BluetoothMusic_PluginConnector::mediaPauseSlot);
    return true;
}

bool KU_BluetoothMusic_Plugin::stop()
{
    return true;
}

QWidget* KU_BluetoothMusic_Plugin::createWidget()
{
    return this->musicControllerWidget;
}

QWidget* KU_BluetoothMusic_Plugin::createSettingsWidget()
{
    return nullptr;
}

QWidget* KU_BluetoothMusic_Plugin::createAboutWidget()
{
    return nullptr;
}

bool KU_BluetoothMusic_Plugin::loadSettings()
{
    return true;
}

bool KU_BluetoothMusic_Plugin::saveSettings() const
{
    return KU::Settings::instance()->status() == QSettings::NoError;
}
