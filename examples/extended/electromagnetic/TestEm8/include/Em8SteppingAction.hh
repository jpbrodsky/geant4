// This code implementation is the intellectual property of
// the GEANT4 collaboration.
//
// By copying, distributing or modifying the Program (or any work
// based on the Program) you indicate your acceptance of this statement,
// and all its terms.
//
// $Id: Em8SteppingAction.hh,v 1.2 2000/06/27 13:29:47 gcosmo Exp $
// GEANT4 tag $Name: geant4-03-01 $
//
// 

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

#ifndef Em8SteppingAction_h
#define Em8SteppingAction_h 1

#include "G4UserSteppingAction.hh"
#include "G4Event.hh"
#include "G4EventManager.hh"
#include "G4ios.hh"
#include "globals.hh"

class Em8DetectorConstruction;
class Em8RunAction;
class Em8EventAction;
class Em8SteppingMessenger;

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

class Em8SteppingAction : public G4UserSteppingAction
{
  public:
    Em8SteppingAction(Em8DetectorConstruction*, Em8EventAction*,
                      Em8RunAction* );
   ~Em8SteppingAction();

    void UserSteppingAction(const G4Step*);

  private:
    Em8DetectorConstruction* detector;
    Em8EventAction*          eventaction;
    Em8RunAction*            runaction;
    Em8SteppingMessenger*    steppingMessenger;

    G4int IDnow,IDold;
    G4int evnoold ;

};

#endif
