// This code implementation is the intellectual property of
// the RD44 GEANT4 collaboration.
//
// By copying, distributing or modifying the Program (or any work
// based on the Program) you indicate your acceptance of this statement,
// and all its terms.
//
// $Id: ExN03EventAction.hh,v 2.3 1998/10/09 15:48:01 japost Exp $
// GEANT4 tag $Name: geant4-00 $
//
// 

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

#ifndef ExN03EventAction_h
#define ExN03EventAction_h 1

#include "G4UserEventAction.hh"
#include "globals.hh"

class ExN03EventActionMessenger;

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

class ExN03EventAction : public G4UserEventAction
{
  public:
    ExN03EventAction();
   ~ExN03EventAction();

  public:
    void BeginOfEventAction();
    void EndOfEventAction();
    
    void SetDrawFlag(G4String val)  {drawFlag = val;};
    
  private:
    G4int    calorimeterCollID;                // Hits collection ID
    G4String drawFlag;                         // control the drawing of event
    ExN03EventActionMessenger*  eventMessenger;
};

#endif

    