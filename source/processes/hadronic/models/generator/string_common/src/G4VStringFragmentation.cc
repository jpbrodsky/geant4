// This code implementation is the intellectual property of
// the GEANT4 collaboration.
//
// By copying, distributing or modifying the Program (or any work
// based on the Program) you indicate your acceptance of this statement,
// and all its terms.
//
// $Id: G4VStringFragmentation.cc,v 1.2 1999/12/15 14:52:47 gunter Exp $
// GEANT4 tag $Name: geant4-03-01 $
//
// G4VStringFragmentation
#include "G4VStringFragmentation.hh"

G4VStringFragmentation::G4VStringFragmentation()
{
}

G4VStringFragmentation::G4VStringFragmentation(const G4VStringFragmentation &right)
{
}

G4VStringFragmentation::~G4VStringFragmentation()
{
}

const G4VStringFragmentation & G4VStringFragmentation::operator=(const G4VStringFragmentation &right)
{
  G4Exception("G4VStringFragmentation::operator= meant to not be accessable");
  return *this;
}

int G4VStringFragmentation::operator==(const G4VStringFragmentation &right) const
{
  return 0;
}

int G4VStringFragmentation::operator!=(const G4VStringFragmentation &right) const
{
  return 1;
}

