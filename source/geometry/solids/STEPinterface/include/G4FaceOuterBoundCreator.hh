// This code implementation is the intellectual property of
// the GEANT4 collaboration.
//
// By copying, distributing or modifying the Program (or any work
// based on the Program) you indicate your acceptance of this statement,
// and all its terms.
//
// $Id: G4FaceOuterBoundCreator.hh,v 1.3 2000/11/09 16:35:45 gcosmo Exp $
// GEANT4 tag $Name: geant4-03-01 $
//
// ----------------------------------------------------------------------
// Class G4FaceOuterBoundCreator
//
// Class description:
//
//

// Authors: J.Sulkimo, P.Urban.
// Revisions by: L.Broglia, G.Cosmo.
//
// History:
//   18-Nov-1999: First step of re-engineering - G.Cosmo
// ----------------------------------------------------------------------
#ifndef G4FACEOUTERBOUNDCREATOR_HH
#define G4FACEOUTERBOUNDCREATOR_HH

#include "G4FaceBoundCreator.hh"

class G4FaceOuterBoundCreator: public G4FaceBoundCreator
{
  public:

  // Constructor & destructor

    G4FaceOuterBoundCreator();
    ~G4FaceOuterBoundCreator();

  // Member functions

  void CreateSTEPGeometry(void* G4obj);
  const char* Name() const { return "Face_Outer_Bound"; }
  static G4FaceOuterBoundCreator GetInstance() { return csc; }

  // Members

  private:

    static G4FaceOuterBoundCreator csc;
};

#endif
