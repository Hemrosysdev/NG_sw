///////////////////////////////////////////////////////////////////////////////
///
/// @file EkxSqlSchemata.h
///
/// @brief Header file of namespace EkxSqlSchemata.
///
/// @author Ultratronik GmbH
///         Dornierstr. 9
///         D-82205 Gilching
///         Germany
///         http://www.ultratronik.de
///
/// @author written by Gerd Esser, Forschung & Entwicklung, gesser@ultratronik.de
///
/// @date 01.04.2021
///
/// @copyright Copyright 2021 by Hemro International AG
///            Hemro International AG
///            Länggenstrasse 34
///            CH 8184 Bachenbülach
///            Switzerland
///            Homepage: www.hemrogroup.com
///
///////////////////////////////////////////////////////////////////////////////


#ifndef EkxSqlSchemata_h
#define EkxSqlSchemata_h

///////////////////////////////////////////////////////////////////////////////
//
//
///////////////////////////////////////////////////////////////////////////////

#include <QString>

///////////////////////////////////////////////////////////////////////////////
//
//
///////////////////////////////////////////////////////////////////////////////

namespace EkxSqlSchemata
{

const QString strEkxSqliteMaster =
#include "EkxSqliteMaster.sql.inc"
;

} // namespace EkxSqlSchemata

///////////////////////////////////////////////////////////////////////////////
//
//
///////////////////////////////////////////////////////////////////////////////

#endif // EkxSqlSchemata_h