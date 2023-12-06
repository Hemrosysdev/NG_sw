import QtQuick 2.12
import QtQml 2.12
import "../../CommonItems"
import SettingsSerializerEnum 1.0

Item {
    id: idRoot;

    property bool visualDebug: false;
    //property bool userRightObtained: settingsStateMachine.userRightsObtained;

    width: 480;
    height: 360;

    Component.onCompleted:
    {
        updateShownDiskUsgaeTime();
    }

    function updateShownDiskUsgaeTime()
    {
        let usageTime = Math.ceil( diskUsageTime.readX100Secs()/100.0 /60 /60 );
        let remainingTime = diskUsageTime.estimatedMax - usageTime;

        idText.text = "" + usageTime + " h";
        idBarLabel.text = ((remainingTime<0)?"+":"") + ((-1)*remainingTime) + " h";
        idBarGraph.criticalLowPercentage = 0.0;
        idBarGraph.criticalHighPercentage = 0.8;
        idBarGraph.currentPercentage = (usageTime* 1.0)/diskUsageTime.estimatedMax;
    }

    Item
    {
        anchors.centerIn: parent;
        width: Math.max(idText.width, idBarGraph.width + idBarLabel.width + 10);
        height: idText.height + idBarLabel.height +6;

        Text
        {
            id: idText;
            x: parent.width/2 - width/2;
            y: 0;
            horizontalAlignment: Text.AlignHCenter;
            verticalAlignment: Text.AlignVCenter;

            font.pixelSize: 58;
            font.letterSpacing: 2;
            font.bold: true;
            font.family: "D-DIN Condensed HEMRO"

            color: idMain.colorEkxTextWhite;
            text: "unknown h";

            DebugFrame{ visible: idRoot.visualDebug; }
        }

        BarGraph
        {
            id: idBarGraph;
            x: 0;
            y: idBarLabel.y + idBarLabel.height/2 - height/2;
            width: 350;

            criticalLowPercentage: 0.30;
            criticalHighPercentage: 0.80;
            currentPercentage: 0.41;

            DebugFrame{ visible: idRoot.visualDebug; }
        }

        Text
        {
            id: idBarLabel;
            x: parent.width - width;
            y: parent.height - height;

            horizontalAlignment: Text.AlignRight;
            verticalAlignment: Text.AlignVCenter;

            font.pixelSize: 36
            font.letterSpacing: 1.8
            font.bold: false
            font.family: "D-DIN Condensed HEMRO"

            color: false ? idMain.colorEkxConfirmRed : idMain.colorEkxTextGrey
            text: "-abc h";

            DebugFrame{ visible: idRoot.visualDebug; }
        }

        DebugFrame{ visible: idRoot.visualDebug; }
    }

    Text
    {
        width: 240;
        height: 80;
        anchors.right: parent.right;
        anchors.bottom: parent.bottom;

        horizontalAlignment: Text.AlignHCenter;
        verticalAlignment: Text.AlignVCenter;

        //font.pixelSize: 58
        font.pixelSize: 43
        //font.letterSpacing: 0.23
        font.letterSpacing: 1.48
        font.bold: false
        font.family: "D-DIN Condensed HEMRO"

        color: (settingsSerializer.userAutoLoginAs===SettingsSerializerEnum.LOGGEDIN_STOREOWNER
                || settingsSerializer.userAutoLoginAs===SettingsSerializerEnum.LOGGEDIN_TECHNICIAN) ?
                   idMain.colorEkxTextWhite : idMain.colorEkxTextGrey;
        text: "Reset";

        Component.onCompleted:
        {
            console.log("settingsSerializer.userAutoLoginAs: "+settingsSerializer.userAutoLoginAs);
            console.log("settingsSerializer.tempUnit: "+settingsSerializer.tempUnit);
        }

        MouseArea
        {
            anchors.fill: parent;
            onClicked:
            {
                if(settingsSerializer.userAutoLoginAs===SettingsSerializerEnum.LOGGEDIN_STOREOWNER
                      || settingsSerializer.userAutoLoginAs===SettingsSerializerEnum.LOGGEDIN_TECHNICIAN)
              {
                    //idConfirmScreen.navAvailableBackup = settingsStateMachine.navAvailable;
                    idConfirmScreen.visible = true;
              }
              // else
              // {
              //     idPinScreen.visible = true;
              // }
            }
        }
    }

    Rectangle
    {
        // ConfirmScreen is missing a background, addding it.
        visible: idConfirmScreen.visible;
        anchors.fill: idConfirmScreen;
        color: "black";
    }

    ConfirmScreen
    {
        id: idConfirmScreen;
        visible: false;
        infoText: "Do you want\nto reset the\ndisk usage time?";
        confirmText: "Reset";
        onUserConfirmed:
        {
            diskUsageTime.reset();
            updateShownDiskUsgaeTime();
        }
    }
}
