///////////////////////////////////////////////////////////////////////////////
///
/// @file DiskUsageTime.cpp
///
/// @brief Implementation file of class DiskUsageTime
///
/// @author Ultratronik GmbH
///         Dornierstr. 9
///         D-82205 Gilching
///         Germany
///         http://www.ultratronik.de
///
/// @date 09.09.2022
///
/// @copyright Copyright 2022 by Hemro International AG
///            Hemro International AG
///            Länggenstrasse 34
///            CH 8184 Bachenbülach
///            Switzerland
///            Homepage: www.hemrogroup.com
///
///////////////////////////////////////////////////////////////////////////////

#include "DiskUsageTime.h"

#include "EkxGlobals.h"
#include "SqliteInterface.h"

///////////////////////////////////////////////////////////////////////////////
//
//
///////////////////////////////////////////////////////////////////////////////

DiskUsageTime::DiskUsageTime( QObject * parent )
    : QObject( parent )
{
}

///////////////////////////////////////////////////////////////////////////////
//
//
///////////////////////////////////////////////////////////////////////////////

DiskUsageTime::~DiskUsageTime()
{
    m_pSqliteInterface = nullptr;
}

///////////////////////////////////////////////////////////////////////////////
//
//
///////////////////////////////////////////////////////////////////////////////

void DiskUsageTime::create( SqliteInterface * pSqliteInterface )
{
    m_pSqliteInterface = pSqliteInterface;
}

///////////////////////////////////////////////////////////////////////////////
//
//
///////////////////////////////////////////////////////////////////////////////

int DiskUsageTime::readDiscUsageTimeX100Secs() const
{
    int     result = -1;
    quint32 temp;

    if ( m_pSqliteInterface->queryCounter( EkxSqliteTypes::SqliteCounter_DISC_USAGE_TIME, temp ) )
    {
        result = temp;
    }

    return result;
}

///////////////////////////////////////////////////////////////////////////////
//
//
///////////////////////////////////////////////////////////////////////////////

void DiskUsageTime::reset()
{
    m_pSqliteInterface->resetCounter( EkxSqliteTypes::SqliteCounter_DISC_USAGE_TIME );
    m_pSqliteInterface->addEvent( EkxSqliteTypes::SqliteEventTypes::SqliteEventType_DISC_USAGE_TIME_RESET, "" );
}

///////////////////////////////////////////////////////////////////////////////
//
//
///////////////////////////////////////////////////////////////////////////////

int DiskUsageTime::maxDiscUsageTimeHours() const
{
    return m_nMaxDiscUsageTimeHours;
}

///////////////////////////////////////////////////////////////////////////////
//
//
///////////////////////////////////////////////////////////////////////////////

bool DiskUsageTime::isWarningActive() const
{
    bool bActive = false;

    if ( maxDiscUsageTimeHours() <= ( readDiscUsageTimeX100Secs() / 100 / 3600 ) )
    {
        bActive = true;
    }

    return bActive;
}

///////////////////////////////////////////////////////////////////////////////
//
//
///////////////////////////////////////////////////////////////////////////////

bool DiskUsageTime::isPreWarningActive() const
{
    bool bActive = false;

    if ( static_cast<int>( maxDiscUsageTimeHours() * 0.8 ) <= ( readDiscUsageTimeX100Secs() / 100 / 3600 ) )
    {
        bActive = true;
    }

    return bActive;
}

///////////////////////////////////////////////////////////////////////////////
//
//
///////////////////////////////////////////////////////////////////////////////

void DiskUsageTime::setMaxDiscUsageTimeHours( const int nMaxHours )
{
    if ( nMaxHours > 0 )
    {
        if ( m_nMaxDiscUsageTimeHours != nMaxHours )
        {
            m_nMaxDiscUsageTimeHours = nMaxHours;
            emit maxDiscUsageTimeHoursChanged();
        }
    }
}

///////////////////////////////////////////////////////////////////////////////
//
//
///////////////////////////////////////////////////////////////////////////////