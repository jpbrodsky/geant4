//
// ********************************************************************
// * DISCLAIMER                                                       *
// *                                                                  *
// * The following disclaimer summarizes all the specific disclaimers *
// * of contributors to this software. The specific disclaimers,which *
// * govern, are listed with their locations in:                      *
// *   http://cern.ch/geant4/license                                  *
// *                                                                  *
// * Neither the authors of this software system, nor their employing *
// * institutes,nor the agencies providing financial support for this *
// * work  make  any representation or  warranty, express or implied, *
// * regarding  this  software system or assume any liability for its *
// * use.                                                             *
// *                                                                  *
// * This  code  implementation is the  intellectual property  of the *
// * GEANT4 collaboration.                                            *
// * By copying,  distributing  or modifying the Program (or any work *
// * based  on  the Program)  you indicate  your  acceptance of  this *
// * statement, and all its terms.                                    *
// ********************************************************************
//
//
// $Id: B03PrimaryGeneratorAction.cc,v 1.5 2002/11/08 17:35:19 dressel Exp $
// GEANT4 tag $Name: geant4-06-00 $
//

#include "globals.hh"

#include "B03PrimaryGeneratorAction.hh"

#include "G4Event.hh"
#include "G4ParticleGun.hh"
#include "G4Neutron.hh"
#include "G4ThreeVector.hh"

B03PrimaryGeneratorAction::B03PrimaryGeneratorAction()
{
  G4int n_particle = 1;
  particleGun = new G4ParticleGun(n_particle);
  particleGun->SetParticleDefinition(G4Neutron::NeutronDefinition());
  particleGun->SetParticleEnergy(10.0*MeV);
  particleGun->SetParticlePosition(G4ThreeVector(0.0, 0.0, -90.0005*cm));
  particleGun->SetParticleMomentumDirection(G4ThreeVector(0.0, 0.0, 1.0));
}

B03PrimaryGeneratorAction::~B03PrimaryGeneratorAction()
{
  delete particleGun;
}

void B03PrimaryGeneratorAction::GeneratePrimaries(G4Event* anEvent)
{
  particleGun->GeneratePrimaryVertex(anEvent);
}