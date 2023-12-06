///////////////////////////////////////////////////////////////////////////////
///
/// @file UpppLevel3Msg.cpp
///
/// @brief Implementation file of class UpppLevel3Msg.
///
/// @author Ultratronik GmbH \n
///         Dornierstr. 9 \n
///         D-82205 Gilching \n
///         Germany
///         http://www.ultratronik.de
///
/// @author written by Gerd Esser, Forschung & Entwicklung, gesser@ultratronik.de
///
/// @date 17.08.2020
///
/// @copyright Copyright 2020 by Hemro International AG \n
///            Hemro International AG \n
///            Länggenstrasse 34 \n
///            CH 8184 Bachenbülach \n
///            Switzerland \n
///            Homepage: www.hemrogroup.com
///
///////////////////////////////////////////////////////////////////////////////

#include "UpppLevel3Msg.h"

///////////////////////////////////////////////////////////////////////////////
//
//
///////////////////////////////////////////////////////////////////////////////

UpppLevel3Msg::UpppLevel3Msg( QObject * parent )
    : UpppCoreMsg( parent )
{

}

///////////////////////////////////////////////////////////////////////////////
//
//
///////////////////////////////////////////////////////////////////////////////

UpppLevel3Msg::UpppLevel3Msg( const UpppLevel3Msg & theRight )
    : UpppCoreMsg( theRight.parent() )
{
    *this = theRight;
}

///////////////////////////////////////////////////////////////////////////////
//
//
///////////////////////////////////////////////////////////////////////////////

UpppLevel3Msg::~UpppLevel3Msg()
{

}

///////////////////////////////////////////////////////////////////////////////
//
//
///////////////////////////////////////////////////////////////////////////////

UpppLevel3Msg & UpppLevel3Msg::operator=( const UpppLevel3Msg & theRight )
{
    if ( this != &theRight )
    {
        UpppCoreMsg::operator=( theRight );

        m_nTimeout    = theRight.m_nTimeout;
        m_bRepeatSend = theRight.m_bRepeatSend;
        m_nRetryCnt   = theRight.m_nRetryCnt;
    }

    return *this;
}

///////////////////////////////////////////////////////////////////////////////
//
//
///////////////////////////////////////////////////////////////////////////////

int UpppLevel3Msg::timeout() const
{
    return m_nTimeout;
}

///////////////////////////////////////////////////////////////////////////////
//
//
///////////////////////////////////////////////////////////////////////////////

void UpppLevel3Msg::setTimeout( const int nTimeout )
{
    m_nTimeout = nTimeout;
}

///////////////////////////////////////////////////////////////////////////////
//
//
///////////////////////////////////////////////////////////////////////////////

bool UpppLevel3Msg::repeatSend() const
{
    return m_bRepeatSend;
}

///////////////////////////////////////////////////////////////////////////////
//
//
///////////////////////////////////////////////////////////////////////////////

void UpppLevel3Msg::setRepeatSend( const bool bRepeat )
{
    m_bRepeatSend = bRepeat;
}

///////////////////////////////////////////////////////////////////////////////
//
//
///////////////////////////////////////////////////////////////////////////////

int UpppLevel3Msg::retryCnt() const
{
    return m_nRetryCnt;
}

///////////////////////////////////////////////////////////////////////////////
//
//
///////////////////////////////////////////////////////////////////////////////

void UpppLevel3Msg::setRetryCnt( const int nRetryCnt )
{
    m_nRetryCnt = nRetryCnt;
}

///////////////////////////////////////////////////////////////////////////////
//
//
///////////////////////////////////////////////////////////////////////////////

void UpppLevel3Msg::incRetryCnt()
{
    m_nRetryCnt++;
}

///////////////////////////////////////////////////////////////////////////////
//
//
///////////////////////////////////////////////////////////////////////////////
