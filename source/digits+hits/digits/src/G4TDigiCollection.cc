// This code implementation is the intellectual property of
// the GEANT4 collaboration.
//
// By copying, distributing or modifying the Program (or any work
// based on the Program) you indicate your acceptance of this statement,
// and all its terms.
//
// $Id: G4TDigiCollection.cc,v 1.2 1999/12/15 14:49:37 gunter Exp $
// GEANT4 tag $Name: geant4-03-01 $
//

#include "G4TDigiCollection.hh"

G4Allocator<G4DigiCollection> aDCAllocator;

G4DigiCollection::G4DigiCollection()
{;}

G4DigiCollection::G4DigiCollection(G4String detName,G4String colNam)
: G4VDigiCollection(detName,colNam)
{;}

G4DigiCollection::~G4DigiCollection()
{;}

int G4DigiCollection::operator==(const G4DigiCollection &right) const
{ return (collectionName==right.collectionName); }

