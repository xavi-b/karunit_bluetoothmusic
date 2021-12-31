import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

import Karunit 1.0
import KarunitPlugins 1.0

Item {
    anchors.fill: parent

    Column {
        anchors.centerIn: parent

        Label {
            width: 400
            horizontalAlignment: Qt.AlignHCenter
            text: KUPBluetoothMusicPluginConnector.track
        }

        Row {
            anchors.horizontalCenter: parent.horizontalCenter
            spacing: 20

            Button {
                icon.name: "media-skip-backward"
                onClicked: {
                    KUPBluetoothMusicPluginConnector.mediaPrevious()
                }
            }

            Button {
                icon.name: KUPBluetoothMusicPluginConnector.status
                           === 0 ? "media-playback-pause" : "media-playback-start"
                onClicked: {
                    if (KUPBluetoothMusicPluginConnector.status === 5)
                        return

                    if (KUPBluetoothMusicPluginConnector.status === 0) {
                        KUPBluetoothMusicPluginConnector.status = 2
                        KUPBluetoothMusicPluginConnector.mediaPause()
                    } else {
                        KUPBluetoothMusicPluginConnector.status = 2
                        KUPBluetoothMusicPluginConnector.mediaPlay()
                    }
                }
            }

            Button {
                icon.name: "media-skip-forward"
                onClicked: {
                    KUPBluetoothMusicPluginConnector.mediaNext()
                }
            }
        }

        Slider {
            width: parent.width
            from: 0
            to: KUPBluetoothMusicPluginConnector.duration
            value: KUPBluetoothMusicPluginConnector.position
            enabled: false
        }
    }
}
