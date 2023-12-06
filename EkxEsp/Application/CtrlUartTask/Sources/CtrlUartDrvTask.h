/*!*****************************************************************************
*
* @file CtrlUartDrvTask.h
*
* @brief Header file for class CtrlUartDrvTask.
*
* @author Ultratronik GmbH
*         Dornierstr. 9
*         D-82205 Gilching
*         www.ultratronik.de
*
* @author Gerd Esser, Forschung & Entwicklung
*
* @created 28.11.2022
*
* @copyright Copyright 2022 by Hemro International AG
*             Hemro International AG
*             Länggenstrasse 34
*             CH 8184 Bachenbülach
*             Switzerland
*             Homepage: www.hemrogroup.com
*
*******************************************************************************/

#ifndef CtrlUartDrvTask_h
#define CtrlUartDrvTask_h

/*##***********************************************************************************************************************************************************
 *  Includes
 *************************************************************************************************************************************************************/

#include "FreeRtosTask.h"
#include <freertos/queue.h>
#include <driver/uart.h>
#include "EkxProtocol.h"

/*!************************************************************************************************************************************************************
 *
 *************************************************************************************************************************************************************/

namespace CtrlUart
{
class CtrlUartTask;

/*!*****************************************************************************************************************************************
 * @brief This task is used by CtrlUartTask. It handles uart communication.
 ******************************************************************************************************************************************/

class CtrlUartDrvTask : public UxEspCppLibrary::FreeRtosTask
{

private:

    static const int                   c_nCtrlUartRxBufSize    { 4000 }; //< should be greater than UART_FIFO_LEN
    static const int                   c_nCtrlUartTxBufSize    { 0 };    //< should be greater or equal UART_FIFO_LEN
    static const int                   c_nCtrlUartBaudRate     { 921600 };
    static const uart_hw_flowcontrol_t c_nCtrlUartFlowCtrl     { UART_HW_FLOWCTRL_DISABLE };
    static const int                   c_nCtrlUartFlowCtrlTh   { 0 };
    static const int                   c_nUartTxBufThreshold   { ( c_nCtrlUartTxBufSize / 2 ) };
    static const int                   c_nCtrlUartQueueSize    { 100 };
    static const int                   c_nMessageTimeout5Ms    { 5 };
    static const int                   c_nMessageTimeout10Ms   { 10 };
    static const int                   c_nMessageTimeout100Ms  { 100 };
    static const int                   c_nMaxWaitTxDoneTicks   { 100 };

public:

    /*!*****************************************************************************************************************************************
     * @brief Constructor
     *
     * @param [in] parent task
     ******************************************************************************************************************************************/
    explicit CtrlUartDrvTask( CtrlUartTask * const pUartTask );

    /*!*****************************************************************************************************************************************
     * @brief Destructor
     ******************************************************************************************************************************************/
    ~CtrlUartDrvTask() override;

    /*!*****************************************************************************************************************************************
     * @brief install FreeRtos uart driver with given configuration
     ******************************************************************************************************************************************/
    esp_err_t setupUartDriver( const uart_config_t * const pUartConfig );

    /*!*****************************************************************************************************************************************
     * @brief install default FreeRtos uart driver
     ******************************************************************************************************************************************/
    esp_err_t init();

    /*!*****************************************************************************************************************************************
     * @brief Getter for the queue of the task
     *
     * @return the queue
     ******************************************************************************************************************************************/
    QueueHandle_t uartQueue();

    /*!*****************************************************************************************************************************************
     * @brief Send raw data to the uart
     *
     * @return     error status
     ******************************************************************************************************************************************/
    esp_err_t writeData( const uint8_t * const pData,
                         const size_t          u32DataSize );

    esp_err_t writeData( const std::string & strData );

private:

    ////////////////////////////////////////
    // private methods
    ////////////////////////////////////////

    /*!*****************************************************************************************************************************************
     * @brief Constructor without parameter is not available
     ******************************************************************************************************************************************/
    CtrlUartDrvTask() = delete;

    /*!*****************************************************************************************************************************************
     * @brief receive uart events from the FreeRtos driver
     ******************************************************************************************************************************************/
    void execute() override;

    /*!*****************************************************************************************************************************************
     * @brief process the uart events from the FreeRtos driver
     ******************************************************************************************************************************************/
    bool processUartEvent( const uart_event_t & uartEvent );

    /*!*****************************************************************************************************************************************
     * @brief clears and flushes uart input queue
     ******************************************************************************************************************************************/
    void clearUartBuffer();

    /*!*****************************************************************************************************************************************
     * @brief unwrap uart frame from CPS transport layer
     ******************************************************************************************************************************************/
    void processTimedOutData();

    ////////////////////////////////////////
    // private member variables
    ////////////////////////////////////////

    CtrlUartTask *              m_pUartTask { nullptr };

    int                         m_nUartNum { -1 };

    QueueHandle_t               m_hUartQueue { nullptr };

    size_t                      m_u32AssumedUartTxBufferPos { 0 };

    EkxProtocol::Deserializer * m_pDeserializer = nullptr;

    EkxProtocol::MessageFrame   m_receiveMessageFrame;

};

/*!************************************************************************************************************************************************************
 *
 *************************************************************************************************************************************************************/

} /* namespace CtrlUart */

#endif /* CtrlUartDrvTask_h */