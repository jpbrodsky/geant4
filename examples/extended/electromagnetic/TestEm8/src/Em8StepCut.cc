// This code implementation is the intellectual property of
// the GEANT4 collaboration.
//
// By copying, distributing or modifying the Program (or any work
// based on the Program) you indicate your acceptance of this statement,
// and all its terms.
//
// $Id: Em8StepCut.cc,v 1.3 2000/06/27 13:29:53 gcosmo Exp $
// GEANT4 tag $Name: geant4-03-01 $
//

#include "Em8StepCut.hh"

#include "G4Step.hh"
#include "G4UserLimits.hh"
#include "G4VParticleChange.hh"
#include "G4EnergyLossTables.hh"

Em8StepCut::Em8StepCut(const G4String& aName)
  : G4VDiscreteProcess(aName),MaxChargedStep(DBL_MAX)
{
   if (verboseLevel>0) {
     G4cout << GetProcessName() << " is created "<< G4endl;
   }
}

Em8StepCut::~Em8StepCut()
{
}

Em8StepCut::Em8StepCut(Em8StepCut& right)
    :G4VDiscreteProcess(right)
{}

void Em8StepCut::SetMaxStep(G4double step)
{
  MaxChargedStep = step ;
}


