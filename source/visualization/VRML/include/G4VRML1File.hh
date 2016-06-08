// This code implementation is the intellectual property of
// the GEANT4 collaboration.
//
// By copying, distributing or modifying the Program (or any work
// based on the Program) you indicate your acceptance of this statement,
// and all its terms.
//
// $Id: G4VRML1File.hh,v 1.6 1999/12/15 14:54:14 gunter Exp $
// GEANT4 tag $Name: geant4-03-01 $
//
// G4VRML1File.hh
// Satoshi Tanaka & Yasuhide Sawada

#if defined (G4VIS_BUILD_VRMLFILE_DRIVER) || defined (G4VIS_USE_VRMLFILE)

#ifndef G4VRML1FILE_HH
#define G4VRML1FILE_HH

#include "G4VGraphicsSystem.hh"

class G4VSceneHandler;

class G4VRML1File: public G4VGraphicsSystem {
public:
	G4VRML1File(); 
	virtual ~G4VRML1File();
	G4VSceneHandler* CreateSceneHandler(const G4String& name = "");
	G4VViewer*  CreateViewer(G4VSceneHandler&, const G4String& name = "");

};

#endif //G4VRML1File_HH
#endif //G4VIS_BUILD_VRMLFILE_DRIVER

