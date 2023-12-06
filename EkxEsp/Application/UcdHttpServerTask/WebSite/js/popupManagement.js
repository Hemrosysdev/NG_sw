/********************************************************************************/

const eventClosePopup = new Event( "eventClosePopup" );

/********************************************************************************/

function startModal()
{
	// When the modal is shown, we want a fixed body
	const scrollY = document.documentElement.scrollTop;
	document.body.style.position = 'fixed';
	document.body.style.top = '-' + scrollY + 'px';
}

/********************************************************************************/

function stopModal()
{
	const scrollY = document.body.style.top;
	document.body.style.position = '';
	document.body.style.top = '';
	document.documentElement.scrollTop = -parseInt( scrollY );
}

/********************************************************************************/

function closeConfirmPopup()
{
	stopModal();
	$( "#confirm_popup" ).hide();
	$( "#confirm_popup_ok" ).unbind( "click" );
}

/********************************************************************************/

function openConfirmPopup( strCaption, strPrompt )
{
	startModal();

	$( "#confirm_popup" ).show();
	$( "#confirm_popup_caption_text" ).text( strCaption );
	$( "#confirm_popup_content" ).text( strPrompt );

	$( "#confirm_popup_ok" ).unbind( "click" );
}

/********************************************************************************/

function disableConfirmPopupCancel()
{
	$( "#confirm_popup_cancel" ).hide();
}

/********************************************************************************/

function disableConfirmPopupOk()
{
	$( "#confirm_popup_ok" ).hide();
}

/********************************************************************************/

function enableConfirmPopupOk( onClickFunction )
{
	$( "#confirm_popup_ok" ).show();
	
	if ( onClickFunction )
	{
		confirmPopupOk.onclick = onClickFunction;
	}
}

/********************************************************************************/

function disableConfirmPopupClose()
{
	$( "#confirm_popup_close" ).hide();
}

/********************************************************************************/

function closePopup()
{
	stopModal();
	popup.style.display = "none";
	document.dispatchEvent( eventClosePopup );
}

/********************************************************************************/

function enablePopupOk()
{
	popupOk.style.display = "block";
	popupCancel.style.display = "none";
	popupContent.style.height = "390px";
}

/********************************************************************************/

function enablePopupCancel()
{
	popupCancel.style.display = "block";
}

/********************************************************************************/

function disablePopupCancel()
{
	popupCancel.style.display = "none";
}

/********************************************************************************/

function openPopup( strCaption, bStartLoader )
{
	startModal();

	popupCaptionText.innerHTML = strCaption;
	popup.style.display = "block";
	preElement.innerHTML = "";
	logElement.innerHTML = "";
	
	enableLoader( bStartLoader );
	popupProgressInfo.style.display = "none";
	popupOk.style.display = "none";
	popupCancel.style.display = "none";
	popupContent.style.height = "490px";
}

/********************************************************************************/

function enableLoader( bEnable )
{
	if ( bEnable )
	{
		popupLoader.style.display = "block";
	}
	else
	{
		popupLoader.style.display = "none";
	}
}

/********************************************************************************/

function showNormalLog( result )
{
	preElement.innerHTML = "";
	logElement.innerHTML = result;
}

/********************************************************************************/

function setPopupEta( eta )
{
	popupEta.innerHTML = eta;
}

/********************************************************************************/

function showProgressInfo( info )
{
	popupUploadFile.innerHTML = info;
}

/********************************************************************************/

function showPreLog( result )
{
	preElement.innerHTML = "";
	logElement.innerHTML = "";
	var res = result.split("\\n");
	for (let i of res) 
	{
		$("#pre_id").append(i);
	}
}

/********************************************************************************/

function showProgressBar( value )
{
	popupProgressInfo.style.display="block";
	popupProgressBarProgress.style.width = value;
	popupProgressBarValue.innerHTML = value;
}

/********************************************************************************/

function hideProgressBar()
{
	popupProgressInfo.style.display="none";
}

/********************************************************************************/