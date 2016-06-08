// This code implementation is the intellectual property of
// the GEANT4 collaboration.
//
// By copying, distributing or modifying the Program (or any work
// based on the Program) you indicate your acceptance of this statement,
// and all its terms.
//
// $Id: MyVisManager.hh,v 1.4 1999/12/15 14:54:23 gunter Exp $
// GEANT4 tag $Name: geant4-03-01 $
//
// 
// John Allison 24th January 1998.
//
// Class description
//
// Example Visualization Manager implementing virtual function
//   RegisterGraphicsSystems.  Exploits C-pre-processor variables
//   G4VIS_USE_DAWN, etc., which are set by the GNUmakefiles if
//   environment variables of the same name are set.
//
// So all you have to do is set environment variables and compile and
//   instantiate this in your main().
//
// Alternatively, you can implement an empty function here and just
//   register the systems you want in your main(), e.g.:
//   G4VisManager* myVisManager = new MyVisManager;
//   myVisManager -> RegisterGraphicsSystem (new MyGraphicsSystem);
//
// See class description of G4VisManager for more details.

#ifndef MYEXAMPLEVISMANAGER_HH
#define MYEXAMPLEVISMANAGER_HH

#include "G4VisManager.hh"

class MyVisManager: public G4VisManager {

public: // With description

  MyVisManager ();

private:

  void RegisterGraphicsSystems ();

};

#endif

