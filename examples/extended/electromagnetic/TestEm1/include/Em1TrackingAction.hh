// This code implementation is the intellectual property of
// the GEANT4 collaboration.
//
// By copying, distributing or modifying the Program (or any work
// based on the Program) you indicate your acceptance of this statement,
// and all its terms.
//
// $Id: Em1TrackingAction.hh,v 1.2 1999/12/15 14:48:56 gunter Exp $
// GEANT4 tag $Name: geant4-03-01 $
//
//

#ifndef Em1TrackingAction_h
#define Em1TrackingAction_h 1

#include "G4UserTrackingAction.hh"

class Em1RunAction;

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

class Em1TrackingAction : public G4UserTrackingAction {

  public:  
    Em1TrackingAction(Em1RunAction*);
   ~Em1TrackingAction() {};
   
    void PostUserTrackingAction(const G4Track*);
    
  private:
    Em1RunAction* runAction;  
};

#endif
