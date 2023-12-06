var pingErrorCnt = 0;
var maxPingErrorCnt = 5;
var aliveInterval = null;

/********************************************************************************/

function confirmAlive( result )
{
	var jsonResult = null;
	
	try
	{
		jsonResult = JSON.parse( result );

		if ( jsonResult.msgType == "Pong" )
		{
			if ( pingErrorCnt >= maxPingErrorCnt )
			{
				closeConfirmPopup();
				location.reload();
			}
			pingErrorCnt = 0;
		}
	}
	catch ( e )
	{
	}
}

/********************************************************************************/

function forceConfirmAlive()
{
	pingErrorCnt = 0;
}

/********************************************************************************/

function processAliveCheck()
{
	pingErrorCnt++;

	var jsonCmd = 
	{
		msgType : "Ping",
	};

	restApiCmd( false, "Ping request", jsonCmd, confirmAlive );

	if ( pingErrorCnt == maxPingErrorCnt + 1 )
	{
		openConfirmPopup( 	"Connection watchdog", 
							"Connection to grinder lost!</br>"
							+ "The web interface tries to reconnect soon.</br></br>"
							+ "If connection cannot be established again,</br>"
							+ "please check your WiFi connection." );
		disableConfirmPopupCancel();
		disableConfirmPopupClose();
		disableConfirmPopupOk();
	}
}

/********************************************************************************/

function setAliveInterval( intervalMs )
{
	clearInterval( aliveInterval );
	aliveInterval = setInterval( processAliveCheck, intervalMs );
}

/********************************************************************************/

window.addEventListener( 	"load", 
							function() 
							{
								setAliveInterval( 1000 );
							},
							false );

/********************************************************************************/
