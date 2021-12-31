#ifndef BLUETOOTHMUSICCONNECTOR_H
#define BLUETOOTHMUSICCONNECTOR_H

#include <QVariantMap>
#include "plugininterface.h"
#include "mediadefines.h"

class KU_BluetoothMusic_PluginConnector : public KU::PLUGIN::PluginConnector
{
    Q_OBJECT

    Q_PROPERTY(QString track MEMBER track NOTIFY trackChanged)
    Q_PROPERTY(int duration MEMBER duration NOTIFY trackChanged)
    Q_PROPERTY(int position MEMBER position NOTIFY positionChanged)
    Q_PROPERTY(int status MEMBER status NOTIFY statusChanged)

public:
    virtual void pluginSlot(QString const& signal, QVariantMap const& data) override;

    Q_INVOKABLE void mediaPrevious();
    Q_INVOKABLE void mediaNext();
    Q_INVOKABLE void mediaPlay();
    Q_INVOKABLE void mediaPause();

signals:
    void trackChanged();
    void positionChanged();
    void statusChanged();

private:
    QString track;
    int     duration = 0;
    int     position = 0;
    int     status   = MediaStatus::Stopped;
};

#endif // BLUETOOTHMUSICCONNECTOR_H
