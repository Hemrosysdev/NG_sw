/*
 * EspLedc.h
 *
 *  Created on: 05.11.2019
 *      Author: gesser
 */

/*!************************************************************************************************************************************************************
 *
 *************************************************************************************************************************************************************/

#ifndef UXESPCPPLIBRARY_ESPLEDCCHANNEL_H
#define UXESPCPPLIBRARY_ESPLEDCCHANNEL_H

/*!************************************************************************************************************************************************************
 *
 *************************************************************************************************************************************************************/

#include "EspLog.h"
#include <driver/ledc.h>
#include <driver/gpio.h>

/*!************************************************************************************************************************************************************
 *
 *************************************************************************************************************************************************************/

namespace UxEspCppLibrary
{

class EspLedcTimer;

/*!************************************************************************************************************************************************************
 *
 *************************************************************************************************************************************************************/

class EspLedcChannel : public EspLog
{
public:

    EspLedcChannel();
    EspLedcChannel( const std::string & strLogName );

    virtual ~EspLedcChannel();

    esp_err_t init( const ledc_channel_t nLedcChannel,
                    const gpio_num_t     nGpioNum,
                    EspLedcTimer *       pLedcTimer );

    ledc_channel_t channel( void ) const;

    gpio_num_t gpioNum( void ) const;

    EspLedcTimer * ledcTimer( void ) const;

    esp_err_t setDuty( const uint32_t u32Duty );

    uint32_t duty( void ) const;

private:

    ledc_channel_t m_nLedcChannel { LEDC_CHANNEL_MAX };

    gpio_num_t     m_nGpioNum { GPIO_NUM_MAX };

    EspLedcTimer * m_pLedcTimer { nullptr };

    uint32_t       m_u32Duty { 0 };

};

/*!************************************************************************************************************************************************************
 *
 *************************************************************************************************************************************************************/

} // namespace UxEspCppLibrary

#endif /* UXESPCPPLIBRARY_ESPLEDCCHANNEL_H */
