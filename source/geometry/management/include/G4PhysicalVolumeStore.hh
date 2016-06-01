// This code implementation is the intellectual property of
// the RD44 GEANT4 collaboration.
//
// By copying, distributing or modifying the Program (or any work
// based on the Program) you indicate your acceptance of this statement,
// and all its terms.
//
// $Id: G4PhysicalVolumeStore.hh,v 2.0 1998/07/02 16:57:02 gunter Exp $
// GEANT4 tag $Name: geant4-00 $
//
// class G4PhysicalVolume
//
// Container for all solids, with functionality derived from
// RWTPtrOrderedVector<T>. The class is `singleton', in that only
// one can exist, and access is facillitated via
// G4PhysicalVolumeStore::GetInstance()
//
// All solids should be registered with G4PhysicalVolumeStore, and removed on
// their destruction. Intended principally for UI browser. The underlying
// container initially has a capacity of 100.
//
// If much additional functionality is added, should consider containment
// instead of inheritance for RWTPtrOrderedVector<T>
//
// Class member functions:
//
// static void Register(G4VPhysicalVolume* pVolume)
//   Add the volume to the collection
// static void DeRegister(G4VPhysicalVolume* pVolume)
//   Remove the volume from the collection
// static G4PhysicalVolumeStore* GetInstance()
//   Get a ptr to the unique G4PhysicalVolumeStore, creating it if necessary
//
// Member functions:
//
// [as per RWTPtrOrderedvector]
//
// NOTE: Constructor is protected - creation and subsequent access is via
//       GetInstance
//
// Member data:
//
// static G4PhysicalVolumeStore*
//   Ptr to the single G4PhysicalVolumeStore
//
// History:
// 25.07.95 P.Kent Initial version

#ifndef G4PHYSICALVOLUMESTORE_HH
#define G4PHYSICALVOLUMESTORE_HH

#include <rw/tpordvec.h>

#include "G4VPhysicalVolume.hh"

class G4PhysicalVolumeStore : public RWTPtrOrderedVector<G4VPhysicalVolume>
{
  public:
    static void Register(G4VPhysicalVolume* pSolid);
    static void DeRegister(G4VPhysicalVolume* pSolid);
    static G4PhysicalVolumeStore* GetInstance();
    virtual ~G4PhysicalVolumeStore();
  protected:
    G4PhysicalVolumeStore();
  private:
    static G4PhysicalVolumeStore* fgInstance;
};

#endif






