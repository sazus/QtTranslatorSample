import QtQuick 2.7

Rectangle {
    id: _root
    objectName: "qml_root"

    property int fontSize: 32

    width:  480
    height: 240

    Item {
        id: _item
        objectName: "qml_item"
        signal qmlBottonClick(string locale)
    }

    Text {
        id: _chenge_text
        objectName: "qml_text"

        text: qsTr("Apple pen!")
        font.pixelSize: fontSize
        anchors.centerIn: parent
    }

    // ボタンRow(横)配置
    Row {
        id: _botton

        spacing: 2
        anchors.bottom: parent.bottom
        anchors.horizontalCenter: parent.horizontalCenter

        // 日本語ボタン
        Rectangle {
            id: _botton_jp

            width: 150; height: 50;
            radius: 10
            color: "lightgray"
            border { width: 2; color: _botton_jp_mouse.enabled?
                                                        "red" : "transparent"; }

            Text {
                text: qsTr("Japanese")
                font.pixelSize: fontSize
                anchors.centerIn: parent
            }
            MouseArea {
                id: _botton_jp_mouse

                anchors.fill: parent
                onClicked: {
                    _item.qmlBottonClick("ja_JP")
                    console.log("click id:_botton_jpn");
                }
            }
            states: [
                State {
                    when: _botton_jp_mouse.pressed
                    PropertyChanges { target: _botton_jp; color: "gray"; }
                }
            ]
        }

        // 中国語ボタン
        Rectangle {
            id: _botton_zh

            width: 150; height: 50;
            radius: 10
            color: "lightgray"
            border { width: 2; color: _botton_zh_mouse.enabled?
                                                        "red" : "transparent"; }

            Text {
                text: qsTr("Chinese")
                font.pixelSize: fontSize
                anchors.centerIn: parent
            }
            MouseArea {
                id : _botton_zh_mouse
                anchors.fill: parent
                onClicked: {
                    _item.qmlBottonClick("zh_CN")
                    console.log("click id:_botton_zh");
                }
            }
            states: [
                State {
                    when: _botton_zh_mouse.pressed
                    PropertyChanges { target: _botton_zh; color: "gray"; }
                }
            ]
        }

        // 英語ボタン
        Rectangle {
            id: _botton_en

            width: 150; height: 50;
            radius: 10
            color: "lightgray"
            border { width: 2; color: _botton_en_mouse.enabled?
                                                        "red" : "transparent"; }

            Text {
                text: qsTr("English")
                font.pixelSize: fontSize
                anchors.centerIn: parent
            }
            MouseArea {
                id: _botton_en_mouse

                anchors.fill: parent
                onClicked: {
                    _item.qmlBottonClick("en_US")
                    console.log("click id:_botton_en");
                }
            }
            states: [
                State {
                    when: _botton_en_mouse.pressed
                    PropertyChanges { target: _botton_en; color: "gray"; }
                }
            ]
        }
    }
}
