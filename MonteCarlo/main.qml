import QtQuick 2.14
import QtQuick.Window 2.14
import QtQuick.Layouts 1.14
import QtQuick.Controls 2.14
import cryptocoin.monte.carlo 1.0

Window {
    id: window
    visible: true
    width: 1600
    height: 900
    title: qsTr("Simulare Monte Carlo")


    // Cripto-monedele definite
    CryptoCoin {
        id: ethereum
        name: qsTr("Ethereum")
        abbreviation: qsTr("ETH")
        value_in_usd: 0287.531
        mod_rate: 5
    }

    CryptoCoin {
        id: bitcoin
        name: qsTr("Bitcoin")
        abbreviation: qsTr("BTC")
        value_in_usd: 8054.234
        mod_rate: 8
    }

    /*Interfata grafica a aplicatiei*/

    ScrollView { // Container ce permite scrolarea aplicatiei in cazul in care este redimensionata fereastra
        id: flickable
        width: main_column.width
        height: main_column.height
        clip: true

        ScrollBar.vertical.policy: ScrollBar.AsNeeded
        ScrollBar.horizontal.policy: ScrollBar.AsNeeded

        ColumnLayout { // Coloana principala in care sunt asezate elementele
            id: main_column
            width: Window.width
            height: Window.height
            transformOrigin: Item.Center

            // Coloana cu informatii generale initiale
            ColumnLayout {
                id: initial_info
                Layout.fillHeight: true
                Layout.fillWidth: true
                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter

                RowLayout {
                    id: investment_row
                    Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                    Layout.fillWidth: true
                    Layout.fillHeight: true

                    Label {
                        id: investment_label
                        text: qsTr("Investitie: ")
                        textFormat: Text.AutoText
                        verticalAlignment: Text.AlignVCenter
                        horizontalAlignment: Text.AlignHCenter
                        font.family: "DejaVu Sans Mono"
                        font.italic: true
                        font.pointSize: 16
                    }



                    TextField {
                        id: investment_value
                        clip: true
                        placeholderText: ethereum.investment
                        placeholderTextColor: "#888687"
                        renderType: Text.NativeRendering
                        horizontalAlignment: Text.AlignHCenter
                        font.family: "DejaVu Sans Mono"
                        font.italic: true
                        font.pointSize: 16
                        onTextEdited: {
                            ethereum.investment = investment_value.text
                            bitcoin.investment = investment_value.text
                        }
                        Layout.alignment: Qt.AlignCenter
                    }

                    Button {
                        id: buy_coins
                        text: qsTr("Buy coins")
                        font.family: "DejaVu Sans"
                        font.pointSize: 14

                        onClicked: {
                            ethereum.buyCoins()
                            bitcoin.buyCoins()

                            eth_coins_label.text = qsTr("Numarul de " + ethereum.abbreviation + " " + ethereum.getCoins())
                            btc_coins_label.text = qsTr("Numarul de " + bitcoin.abbreviation + " " + bitcoin.getCoins())
                        }
                    }

                }
            }

            // Coloana pentru Ethereum
            ColumnLayout {
                id: ethereum_column
                Layout.fillHeight: true
                Layout.fillWidth: true
                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter

                // Prima linie contine un logo si numele cripto-monedei
                RowLayout {
                    id: crypto_1
                    Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                    Layout.fillWidth: true
                    Layout.fillHeight: true

                    Image {
                        id: crypto_1_logo
                        source: "res/images/Ethereum_logo_2014.svg"
                        Layout.preferredHeight: 200
                        Layout.preferredWidth: 200
                        fillMode: Image.PreserveAspectFit
                    }

                    Text {
                        id: crypto_1_name
                        text: ethereum.name
                        font.family: "DejaVu Sans"
                        font.pointSize: 15
                        Layout.leftMargin: 15
                    }

                }

                // A doua linie contine o casuta cu ajutorul careia se poate modifica valoarea monedei
                // Clasa din C++ este legata de TextField-ul de pe acest rand
                RowLayout {
                    Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                    Layout.fillWidth: true
                    Layout.fillHeight: true

                    Label {
                        id: crypto_1_value_label
                        text: qsTr("1 " + ethereum.abbreviation + " = $")
                        font.family: "DejaVu Sans Mono"
                        font.italic: true
                        font.pointSize: 18
                    }


                    TextField {
                        id: crypto_1_value
                        clip: true
                        placeholderText: ethereum.value_in_usd
                        placeholderTextColor: "#888687"
                        horizontalAlignment: Text.AlignHCenter
                        renderType: Text.NativeRendering
                        font.family: "DejaVu Sans Mono"
                        font.italic: true
                        font.pointSize: 18
                        onTextEdited: {
                            ethereum.value_in_usd = crypto_1_value.text
                        }
                        Layout.alignment: Qt.AlignCenter
                    }


                }

                RowLayout {
                    Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                    Layout.fillWidth: true
                    Layout.fillHeight: true

                    Label {
                        id: eth_coins_label
                        text: qsTr("Numarul de " + ethereum.abbreviation + " " + ethereum.getCoins())
                        font.family: "DejaVu Sans Mono"
                        font.italic: true
                        font.pointSize: 18
                    }

                }

                // Acest rand contine abilitatea de a shimba rata initiala a modificarii valorii
                RowLayout {
                    Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                    Layout.fillWidth: true
                    Layout.fillHeight: true

                    Label {
                        id: crypto_1_mod_label
                        text: qsTr("Probabilitatea sa se modifice pana maine = ")
                        font.family: "DejaVu Sans Mono"
                        font.italic: true
                        font.pointSize: 16
                    }



                    TextField {
                        id: crypto_1_mod
                        clip: true
                        placeholderText: ethereum.mod_rate
                        placeholderTextColor: "#888687"
                        horizontalAlignment: Text.AlignHCenter
                        renderType: Text.NativeRendering
                        font.family: "DejaVu Sans Mono"
                        font.italic: true
                        font.pointSize: 16
                        onTextEdited: {
                            ethereum.mod_rate = crypto_1_mod.text
                        }
                        Layout.alignment: Qt.AlignCenter
                    }


                }

                RowLayout {
                    Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                    Layout.fillWidth: true
                    Layout.fillHeight: true

                    Text {
                        id: final_sum_ethereum
                        text: qsTr("Suma initiala = " + ethereum.investment)
                        font.family: "DejaVu Sans Mono"
                        font.italic: true
                        font.pointSize: 16
                    }
                }
            }

            // Coloana pentru Bitcoin
            // Randurile din aceasta coloana sunt identice cu cele pentru Ethereum
            ColumnLayout {
                id: bitcoin_column
                Layout.fillHeight: true
                Layout.fillWidth: true
                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter

                RowLayout {
                    id: crypto_2
                    Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                    Layout.fillWidth: true
                    Layout.fillHeight: true

                    Image {
                        id: crypto_2_logo
                        Layout.fillWidth: false
                        Layout.fillHeight: false
                        source: "res/images/Bitcoin_logo.svg"
                        Layout.preferredHeight: 200
                        Layout.preferredWidth: 200
                        fillMode: Image.PreserveAspectFit
                    }

                    Text {
                        id: crypto_2_name
                        text: qsTr(bitcoin.name)
                        font.family: "DejaVu Sans"
                        font.pointSize: 15
                        Layout.leftMargin: 15
                    }
                }

                RowLayout {
                    Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                    Layout.fillWidth: true
                    Layout.fillHeight: true

                    Label {
                        id: crypto_2_value_label
                        text: qsTr("1 " + bitcoin.abbreviation + " = $")
                        font.family: "DejaVu Sans Mono"
                        font.italic: true
                        font.pointSize: 18
                    }



                    TextField {
                        id: crypto_2_value
                        clip: true
                        placeholderText: bitcoin.value_in_usd
                        placeholderTextColor: "#888687"
                        renderType: Text.NativeRendering
                        horizontalAlignment: Text.AlignHCenter
                        font.family: "DejaVu Sans Mono"
                        font.italic: true
                        font.pointSize: 18
                        onTextEdited: {
                            bitcoin.value_in_usd = crypto_2_value.text
                        }
                        Layout.alignment: Qt.AlignCenter
                    }


                }

                RowLayout {
                    Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                    Layout.fillWidth: true
                    Layout.fillHeight: true

                    Label {
                        id: btc_coins_label
                        text: qsTr("Numarul de " + bitcoin.abbreviation + " " + bitcoin.getCoins())
                        font.family: "DejaVu Sans Mono"
                        font.italic: true
                        font.pointSize: 18
                    }


                }

                RowLayout {
                    Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                    Layout.fillWidth: true
                    Layout.fillHeight: true

                    Label {
                        id: crypto_2_mod_label
                        text: qsTr("Probabilitatea sa se modifice pana maine = ")
                        font.family: "DejaVu Sans Mono"
                        font.italic: true
                        font.pointSize: 16
                    }



                    TextField {
                        id: crypto_2_mod
                        clip: true
                        placeholderText: bitcoin.mod_rate
                        placeholderTextColor: "#888687"
                        renderType: Text.NativeRendering
                        horizontalAlignment: Text.AlignHCenter
                        font.family: "DejaVu Sans Mono"
                        font.italic: true
                        font.pointSize: 16
                        onTextEdited: {
                            bitcoin.mod_rate = crypto_2_mod.text
                        }
                        Layout.alignment: Qt.AlignCenter
                    }


                }

                RowLayout {
                    Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                    Layout.fillWidth: true
                    Layout.fillHeight: true

                    Text {
                        id: final_sum_bitcoin
                        text: qsTr("Suma initiala = " + bitcoin.investment)
                        font.family: "DejaVu Sans Mono"
                        font.italic: true
                        font.pointSize: 16
                    }
                }
            }

            // Coloana contine butonul ce porneste simularea
            ColumnLayout {
                id: start_simulation_column
                Layout.fillHeight: true
                Layout.fillWidth: true
                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter

                RowLayout {
                    Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                    Layout.fillWidth: true
                    Layout.fillHeight: true

                    Button {
                        id: start_simulation
                        text: "Porneste simularea"
                        font.bold: true
                        font.family: "DejaVu Sans"
                        font.pointSize: 14

                        onClicked: {
                            // Simularea pentru fiecare moneda in parte
                            ethereum.simulate(10000);
                            bitcoin.simulate(10000);

                            /*Modificarea unor valori din interfata dupa simulare*/
                            crypto_1_value.text = ethereum.value_in_usd
                            crypto_2_value.text = bitcoin.value_in_usd

                            final_sum_ethereum.text = qsTr("Suma finala = " + ethereum.final_sum)
                            final_sum_bitcoin.text = qsTr("Suma finala = " + bitcoin.final_sum)
                        }
                    }
                }
            }
        }
    }


}
