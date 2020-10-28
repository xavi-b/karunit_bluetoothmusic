#ifndef BLUETOOTHMUSICPLUGIN_H
#define BLUETOOTHMUSICPLUGIN_H

#include <QtPlugin>
#include <QIcon>
#include <QDebug>
#include <QLabel>
#include <QDateTime>
#include <QFontDatabase>
#include "plugininterface.h"
#include "settings.h"
#include "musiccontroller.h"
#include "bluetoothmusicconnector.h"

class KU_BluetoothMusic_Plugin : public QObject, public KU::PLUGIN::PluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "xavi-b.karunit.PluginInterface")
    Q_INTERFACES(KU::PLUGIN::PluginInterface)

public:
    KU_BluetoothMusic_Plugin();
    ~KU_BluetoothMusic_Plugin();
    virtual QString name() const override;
    virtual QString id() const override;
    virtual KU::PLUGIN::PluginVersion version() const override;
    virtual QString license() const override;
    virtual QIcon icon() const override;
    virtual bool initialize() override;
    virtual bool stop() override;

    virtual QWidget* createWidget() override;
    virtual QWidget* createSettingsWidget() override;
    virtual QWidget* createAboutWidget() override;
    virtual bool loadSettings() override;
    virtual bool saveSettings() const override;

private:
    MusicController* musicControllerWidget = nullptr;
    KU_BluetoothMusic_PluginConnector* pluginConnector = nullptr;
};


#endif // BLUETOOTHMUSICPLUGIN_H
