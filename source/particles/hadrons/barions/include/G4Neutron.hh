// This code implementation is the intellectual property of
// the GEANT4 collaboration.
//
// By copying, distributing or modifying the Program (or any work
// based on the Program) you indicate your acceptance of this statement,
// and all its terms.
//
// $Id: G4Neutron.hh,v 1.6 2001/03/12 05:45:41 kurasige Exp $
// GEANT4 tag $Name: geant4-03-01 $
//
// 
// ------------------------------------------------------------
//      GEANT 4 class header file
//
//      For information related to this code contact:
//      CERN, CN Division, ASD group
//      History: first implementation, based on object model of
//      4-th April 1996, G.Cosmo
// ****************************************************************
//  Added particle definitions, H.Kurashige, 19 April 1996
//  Revised, G.Cosmo, 6 June 1996
//  Added not static GetEnergyCuts() and GetLengthCuts(), G.Cosmo, 11 July 1996
//----------------------------------------------------------------

// Each class inheriting from G4VBaryon
// corresponds to a particle type; one and only one
// instance for each class is guaranteed.

#ifndef G4Neutron_h
#define G4Neutron_h 1

#include "globals.hh"
#include "G4ios.hh"
#include "G4VBaryon.hh"

// ######################################################################
// ###                         NEUTRON                                ###
// ######################################################################

class G4Neutron : public G4VBaryon
{
 private:
   static G4Neutron theNeutron;
   static G4double  theNeutronLengthCut;
   static G4double* theNeutronKineticEnergyCuts;

 private:
  G4Neutron(
       const G4String&     aName,        G4double            mass,
       G4double            width,        G4double            charge,   
       G4int               iSpin,        G4int               iParity,    
       G4int               iConjugation, G4int               iIsospin,   
       G4int               iIsospin3,    G4int               gParity,
       const G4String&     pType,        G4int               lepton,      
       G4int               baryon,       G4int               encoding,
       G4bool              stable,       G4double            lifetime,
       G4DecayTable        *decaytable
   );

 public:
   virtual ~G4Neutron(){}

   static G4Neutron* NeutronDefinition();
   static G4Neutron* Neutron(){return &theNeutron;}
   static G4double GetCuts() {return theNeutronLengthCut;}   
   static G4double* GetCutsInEnergy() {return theNeutronKineticEnergyCuts;};

   virtual void SetCuts(G4double aCut); 
   virtual void RestoreCuts(G4double cutInLength,
			    const G4double* cutInEnergy );

 public:  //With Description
   G4int    GetAtomicNumber() const;
   G4int    GetAtomicMass() const;

   G4double GetExcitationEnergy() const {return 0.;} 
   void     SetExcitationEnergy(G4double ){}
   // These two methods are dummy because all particles derived from 
   // G4Neutron is "groud state" nuclei  
};

inline
 G4int G4Neutron::GetAtomicNumber() const 
{
  return 0; 
}

inline
 G4int G4Neutron::GetAtomicMass() const 
{
  return 1;
}

inline
 void G4Neutron::RestoreCuts(G4double cutInLength,
			    const G4double* cutInEnergy )
{
  G4ParticleWithCuts::RestoreCuts(cutInLength, cutInEnergy);
  theNeutronLengthCut = theCutInMaxInteractionLength;  
  theNeutronKineticEnergyCuts = theKineticEnergyCuts;
}

#endif
