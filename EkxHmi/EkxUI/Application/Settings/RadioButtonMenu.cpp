///////////////////////////////////////////////////////////////////////////////
///
/// @file RadioButtonMenu.cpp
///
/// @brief Implementation file of class RadioButtonMenu
///
/// @author Ultratronik GmbH
///         Dornierstr. 9
///         D-82205 Gilching
///         Germany
///         http://www.ultratronik.de
///
/// @author written by Xaver Pilz, Forschung & Entwicklung, xpilz@ultratronik.de
///
/// @date 25.01.2021
///
/// @copyright Copyright 2021 by Hemro International AG
///            Hemro International AG
///            Länggenstrasse 34
///            CH 8184 Bachenbülach
///            Switzerland
///            Homepage: www.hemrogroup.com
///
///////////////////////////////////////////////////////////////////////////////

#include "RadioButtonMenu.h"

///////////////////////////////////////////////////////////////////////////////
//
//
///////////////////////////////////////////////////////////////////////////////

RadioButtonMenu::RadioButtonMenu( QObject * parent ) : QObject( parent )
{

}

///////////////////////////////////////////////////////////////////////////////
//
//
///////////////////////////////////////////////////////////////////////////////

int RadioButtonMenu::selectedIndex()
{
    return m_selectedIndex;
}

///////////////////////////////////////////////////////////////////////////////
//
//
///////////////////////////////////////////////////////////////////////////////

void RadioButtonMenu::setSelectedIndex( int index )
{
    if ( m_selectedIndex != index )
    {
        m_selectedIndex = index;
        emit selectedIndexChanged();
    }
}

///////////////////////////////////////////////////////////////////////////////
//
//
///////////////////////////////////////////////////////////////////////////////

QQmlListProperty<RadioButtonMenuItem> RadioButtonMenu::qlpMenuItems()
{
    return QQmlListProperty<RadioButtonMenuItem>( this, this, &cb_menuItemsCount, &cb_menuItemsAt );
}

///////////////////////////////////////////////////////////////////////////////
//
//
///////////////////////////////////////////////////////////////////////////////

// static functions:

int RadioButtonMenu::cb_menuItemsCount( QQmlListProperty<RadioButtonMenuItem> * qlp )
{
    RadioButtonMenu * radioButtonMenu = reinterpret_cast<RadioButtonMenu *>( qlp->data );
    return radioButtonMenu->menuItems.count();
}

///////////////////////////////////////////////////////////////////////////////
//
//
///////////////////////////////////////////////////////////////////////////////

RadioButtonMenuItem * RadioButtonMenu::cb_menuItemsAt( QQmlListProperty<RadioButtonMenuItem> * qlp,
                                                       int                                     index )
{
    RadioButtonMenu * radioButtonMenu = reinterpret_cast<RadioButtonMenu *>( qlp->data );
    return radioButtonMenu->menuItems.at( index );
}

///////////////////////////////////////////////////////////////////////////////
//
//
///////////////////////////////////////////////////////////////////////////////

