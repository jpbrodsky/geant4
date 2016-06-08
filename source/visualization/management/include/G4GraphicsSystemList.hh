// This code implementation is the intellectual property of
// the GEANT4 collaboration.
//
// By copying, distributing or modifying the Program (or any work
// based on the Program) you indicate your acceptance of this statement,
// and all its terms.
//
// $Id: G4GraphicsSystemList.hh,v 1.6 2001/03/07 14:37:40 johna Exp $
// GEANT4 tag $Name: geant4-03-01 $
//
// 
// John Allison  2nd April 1996

#ifndef G4GRAPHICSSYSTEMLIST_HH
#define G4GRAPHICSSYSTEMLIST_HH

#include "g4std/vector"
#include "G4VGraphicsSystem.hh"

class G4GraphicsSystemList: public G4std::vector<G4VGraphicsSystem*> {
public:
  void remove(G4VGraphicsSystem*);
};

typedef G4std::vector<G4VGraphicsSystem*>::iterator
        G4GraphicsSystemListIterator;
typedef G4std::vector<G4VGraphicsSystem*>::const_iterator
        G4GraphicsSystemListConstIterator;

#endif
