///////////////////////////////////////////////////////////////////////////////
///
/// @file AcyclicNotification.cpp
///
/// @brief Implementation file of class AcyclicNotification
///
/// @author Ultratronik GmbH
///         Dornierstr. 9
///         D-82205 Gilching
///         Germany
///         http://www.ultratronik.de
///
/// @author written by Gerd Esser, Forschung & Entwicklung, gesser@ultratronik.de
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

#include "AcyclicNotification.h"
#include "NotificationCenter.h"

#include <QDebug>

///////////////////////////////////////////////////////////////////////////////
//
//
///////////////////////////////////////////////////////////////////////////////

AcyclicNotification::AcyclicNotification()
{
}

///////////////////////////////////////////////////////////////////////////////
//
//
///////////////////////////////////////////////////////////////////////////////

AcyclicNotification::~AcyclicNotification()
{
    m_pNotificationCenter = nullptr;
}

///////////////////////////////////////////////////////////////////////////////
//
//
///////////////////////////////////////////////////////////////////////////////

void AcyclicNotification::create( NotificationCenter * const                   pNotificationCenter,
                                  const EkxSqliteTypes::SqliteNotificationType nNotificationId )
{
    Q_ASSERT( pNotificationCenter );

    m_pNotificationCenter = pNotificationCenter;
    m_nNotificationId     = nNotificationId;

    if ( m_pNotificationCenter == nullptr )
    {
        qCritical() << "AcyclicNotification::create(): pNotificationCenter is null";
    }
}

///////////////////////////////////////////////////////////////////////////////
//
//
///////////////////////////////////////////////////////////////////////////////

bool AcyclicNotification::isActive() const
{
    return m_bActive;
}

///////////////////////////////////////////////////////////////////////////////
//
//
///////////////////////////////////////////////////////////////////////////////

void AcyclicNotification::activate()
{
    setActive( true );
}

///////////////////////////////////////////////////////////////////////////////
//
//
///////////////////////////////////////////////////////////////////////////////

void AcyclicNotification::deactivate()
{
    setActive( false );
}

///////////////////////////////////////////////////////////////////////////////
//
//
///////////////////////////////////////////////////////////////////////////////

void AcyclicNotification::setActive( const bool bActive )
{
    if ( m_bActive != bActive )
    {
        m_bActive = bActive;

        if ( m_bActive )
        {
            m_pNotificationCenter->raiseNotification( m_nNotificationId );
        }
        else
        {
            m_pNotificationCenter->removeNotification( m_nNotificationId );
        }
    }
}

///////////////////////////////////////////////////////////////////////////////
//
//
///////////////////////////////////////////////////////////////////////////////
