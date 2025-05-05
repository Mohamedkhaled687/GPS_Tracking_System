import QtQuick 2.15
import QtQuick.Controls 2.15
import QtLocation
import QtPositioning

Window {
    width: 1200
    height: 700
    visible: true
    title: qsTr("GPS GUI Application")

    // Serial port connection controls
    Rectangle {
        id: connectionPanel
        width: 250
        height: 120
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.margins: 10
        color: "#f0f0f0"
        radius: 5
        border.color: "#cccccc"
        border.width: 1

        Column {
            anchors.fill: parent
            anchors.margins: 10
            spacing: 10

            Label {
                text: "Serial Port Connection"
                font.bold: true
                font.pixelSize: 14
            }

            ComboBox {
                id: portComboBox
                width: parent.width
                model: serialCom.availablePorts()
            }

            Row {
                spacing: 10
                Button {
                    text: serialCom.isConnected ? "Disconnect" : "Connect"
                    width: 100
                    onClicked: {
                        if (serialCom.isConnected) {
                            serialCom.disconnectFromPort()
                        } else {
                            serialCom.connectToPort(portComboBox.currentText)
                        }
                    }
                }
                Button {
                    text: "Refresh"
                    width: 100
                    onClicked: portComboBox.model = serialCom.availablePorts()
                }
            }
        }
    }

    // Status indicator
    Rectangle {
        id: statusIndicator
        width: 12
        height: 12
        radius: 6
        anchors {
            bottom: connectionPanel.bottom
            horizontalCenter: connectionPanel.horizontalCenter
            bottomMargin: 10
        }
        color: serialCom.isConnected ? "#4CAF50" : "#f44336"
    }

    Label {
        id: statusLabel
        anchors.left: statusIndicator.right
        anchors.leftMargin: 5
        anchors.verticalCenter: statusIndicator.verticalCenter
        text: serialCom.isConnected ? "Connected" : "Disconnected"
        color: serialCom.isConnected ? "#4CAF50" : "#f44336"
    }

    Rectangle {
        id: gpsDisplay
        width: 680
        height: 400
        anchors {
            left: connectionPanel.right
            top: parent.top
            bottom: parent.bottom
            right: parent.right
            leftMargin: 5
        }

        // These properties hold the raw GPS values from serialCom
        property real gpsLongitude: 0.0
        property real gpsLatitude: 0.0
        property real currentLongitude: gpsLongitude
        property real currentLatitude: gpsLatitude

        // Add a property list to store path coordinates
        property var pathCoordinates: []
        property bool firstCoordinateReceived: false

        // Add error handling for invalid coordinates
        function isValidCoordinate(lat, lon) {
            return !isNaN(lat) && !isNaN(lon) &&
                   lat >= -90 && lat <= 90 &&
                   lon >= -180 && lon <= 180;
        }

        // Modified function to update path
        function updatePath(lat, lon) {
            var newCoord = QtPositioning.coordinate(lat, lon);

            if (!firstCoordinateReceived) {
                firstCoordinateReceived = true;
                pathCoordinates = [newCoord];
            } else {
                // Create a new array with all existing coordinates plus the new one
                var newPath = pathCoordinates.slice(); // Create a copy of the existing array
                newPath.push(newCoord);
                pathCoordinates = newPath; // Assign the new array to trigger update
            }
            // Force update of the polyline
            pathLine.path = pathCoordinates;
        }

        Map {
            id: map
            anchors.fill: parent
            zoomLevel: 16
            center: QtPositioning.coordinate(0, 0)
            plugin: Plugin {
                name: "osm"
                PluginParameter {
                    name: "osm.useragent"
                    value: "MyGPSApp"
                }
                PluginParameter {
                    name: "osm.mapping.custom.host"
                    value: "https://tile.openstreetmap.org/"
                }
            }

            // Modified MapPolyline for better visibility
            MapPolyline {
                id: pathLine
                line.width: 4
                line.color: "blue"
                path: gpsDisplay.pathCoordinates
            }

            MapQuickItem {
                id: carMarker
                coordinate: QtPositioning.coordinate(gpsDisplay.currentLatitude, gpsDisplay.currentLongitude)
                anchorPoint.x: marker.width / 2
                anchorPoint.y: marker.height
                sourceItem: Image {
                    id: marker
                    width: 20
                    height: 20
                    source: "marker.png"
                    z: 2
                }
            }
        }

        Row {
            spacing: 10
            anchors.top: parent.top
            anchors.right: parent.right
            anchors.topMargin: 10
            anchors.rightMargin: 10
            Button {
                text: "+"
                width: 20
                height: 20
                onClicked: map.zoomLevel = Math.min(map.zoomLevel + 1, 20)
            }
            Button {
                text: "-"
                width: 20
                height: 20
                onClicked: map.zoomLevel = Math.max(map.zoomLevel - 1, 2)
            }
            Button {
                text: "Clear"
                width: 50
                height: 20
                onClicked: {
                    gpsDisplay.pathCoordinates = [];
                    gpsDisplay.firstCoordinateReceived = false;
                    pathLine.path = [];
                }
            }
        }

        Behavior on currentLongitude {
            NumberAnimation { duration: 25; easing.type: Easing.InOutQuad }
        }
        Behavior on currentLatitude {
            NumberAnimation { duration: 25; easing.type: Easing.InOutQuad }
        }

        Connections {
            target: serialCom
            function onGpsLongitudeChanged() {
                if (gpsDisplay.isValidCoordinate(serialCom.gpsLatitude, serialCom.gpsLongitude)) {
                    gpsDisplay.gpsLongitude = serialCom.gpsLongitude;
                    gpsDisplay.currentLongitude = serialCom.gpsLongitude;
                    gpsDisplay.currentLatitude = serialCom.gpsLatitude;
                    var newCoord = QtPositioning.coordinate(serialCom.gpsLatitude, serialCom.gpsLongitude);
                    map.center = newCoord;
                    // Only update path when both coordinates have changed
                    gpsDisplay.updatePath(serialCom.gpsLatitude, serialCom.gpsLongitude);
                }
            }
            function onGpsLatitudeChanged() {
                if (gpsDisplay.isValidCoordinate(serialCom.gpsLatitude, serialCom.gpsLongitude)) {
                    gpsDisplay.gpsLatitude = serialCom.gpsLatitude;
                    gpsDisplay.currentLongitude = serialCom.gpsLongitude;
                    gpsDisplay.currentLatitude = serialCom.gpsLatitude;
                    var newCoord = QtPositioning.coordinate(serialCom.gpsLatitude, serialCom.gpsLongitude);
                    map.center = newCoord;
                    // Only update path when both coordinates have changed
                    gpsDisplay.updatePath(serialCom.gpsLatitude, serialCom.gpsLongitude);
                }
            }
        }
    }
}
