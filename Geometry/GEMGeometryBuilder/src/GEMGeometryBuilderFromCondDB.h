#ifndef Geometry_GEMGeometry_GEMGeometryBuilderFromCondDB_H
#define Geometry_GEMGeometry_GEMGeometryBuilderFromCondDB_H

/** \class  GEMGeometryBuilderFromCondDB
 *  Build the GEMGeometry from the RecoIdealGeometry description stored in Condition DB 
 *
 *  \author M. Maggi - INFN Bari
 *
 */

#include "CondFormats/GeometryObjects/interface/RecoIdealGeometry.h"
#include <map>
#include <list>

class GEMGeometry;
class GEMDetId;
class GEMEtaPartition;

class GEMGeometryBuilderFromCondDB 
{
 public:

  GEMGeometryBuilderFromCondDB();

  ~GEMGeometryBuilderFromCondDB();
  
  void build(const std::shared_ptr<GEMGeometry>& theGeometry,
	     const RecoIdealGeometry& rgeo );
  
 private:

  std::map<GEMDetId, std::list<GEMEtaPartition *> > m_chids;
};

#endif
