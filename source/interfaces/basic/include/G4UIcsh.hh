// This code implementation is the intellectual property of
// the GEANT4 collaboration.
//
// By copying, distributing or modifying the Program (or any work
// based on the Program) you indicate your acceptance of this statement,
// and all its terms.
//
// $Id: G4UIcsh.hh,v 1.2 2000/07/22 10:52:28 asaim Exp $
// GEANT4 tag $Name: geant4-03-01 $
//

#ifndef G4UIcsh_h
#define G4UIcsh_h

#include "G4VUIshell.hh"

//
//   Description:
//   This class gives csh-like shell. (same as dumb terminal)
//

class G4UIcsh : public G4VUIshell {
protected:

public:
  G4UIcsh(const G4String& prompt="%s> ");
  ~G4UIcsh();
  
  virtual G4String GetCommandLine(const char* msg=0);

};

#endif

