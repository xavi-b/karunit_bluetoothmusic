#ifndef TESTPLUGIN_H
#define TESTPLUGIN_H

#include <QtPlugin>
#include <QIcon>
#include <QDebug>
#include <QLabel>
#include <QDateTime>
#include <QFontDatabase>
#include "plugininterface.h"
#include "bluetoothinterface.h"
#include "settings.h"
#include "musiccontroller.h"

class KU_BluetoothMusic_Plugin : public QObject, public KU::PLUGIN::PluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "xavi-b.karunit.PluginInterface")
    Q_INTERFACES(KU::PLUGIN::PluginInterface)

public:
    virtual QString name() const override;
    virtual QString id() const override;
    virtual KU::PLUGIN::PluginVersion version() const override;
    virtual QString license() const override;
    virtual QIcon icon() const override;
    virtual bool initialize() override;
    virtual bool stop() override;

    virtual QWidget* createWidget() override;
    virtual QWidget* createSettingsWidget() override;
    virtual bool loadSettings() override;
    virtual bool saveSettings() const override;

private:
    MusicController* musicControllerWidget = nullptr;
    KU::PLUGIN::BluetoothPluginInterface* bluetoothPlugin = nullptr;
};


#endif // TESTPLUGIN_H
