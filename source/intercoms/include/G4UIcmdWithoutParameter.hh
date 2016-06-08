// This code implementation is the intellectual property of
// the GEANT4 collaboration.
//
// By copying, distributing or modifying the Program (or any work
// based on the Program) you indicate your acceptance of this statement,
// and all its terms.
//
// $Id: G4UIcmdWithoutParameter.hh,v 1.3 1999/12/15 14:50:39 gunter Exp $
// GEANT4 tag $Name: geant4-03-01 $
//
//

#ifndef G4UIcmdWithoutParameter_H
#define G4UIcmdWithoutParameter_H 1

#include "G4UIcommand.hh"

// class description:
//  A concrete class of G4UIcommand. The command defined by this class
// takes no parameter argument.
//  General information of G4UIcommand is given in G4UIcommand.hh.

class G4UIcmdWithoutParameter : public G4UIcommand
{
  public: // with description
    G4UIcmdWithoutParameter
    (const char * theCommandPath,G4UImessenger * theMessenger);
    //  Constructor. The command string with full path directory
    // and the pointer to the messenger must be given.
};

#endif
