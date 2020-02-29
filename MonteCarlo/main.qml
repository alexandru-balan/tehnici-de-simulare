import QtQuick 2.14
import QtQuick.Window 2.14
import QtQuick.Layouts 1.14

Window {
    visible: true
    width: 1080
    height: 720
    title: qsTr("Simulare Monte Carlo")

    ColumnLayout {
        id: main_column
        width: Window.width
        height: Window.height

        RowLayout {
            id: crypto_1
            Layout.fillWidth: true
            Layout.fillHeight: true

            Image {
                id: crypto_1_logo
                source: "./res/images/Ethereum_logo_2014.svg"
                Layout.preferredHeight: 100
                Layout.preferredWidth: 100
                fillMode: Image.PreserveAspectFit
            }


        }

        RowLayout {
            id: crypto_2
            Layout.fillWidth: true
            Layout.fillHeight: true

            Image {
                id: crypto_2_logo
                source: "./res/images/Bitcoin_logo.svg"
                Layout.preferredHeight: 100
                Layout.preferredWidth: 100
                fillMode: Image.PreserveAspectFit
            }
        }
    }
}
