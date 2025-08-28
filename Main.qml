import QtQuick
import QtQuick.Controls

Window {
    property var slotResults: ["0", "0", "0"]

    width: 800
    height: width * 0.75
    visible: true
    title: qsTr("Hello Duck:>")
    color: "#b3e5fc"

    Rectangle {
        id: infoRect
        width: 280
        height: 80
        color: "#bc77b4"
        anchors {
            top: parent.top
            left: parent.left
            topMargin: 20
            leftMargin: 20
        }
        Text {
            id: infoText
            anchors.centerIn: parent
            text: "Balance: $" + backend.balance
            font.pixelSize: 32
        }
    }

    Row {
        spacing: 40
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter

        Repeater {
            model: 3
            Rectangle {
                width: 120
                height: 120
                color: "#8f3030"
                border.color: "#888"
                radius: 16
                Text {
                    anchors.centerIn: parent
                    text: slotResults[index]
                    font.pixelSize: 64
                }
            }
        }
    }

    Button {
        text: "Spin (100$)"
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 60
        width: 300
        height: 100
        font.pixelSize: 48
        onClicked: {
            slotResults = backend.spinSlots()
        }
    }
}