// This code implementation is the intellectual property of
// the GEANT4 collaboration.
//
// By copying, distributing or modifying the Program (or any work
// based on the Program) you indicate your acceptance of this statement,
// and all its terms.
//
// $Id: G4XoViewer.hh,v 1.4 1999/12/15 14:54:02 gunter Exp $
// GEANT4 tag $Name: geant4-03-01 $
//
// 
// Guy Barrand 04 November 1996
// Wo viewer - opens window, hard copy, etc.

#ifndef G4XOVIEWER_HH
#define G4XOVIEWER_HH

#if defined(G4VIS_BUILD_OPACS_DRIVER) || defined(G4VIS_USE_OPACS)

#include <X11/Intrinsic.h>
#include <OCamera.h>

#include "G4VViewer.hh"
#include "globals.hh"

class G4Xo;
class G4GoSceneHandler;

// Base class for various WoView classes.
class G4XoViewer: public G4VViewer {
public:
          G4XoViewer  (G4GoSceneHandler& scene, const G4String& name = "");
 virtual ~G4XoViewer  ();
  void    DrawView  ();
  void    ShowView  ();
  OCamera GetCamera ();
private:
  void       ClearView  ();
  void       FinishView ();
  void       SetView    ();
private:
  G4GoSceneHandler& fSceneHandler;    // Graphics Scene for this view.
  OCamera    fGoCamera;
  Widget     fXoCamera;
  Widget     fShell;
};

#endif

#endif
