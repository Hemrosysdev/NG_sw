/********************************************************************************/

$(function () 
{
	var includes = $('[data-include]')
	$.each(includes, function () 
	{
		var file = $(this).data('include')
		$(this).load(file)
	})
})

/********************************************************************************/

function restApiCmd( bInteractive, strCaption, jsonCmdArray, onSuccessCallback = null )
{
	if ( bInteractive )
	{
		openPopup( strCaption, true );
	}

	var jsonString = JSON.stringify( jsonCmdArray, undefined, 4 );
	
	const url="/restApi?jsonCmd";
	$.ajax({
		url:url,
		type:"POST",
		data: jsonString,
		contentType: "application/json",
		success:
			function(result)
			{
				if ( bInteractive )
				{
					var log;
					
					try
					{
						jsonResult = JSON.parse( result );

						var log = jsonResult.data;
						
						if ( log != "" )
						{
							log += "\n\n";
						}

						if ( jsonResult.success )
						{
							log += "Successfully executed!";
						}
						else
						{
							log += "Execution failed!";
						}
					}
					catch ( e )
					{
						log = "Execution failed!\nAnswer is no JSON object.";
					}

					showPreLog( log );
				}
				else if ( onSuccessCallback != null )
				{
					onSuccessCallback( result );
				}
			},
		error:
			function(result)
			{
				if ( bInteractive )
				{
					showPreLog( "Command failed!" );
				}
			},
		complete: 
			function(result)
			{
				if ( bInteractive )
				{
					popupLoader.style.display = "none";
					enablePopupOk();
				}
			}
	})
}

/********************************************************************************/

function setStateColor( itemId, isFailed, failColor, goodColor )
{
	if ( isFailed )
	{
		$( itemId ).css( { "backgroundColor": failColor, "color": "white" } );
	}
	else
	{
		$( itemId ).css( { "backgroundColor": goodColor, "color": "white" } );
	}
}

/********************************************************************************/