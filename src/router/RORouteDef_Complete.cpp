//---------------------------------------------------------------------------//
//                        RORouteDef_Complete.cpp -
//  A complete route definition (with all passed edges being known)
//                           -------------------
//  project              : SUMO - Simulation of Urban MObility
//  begin                : Sept 2002
//  copyright            : (C) 2002 by Daniel Krajzewicz
//  organisation         : IVF/DLR http://ivf.dlr.de
//  email                : Daniel.Krajzewicz@dlr.de
//---------------------------------------------------------------------------//

//---------------------------------------------------------------------------//
//
//   This program is free software; you can redistribute it and/or modify
//   it under the terms of the GNU General Public License as published by
//   the Free Software Foundation; either version 2 of the License, or
//   (at your option) any later version.
//
//---------------------------------------------------------------------------//
namespace
{
    const char rcsid[] =
    "$Id$";
}
// $Log$
// Revision 1.12  2006/11/16 10:50:51  dkrajzew
// warnings removed
//
// Revision 1.11  2006/11/14 06:48:58  dkrajzew
// readapting changes in the router-API
//
// Revision 1.10  2006/01/26 08:44:14  dkrajzew
// adapted the new router API
//
// Revision 1.9  2006/01/24 13:43:53  dkrajzew
// added vehicle classes to the routing modules
//
// Revision 1.8  2006/01/09 12:00:59  dkrajzew
// debugging vehicle color usage
//
// Revision 1.7  2005/10/07 11:42:15  dkrajzew
// THIRD LARGE CODE RECHECK: patched problems on Linux/Windows configs
//
// Revision 1.6  2005/09/15 12:05:11  dkrajzew
// LARGE CODE RECHECK
//
// Revision 1.5  2005/05/04 08:53:07  dkrajzew
// level 3 warnings removed; a certain SUMOTime time description added
//
// Revision 1.4  2004/12/16 12:26:52  dkrajzew
// debugging
//
// Revision 1.3  2004/11/23 10:25:52  dkrajzew
// debugging
//
// Revision 1.2  2004/07/02 09:39:41  dkrajzew
// debugging while working on INVENT; preparation of classes to be derived for an online-routing
//
// Revision 1.1  2004/01/26 08:02:27  dkrajzew
// loaders and route-def types are now renamed in an senseful way; further changes in order to make both new routers work; documentation added
//
// ------------------------------------------------
// Revision 1.7  2003/11/11 08:04:45  dkrajzew
// avoiding emissions of vehicles on too short edges
//
// Revision 1.6  2003/07/30 09:26:33  dkrajzew
// all vehicles, routes and vehicle types may now have specific colors
//
// Revision 1.5  2003/06/18 11:36:50  dkrajzew
// a new interface which allows to choose whether to stop after a route could
//  not be computed or not; not very sphisticated, in fact
//
// Revision 1.4  2003/03/20 17:40:58  dkrajzew
// StringUtils moved from utils/importio to utils/common
//
// Revision 1.3  2003/02/07 10:45:04  dkrajzew
// updated
//
/* =========================================================================
 * compiler pragmas
 * ======================================================================= */
#pragma warning(disable: 4786)


/* =========================================================================
 * included modules
 * ======================================================================= */
#ifdef HAVE_CONFIG_H
#ifdef WIN32
#include <windows_config.h>
#else
#include <config.h>
#endif
#endif // HAVE_CONFIG_H

#include <string>
#include <deque>
#include "ROEdgeVector.h"
#include "ROEdge.h"
#include "RORouteDef.h"
#include "RORoute.h"
#include "ROAbstractRouter.h"
#include "RORouteDef_Complete.h"

#ifdef _DEBUG
#include <utils/dev/debug_new.h>
#endif // _DEBUG


/* =========================================================================
 * using namespaces
 * ======================================================================= */
using namespace std;


/* =========================================================================
 * method definitions
 * ======================================================================= */
RORouteDef_Complete::RORouteDef_Complete(const std::string &id,
                                         const RGBColor &color,
                                         const ROEdgeVector &edges)
    : RORouteDef(id, color), _edges(edges)
{
}


RORouteDef_Complete::~RORouteDef_Complete()
{
}


const ROEdge * const
RORouteDef_Complete::getFrom() const
{
    return _edges.getFirst();
}


const ROEdge * const
RORouteDef_Complete::getTo() const
{
    return _edges.getLast();
}


RORoute *
RORouteDef_Complete::buildCurrentRoute(ROAbstractRouter &,
		SUMOTime , ROVehicle &) const
{
    return new RORoute(_id, 0, 1, _edges);
}


void
RORouteDef_Complete::addAlternative(const ROVehicle *const, RORoute *current, SUMOTime begin)
{
    _startTime = begin;
    delete current;
}


RORouteDef *
RORouteDef_Complete::copy(const std::string &id) const
{
    return new RORouteDef_Complete(id, myColor, _edges);
}


const ROEdgeVector &
RORouteDef_Complete::getCurrentEdgeVector() const
{
    return _edges;
}


/**************** DO NOT DEFINE ANYTHING AFTER THE INCLUDE *****************/

// Local Variables:
// mode:C++
// End:


