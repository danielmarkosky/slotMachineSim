import QtQuick
import QtQuick.Controls

Window {
    property var slotResults: [
        "qrc:/images/dollar.png",
        "qrc:/images/dollar.png",
        "qrc:/images/dollar.png"
    ]

    width: 800
    height: width * 0.75
    visible: true
    title: qsTr("Hello Duck:>")
    color: "#b3e5fc"

    Rectangle {
        id: infoRect
        width: 300
        height: 80
        color: "#bc77b4"
        anchors {
            top: parent.top
            left: parent.left
            topMargin: 20
            leftMargin: 20
        }
        Text {
            text: "Balance: $" + backend.balance
            font.pixelSize: 36
            color: "white"
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            anchors.centerIn: parent
            width: parent.width
            height: parent.height
        }
    }

    Row {
        spacing: 40
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter

        Repeater {
            model: 3
            Rectangle {
                width: 150
                height: 150
                color: "#8f3030"
                border.color: "#888"
                radius: 16
                Image {
                    anchors.fill: parent
                    anchors.margins: 16
                    source: slotResults[index]
                    width: parent.width
                    height: parent.height
                    fillMode: Image.PreserveAspectFit
                    smooth: true
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
