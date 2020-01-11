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

QSet<KU::PLUGIN::PluginInfo> KU_BluetoothMusic_Plugin::dependencies() const
{
    return QSet<KU::PLUGIN::PluginInfo>();
}

QString KU_BluetoothMusic_Plugin::license() const
{
    return "LGPL";
}

QIcon KU_BluetoothMusic_Plugin::icon() const
{
    return QIcon();
}

bool KU_BluetoothMusic_Plugin::initialize(const QSet<KU::PLUGIN::PluginInterface*>& plugins)
{
    if(QFontDatabase::addApplicationFont(":/FontAwesome") < 0)
        qWarning() << "FontAwesome cannot be loaded !";

    qDebug() << this->name() << "initialize";
    for(auto& p : plugins)
    {
        qDebug() << p->name();
        auto bluetoothPlugin = dynamic_cast<KU::PLUGIN::BluetoothPluginInterface*>(p);
        if(bluetoothPlugin != nullptr)
        {
            this->bluetoothPlugin = bluetoothPlugin;
            QObject::connect(this->bluetoothPlugin->getBluetoothConnector(), &KU::PLUGIN::BluetoothConnector::trackChanged,
                             this->musicControllerWidget, &MusicController::trackChanged);
            QObject::connect(this->bluetoothPlugin->getBluetoothConnector(), &KU::PLUGIN::BluetoothConnector::nameChanged,
                             this->musicControllerWidget, &MusicController::nameChanged);
            QObject::connect(this->bluetoothPlugin->getBluetoothConnector(), &KU::PLUGIN::BluetoothConnector::positionChanged,
                             this->musicControllerWidget, &MusicController::positionChanged);
            QObject::connect(this->bluetoothPlugin->getBluetoothConnector(), &KU::PLUGIN::BluetoothConnector::repeatChanged,
                             this->musicControllerWidget, &MusicController::repeatChanged);
            QObject::connect(this->bluetoothPlugin->getBluetoothConnector(), &KU::PLUGIN::BluetoothConnector::shuffleChanged,
                             this->musicControllerWidget, &MusicController::shuffleChanged);
            QObject::connect(this->bluetoothPlugin->getBluetoothConnector(), &KU::PLUGIN::BluetoothConnector::statusChanged,
                             this->musicControllerWidget, &MusicController::statusChanged);

            QObject::connect(this->musicControllerWidget, &MusicController::mediaPrevious,
                             this->bluetoothPlugin->getBluetoothConnector(), &KU::PLUGIN::BluetoothConnector::mediaPrevious);
            QObject::connect(this->musicControllerWidget, &MusicController::mediaNext,
                             this->bluetoothPlugin->getBluetoothConnector(), &KU::PLUGIN::BluetoothConnector::mediaNext);
            QObject::connect(this->musicControllerWidget, &MusicController::mediaPlay,
                             this->bluetoothPlugin->getBluetoothConnector(), &KU::PLUGIN::BluetoothConnector::mediaPlay);
            QObject::connect(this->musicControllerWidget, &MusicController::mediaPause,
                             this->bluetoothPlugin->getBluetoothConnector(), &KU::PLUGIN::BluetoothConnector::mediaPause);
        }
    }
    return true;
}

bool KU_BluetoothMusic_Plugin::stop()
{
    return true;
}

QWidget* KU_BluetoothMusic_Plugin::createWidget()
{
    this->musicControllerWidget = new MusicController;
    return this->musicControllerWidget;
}

QWidget* KU_BluetoothMusic_Plugin::createSettingsWidget()
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
