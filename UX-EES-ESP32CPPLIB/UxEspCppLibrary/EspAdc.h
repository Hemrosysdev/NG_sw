/*
 * EspAdc.h
 *
 *  Created on: 06.11.2019
 *      Author: gesser
 */

#ifndef UXESPCPPLIBRARY_ESPADC_H
#define UXESPCPPLIBRARY_ESPADC_H

/*!************************************************************************************************************************************************************
 *
 *************************************************************************************************************************************************************/

#include "EspLog.h"
#include <driver/adc.h>
#include <esp_adc_cal.h>

/*!************************************************************************************************************************************************************
 *
 *************************************************************************************************************************************************************/

namespace UxEspCppLibrary
{

/*!************************************************************************************************************************************************************
 *
 *************************************************************************************************************************************************************/

class EspAdc : public EspLog
{
public:

    EspAdc();
    EspAdc( const std::string & strLogName );

    virtual ~EspAdc();

    esp_err_t  init( const adc_unit_t        nUnit,
                     const adc_channel_t     nChannel,
                     const adc_atten_t       nAtten,
                     const adc_bits_width_t  nBitsWidth,
                     const uint32_t          u32Vref = 0 );    // if voltage reading is used

    uint32_t readRaw( void );

    uint32_t readVoltage( void );

private:

    adc_unit_t m_nUnit;

    adc_channel_t m_nChannel;

    adc_atten_t m_nAtten;

    adc_bits_width_t  m_nBitsWidth;

    uint32_t          m_u32Vref;

    esp_adc_cal_characteristics_t   m_adcCalCharacteristics;

};

/*!************************************************************************************************************************************************************
 *
 *************************************************************************************************************************************************************/

} // namespace UxEspCppLibrary

#endif /* UXESPCPPLIBRARY_ESPADC_H */
