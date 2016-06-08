// This code implementation is the intellectual property of
// the GEANT4 collaboration.
//
// By copying, distributing or modifying the Program (or any work
// based on the Program) you indicate your acceptance of this statement,
// and all its terms.
//
// $Id: G4GeometryManager.hh,v 1.3 2000/04/20 16:49:46 gcosmo Exp $
// GEANT4 tag $Name: geant4-03-01 $
//
// class G4GeometryManager
//
// Class description:
//
// A class responsible for high level geometrical functions, and for
// high level objects in the geometry subdomain.
// The class is a `singleton', with access via the static method
// G4GeometryManager::GetInstance().
//
// Member data:
//
//   static G4GeometryManager* fgInstance
//     - Ptr to the unique instance of class

// History:
// 26.07.95 P.Kent Initial version, incuding optimisation Build

#ifndef G4GEOMETRYMANAGER_HH
#define G4GEOMETRYMANAGER_HH

#include "globals.hh"

// Needed for building optimisations
#include "geomdefs.hh"
#include "G4LogicalVolumeStore.hh"
#include "G4LogicalVolume.hh"
#include "G4SmartVoxelHeader.hh"
#ifdef  G4GEOMETRY_VOXELDEBUG
#include "G4ios.hh"
#endif

class G4GeometryManager
{
  public: // with description
  
    G4bool CloseGeometry(G4bool pOptimise=true);
      // Close (`lock') the geometry: perform sanity and `completion' checks
      // and optionally [default=yes] build optimisation information.
    
    void OpenGeometry();
      // Open (`unlock') the geometry and remove optimisation information if
      // present.

    static G4GeometryManager* GetInstance();
      // Return ptr to singleton instance of the class.

  protected:

    G4GeometryManager();

  private:

    void BuildOptimisations(const G4bool allOpt);
    void DeleteOptimisations();

    static G4GeometryManager* fgInstance;
    G4bool fIsClosed;
};

#endif
