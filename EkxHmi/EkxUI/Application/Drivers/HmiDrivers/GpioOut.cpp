///////////////////////////////////////////////////////////////////////////////
///
/// @file GpioOut.cpp
///
/// @brief main application entry point of GpioOut.
///
/// @author Ultratronik GmbH
///         Dornierstr. 9
///         D-82205 Gilching
///         Germany
///         http://www.ultratronik.de
///
/// @author written by Gerd Esser, Forschung & Entwicklung, gesser@ultratronik.de
///
/// @date 20.09.2022
///
/// @copyright Copyright 2022 by Hemro International AG
///            Hemro International AG
///            Länggenstrasse 34
///            CH 8184 Bachenbülach
///            Switzerland
///            Homepage: www.hemrogroup.com
///
///////////////////////////////////////////////////////////////////////////////

#include "GpioOut.h"

namespace SystemIo
{

///////////////////////////////////////////////////////////////////////////////
//
//
///////////////////////////////////////////////////////////////////////////////

GpioOut::GpioOut( QObject * pParent )
    : SystemDeviceFile( pParent )
{
}

///////////////////////////////////////////////////////////////////////////////
//
//
///////////////////////////////////////////////////////////////////////////////

GpioOut::GpioOut( const QString & strSystemDeviceFile,
                  const bool      bInitLevel,
                  QObject *       pParent )
    : SystemDeviceFile( strSystemDeviceFile, pParent )
{
    if ( bInitLevel )
    {
        setHigh();
    }
    else
    {
        setLow();
    }
}

///////////////////////////////////////////////////////////////////////////////
//
//
///////////////////////////////////////////////////////////////////////////////

GpioOut::~GpioOut()
{
}

///////////////////////////////////////////////////////////////////////////////
//
//
///////////////////////////////////////////////////////////////////////////////

void GpioOut::setLow()
{
    m_bLevel = false;
    writeFile( "0" );
}

///////////////////////////////////////////////////////////////////////////////
//
//
///////////////////////////////////////////////////////////////////////////////

void GpioOut::setHigh()
{
    m_bLevel = true;
    writeFile( "1" );
}

///////////////////////////////////////////////////////////////////////////////
//
//
///////////////////////////////////////////////////////////////////////////////

bool GpioOut::level() const
{
    return m_bLevel;
}

///////////////////////////////////////////////////////////////////////////////
//
//
///////////////////////////////////////////////////////////////////////////////

bool GpioOut::isLow() const
{
    return m_bLevel == false;
}

///////////////////////////////////////////////////////////////////////////////
//
//
///////////////////////////////////////////////////////////////////////////////

bool GpioOut::isHigh() const
{
    return m_bLevel == true;
}

///////////////////////////////////////////////////////////////////////////////
//
//
///////////////////////////////////////////////////////////////////////////////

} // namespace SystemIo

