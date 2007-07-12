/****************************************************************************/
/// @file    Named.h
/// @author  Daniel Krajzewicz
/// @date    Sept 2002
/// @version $Id$
///
// An object that has a name
/****************************************************************************/
// SUMO, Simulation of Urban MObility; see http://sumo.sourceforge.net/
// copyright : (C) 2001-2007
//  by DLR (http://www.dlr.de/) and ZAIK (http://www.zaik.uni-koeln.de/AFS)
/****************************************************************************/
//
//   This program is free software; you can redistribute it and/or modify
//   it under the terms of the GNU General Public License as published by
//   the Free Software Foundation; either version 2 of the License, or
//   (at your option) any later version.
//
/****************************************************************************/
#ifndef Named_h
#define Named_h


// ===========================================================================
// included modules
// ===========================================================================
#ifdef _MSC_VER
#include <windows_config.h>
#else
#include <config.h>
#endif

#include <string>


// ===========================================================================
// class definitions
// ===========================================================================
/**
 * @class Named
 * The base class for objects which do have a name (an id).
 */
class Named
{
public:
    /// Constructor
    Named(const std::string &id) : myId(id)
    { }

    /// Destructor
    virtual ~Named()
    { }

    /// Returns the name
    const std::string &getID() const
    {
        return myId;
    }

protected:
    /// The name of the object
    std::string myId;

};


#endif

/****************************************************************************/

