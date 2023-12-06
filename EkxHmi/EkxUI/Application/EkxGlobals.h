///////////////////////////////////////////////////////////////////////////////
///
/// @file EkxGlobals.h
///
/// @brief Header file of global application values.
///
/// @author Ultratronik GmbH
///         Dornierstr. 9
///         D-82205 Gilching
///         Germany
///         http://www.ultratronik.de
///
/// @author written by Gerd Esser, Forschung & Entwicklung, gesser@ultratronik.de
///
/// @date 10.02.2021
///
/// @copyright Copyright 2021 by Hemro International AG
///            Hemro International AG
///            Länggenstrasse 34
///            CH 8184 Bachenbülach
///            Switzerland
///            Homepage: www.hemrogroup.com
///
///////////////////////////////////////////////////////////////////////////////

#ifndef EkxGlobals_h
#define EkxGlobals_h

#include <qglobal.h>

///////////////////////////////////////////////////////////////////////////////
//
//
///////////////////////////////////////////////////////////////////////////////

#ifndef QT_ENDL
#if QT_VERSION >= QT_VERSION_CHECK( 5, 13, 0 )
#define QT_ENDL Qt::endl
#else
#define QT_ENDL endl
#endif
#endif

///////////////////////////////////////////////////////////////////////////////
//
//
///////////////////////////////////////////////////////////////////////////////

#endif // EkxGlobals_h