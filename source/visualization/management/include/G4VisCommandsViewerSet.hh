// This code implementation is the intellectual property of
// the GEANT4 collaboration.
//
// By copying, distributing or modifying the Program (or any work
// based on the Program) you indicate your acceptance of this statement,
// and all its terms.
//
// $Id: G4VisCommandsViewerSet.hh,v 1.8 2001/02/06 23:36:52 johna Exp $
// GEANT4 tag $Name: geant4-03-01 $

// /vis/viewer/set commands - John Allison  16th May 2000

#ifndef G4VISCOMMANDSVIEWERSET_HH
#define G4VISCOMMANDSVIEWERSET_HH

#include "G4VisCommandsViewer.hh"

#include "g4std/vector"

class G4UIcommand;
class G4UIcmdWithAString;
class G4UIcmdWithABool;
class G4UIcmdWithAnInteger;

class G4VisCommandsViewerSet: public G4VVisCommandViewer {
public:
  G4VisCommandsViewerSet ();
  virtual ~G4VisCommandsViewerSet ();
  G4String GetCurrentValue (G4UIcommand* command);
  void SetNewValue (G4UIcommand* command, G4String newValue);
private:
  G4VisCommandsViewerSet (const G4VisCommandsViewerSet&);
  G4VisCommandsViewerSet& operator = (const G4VisCommandsViewerSet&);
  G4UIcmdWithAString*   fpCommandAll;
  G4UIcmdWithABool*     fpCommandAutoRefresh;
  G4UIcommand*          fpCommandCulling;
  G4UIcmdWithABool*     fpCommandEdge;
  G4UIcmdWithABool*     fpCommandHiddenEdge;
  G4UIcmdWithABool*     fpCommandHiddenMarker;
  G4UIcmdWithAnInteger* fpCommandLineSegments;
  G4UIcmdWithAString*   fpCommandLightsMove;
  G4UIcommand*          fpCommandProjection;
  G4UIcommand*          fpCommandSectionPlane;
  G4UIcmdWithAString*   fpCommandStyle;
};

#endif
