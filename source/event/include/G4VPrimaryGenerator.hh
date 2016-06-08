// This code implementation is the intellectual property of
// the GEANT4 collaboration.
//
// By copying, distributing or modifying the Program (or any work
// based on the Program) you indicate your acceptance of this statement,
// and all its terms.
//
// $Id: G4VPrimaryGenerator.hh,v 1.3 1999/12/15 14:49:39 gunter Exp $
// GEANT4 tag $Name: geant4-03-01 $
//

#ifndef G4VPrimaryGenerator_h
#define G4VPrimaryGenerator_h 1

class G4Event;

// class description:
//
//  This is an abstract base class of all of primary generators.
// This class has only one pure virtual method GeneratePrimaryVertex()
// which takes a G4Event object and generates a primay vertex and
// primary particles associate to the vertex.
//

class G4VPrimaryGenerator
{
  public:
     G4VPrimaryGenerator();
     virtual ~G4VPrimaryGenerator();

     virtual void GeneratePrimaryVertex(G4Event* evt) = 0;
};

#endif

