// import QtQuick 1.0 // to target Maemo 5
import QtQuick 1.1

Rectangle {
    width: 360
    height: 360
    Text {
        anchors.centerIn: parent
        text: "Hello World"
    }
    MouseArea {
        x: 0
        y: -6
        anchors.rightMargin: 0
        anchors.bottomMargin: 6
        anchors.leftMargin: 0
        anchors.topMargin: -6
        anchors.fill: parent
        onClicked: {
            Qt.quit();
        }
    }
}
