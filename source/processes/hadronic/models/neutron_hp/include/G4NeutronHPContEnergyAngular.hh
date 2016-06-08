// This code implementation is the intellectual property of
// neutron_hp -- header file
// J.P. Wellisch, Nov-1996
// A prototype of the low energy neutron transport model.
//
// By copying, distributing or modifying the Program (or any work
// based on the Program) you indicate your acceptance of this statement,
// and all its terms.
//
// $Id: G4NeutronHPContEnergyAngular.hh,v 1.4 1999/12/15 14:53:11 gunter Exp $
// GEANT4 tag $Name: geant4-03-01 $
//
#ifndef G4NeutronHPContEnergyAngular_h
#define G4NeutronHPContEnergyAngular_h 1

#include "G4ios.hh"
#include "g4std/fstream"
#include "globals.hh"
#include "G4VNeutronHPEnergyAngular.hh"
#include "G4NeutronHPContAngularPar.hh"
#include "G4InterpolationManager.hh"

// we will need one of these per product.

class G4NeutronHPContEnergyAngular : public G4VNeutronHPEnergyAngular
{
  public:
  
  G4NeutronHPContEnergyAngular()
  {
    theAngular = NULL;
    currentMeanEnergy = -2;
  }
  
  ~G4NeutronHPContEnergyAngular()
  {
    if(theAngular!=NULL) delete [] theAngular;
  }
  
  public:
  
  void Init(G4std::ifstream & aDataFile)
  {
    aDataFile >> theTargetCode >> theAngularRep >> theInterpolation >> nEnergy;
    theAngular = new G4NeutronHPContAngularPar[nEnergy];
    theManager.Init(aDataFile);
    for(G4int i=0; i<nEnergy; i++)
    {
      theAngular[i].Init(aDataFile);
      theAngular[i].SetInterpolation(theInterpolation);
    }
  }
G4double MeanEnergyOfThisInteraction();
G4ReactionProduct * Sample(G4double anEnergy, G4double massCode, G4double mass);
  
  private:
  
  G4double theTargetCode;
  G4int theAngularRep;
  G4int nEnergy;
  
  G4int theInterpolation;

  G4InterpolationManager theManager; // knows the interpolation between stores
  G4NeutronHPContAngularPar * theAngular;
  
  G4double currentMeanEnergy;
  
};
#endif
