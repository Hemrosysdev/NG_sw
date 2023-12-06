/*!*************************************************************************************************************************************************************
 *
 * @file UcdPwmOutQueue.cpp
 * @brief Source file of component unit UcdPwmOut.
 *
 * This file was developed as part of Spotlight.
 *
 * @author Ultratronik GmbH
 *         Dornierstr. 9
 *         D-82205 Gilching
 *         http://www.ultratronik.de
 * @author Srdjan Nikolic, Entwicklung - <optional according to the authors needs>
 *
 * @copyright Copyright 2020 by Ultratronik GmbH.
 *            All rights reserved.
 *            None of this file or parts of it may be
 *            copied, redistributed or used in any other way
 *            without written approval of Ultratronik GmbH.
 *
 **************************************************************************************************************************************************************/

/***************************************************************************************************************************************************************
 *      Includes
 **************************************************************************************************************************************************************/

#include "UcdPwmOutQueue.h"

#include <string>
#include <cstring>
#include "UcdPwmOutQueueTypes.h"

#include "FreeRtosQueueTask.h"

/*!************************************************************************************************************************************************************
 *
 *************************************************************************************************************************************************************/

UcdPwmOutQueue::UcdPwmOutQueue()
    : UxEspCppLibrary::FreeRtosQueue( 10,
                                      UxEspCppLibrary::FreeRtosQueueTask::minTargetQueueSize( sizeof( UcdPwmOutQueueTypes::message ) ),
                                      "UcdPwmOutQueue" )
{

}

/*!************************************************************************************************************************************************************
 *
 *************************************************************************************************************************************************************/

UcdPwmOutQueue::~UcdPwmOutQueue()
{
}

/*!************************************************************************************************************************************************************
 *
 *************************************************************************************************************************************************************/

BaseType_t UcdPwmOutQueue::sendCtrlUartCommand( const EkxProtocol::DriverId                  u8DriverId,
                                                const uint32_t                               u32MsgCounter,
                                                const uint8_t                                u8RepeatCounter,
                                                EkxProtocol::Payload::MessagePayload * const pMessagePayload )
{
    UcdPwmOutQueueTypes::message message;

    message.u32Type                                   = UcdPwmOutQueueTypes::messageType::CtrlUartCommand;
    message.payload.ctrlUartCommand.m_u8DriverId      = u8DriverId;
    message.payload.ctrlUartCommand.m_u32MsgCounter   = u32MsgCounter;
    message.payload.ctrlUartCommand.m_u8RepeatCounter = u8RepeatCounter;
    message.payload.ctrlUartCommand.m_pMessagePayload = pMessagePayload;

    return send( &message );
}

/*!************************************************************************************************************************************************************
 *
 *************************************************************************************************************************************************************/

BaseType_t UcdPwmOutQueue::sendAckNackReceived( const uint32_t u32MsgCounter,
                                                const bool     bSuccess )
{
    UcdPwmOutQueueTypes::message message;

    message.u32Type                                 = UcdPwmOutQueueTypes::messageType::AckNackReceived;
    message.payload.ackNackReceived.m_u32MsgCounter = u32MsgCounter;
    message.payload.ackNackReceived.m_bSuccess      = bSuccess;

    return send( &message );
}

/*!************************************************************************************************************************************************************
 *
 *************************************************************************************************************************************************************/
