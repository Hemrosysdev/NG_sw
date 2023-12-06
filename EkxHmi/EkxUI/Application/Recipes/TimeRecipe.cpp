///////////////////////////////////////////////////////////////////////////////
///
/// @file TimeRecipe.cpp
///
/// @brief Implementation file of class TimeRecipe.
///
/// @author Ultratronik GmbH
///         Dornierstr. 9
///         D-82205 Gilching
///         Germany
///         http://www.ultratronik.de
///
/// @author written by Florian Sonntag, Forschung & Entwicklung, fsonntag@ultratronik.de
///
/// @date 31.03.2021
///
/// @copyright Copyright 2021 by Hemro International AG
///            Hemro International AG
///            Länggenstrasse 34
///            CH 8184 Bachenbülach
///            Switzerland
///            Homepage: www.hemrogroup.com
///
///////////////////////////////////////////////////////////////////////////////

#include "TimeRecipe.h"
#include "DddDriver.h"

///////////////////////////////////////////////////////////////////////////////
//
//
///////////////////////////////////////////////////////////////////////////////

TimeRecipe::TimeRecipe( bool      bPersisted,
                        QObject * parent )
    : QObject( parent )
    , m_bPersisted( bPersisted )
{
}

///////////////////////////////////////////////////////////////////////////////
//
//
///////////////////////////////////////////////////////////////////////////////

TimeRecipe::~TimeRecipe()
{
}

///////////////////////////////////////////////////////////////////////////////
//
//
///////////////////////////////////////////////////////////////////////////////

int TimeRecipe::recipeBigValue() const
{
    return m_nRecipeBigValue;
}

///////////////////////////////////////////////////////////////////////////////
//
//
///////////////////////////////////////////////////////////////////////////////

void TimeRecipe::setRecipeBigValue( const int nRecipeBigValue )
{
    if ( nRecipeBigValue != m_nRecipeBigValue )
    {
        m_nRecipeBigValue = nRecipeBigValue;

        emit recipeBigValueChanged();
    }
}

///////////////////////////////////////////////////////////////////////////////
//
//
///////////////////////////////////////////////////////////////////////////////

int TimeRecipe::recipeCommaValue() const
{
    return m_nRecipeCommaValue;
}

///////////////////////////////////////////////////////////////////////////////
//
//
///////////////////////////////////////////////////////////////////////////////

void TimeRecipe::setRecipeCommaValue( const int nRecipeCommaValue )
{
    if ( nRecipeCommaValue != m_nRecipeCommaValue )
    {
        m_nRecipeCommaValue = nRecipeCommaValue;

        emit recipeCommaValueChanged();
    }
}

///////////////////////////////////////////////////////////////////////////////
//
//
///////////////////////////////////////////////////////////////////////////////

void TimeRecipe::setGrindingSize( const int nGrindingSize )
{
    int nTempGrindingSize = std::min( MAX_HEMRO_SCALE, nGrindingSize );

    if ( m_nGrindingSize != nTempGrindingSize )
    {
        m_nGrindingSize = nTempGrindingSize;
        emit grindingSizeChanged();
    }
}

///////////////////////////////////////////////////////////////////////////////
//
//
///////////////////////////////////////////////////////////////////////////////

int TimeRecipe::grindingSize() const
{
    return m_nGrindingSize;
}

///////////////////////////////////////////////////////////////////////////////
//
//
///////////////////////////////////////////////////////////////////////////////

int TimeRecipe::portaFilterIndex() const
{
    return m_nPortaFilterIndex;
}

///////////////////////////////////////////////////////////////////////////////
//
//
///////////////////////////////////////////////////////////////////////////////

void TimeRecipe::setPortaFilterIndex( const int nPortaFilterIndex )
{
    if ( nPortaFilterIndex != m_nPortaFilterIndex )
    {
        m_nPortaFilterIndex = nPortaFilterIndex;

        emit portaFilterIndexChanged();
    }
}

///////////////////////////////////////////////////////////////////////////////
//
//
///////////////////////////////////////////////////////////////////////////////

void TimeRecipe::setRecipeIconOn( const bool bRecipeIconOn )
{
    if ( bRecipeIconOn != m_bRecipeIconOn )
    {
        m_bRecipeIconOn = bRecipeIconOn;

        emit recipeIconOnChanged();
    }
}

///////////////////////////////////////////////////////////////////////////////
//
//
///////////////////////////////////////////////////////////////////////////////

bool TimeRecipe::recipeIconOn() const
{
    return m_bRecipeIconOn;
}

///////////////////////////////////////////////////////////////////////////////
//
//
///////////////////////////////////////////////////////////////////////////////

void TimeRecipe::setShowCoarseness( const bool bShow )
{
    if ( m_bShowCoarseness != bShow )
    {
        m_bShowCoarseness = bShow;
        emit showCoarsenessChanged();
    }
}

///////////////////////////////////////////////////////////////////////////////
//
//
///////////////////////////////////////////////////////////////////////////////

bool TimeRecipe::showCoarseness() const
{
    return m_bShowCoarseness;
}

///////////////////////////////////////////////////////////////////////////////
//
//
///////////////////////////////////////////////////////////////////////////////

void TimeRecipe::setRecipeName( const QString & strRecipeName )
{
    if ( m_strRecipeName != strRecipeName )
    {
        m_strRecipeName = strRecipeName;
        Q_EMIT recipeNameChanged();
    }
}

///////////////////////////////////////////////////////////////////////////////
//
//
///////////////////////////////////////////////////////////////////////////////

QString TimeRecipe::recipeName() const
{
    return m_strRecipeName;
}

///////////////////////////////////////////////////////////////////////////////
//
//
///////////////////////////////////////////////////////////////////////////////

void TimeRecipe::setShowRecipeName( bool bShowRecipeName )
{
    if ( m_bShowRecipeName != bShowRecipeName )
    {
        m_bShowRecipeName = bShowRecipeName;
        Q_EMIT showRecipeNameChanged();
    }
}

///////////////////////////////////////////////////////////////////////////////
//
//
///////////////////////////////////////////////////////////////////////////////

bool TimeRecipe::showRecipeName() const
{
    return m_bShowRecipeName;
}

///////////////////////////////////////////////////////////////////////////////
//
//
///////////////////////////////////////////////////////////////////////////////

void TimeRecipe::setUuid( const QString & strUuid )
{
    if ( m_strUuid != strUuid )
    {
        m_strUuid = strUuid;
        emit uuidChanged();
    }
}

///////////////////////////////////////////////////////////////////////////////
//
//
///////////////////////////////////////////////////////////////////////////////

const QString & TimeRecipe::uuid() const
{
    return m_strUuid;
}

///////////////////////////////////////////////////////////////////////////////
//
//
///////////////////////////////////////////////////////////////////////////////

bool TimeRecipe::persisted() const
{
    return m_bPersisted;
}

///////////////////////////////////////////////////////////////////////////////
//
//
///////////////////////////////////////////////////////////////////////////////

void TimeRecipe::setPersisted( bool bPersisted )
{
    if ( m_bPersisted != bPersisted )
    {
        m_bPersisted = bPersisted;
        Q_EMIT persistedChanged();
    }
}

///////////////////////////////////////////////////////////////////////////////
//
//
///////////////////////////////////////////////////////////////////////////////