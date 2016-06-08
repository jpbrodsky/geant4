// This code implementation is the intellectual property of
// the GEANT4 collaboration.
//
// By copying, distributing or modifying the Program (or any work
// based on the Program) you indicate your acceptance of this statement,
// and all its terms.
//
// $Id: G4KaonPlus.cc,v 1.4 2000/02/27 05:57:45 kurasige Exp $
// GEANT4 tag $Name: geant4-03-01 $
//
// 
// ----------------------------------------------------------------------
//      GEANT 4 class implementation file
//
//      For information related to this code contact:
//      CERN, CN Division, ASD Group
//      History: first implementation, based on object model of
//      4th April 1996, G.Cosmo
//                              H.Kurashige   7 Jul 96
// **********************************************************************

#include "g4std/fstream"
#include "g4std/iomanip"

#include "G4KaonPlus.hh"

#include "G4PhaseSpaceDecayChannel.hh"
#include "G4KL3DecayChannel.hh"
#include "G4DecayTable.hh"

// ######################################################################
// ###                          KAONPLUS                              ###
// ######################################################################

G4KaonPlus::G4KaonPlus(
       const G4String&     aName,        G4double            mass,
       G4double            width,        G4double            charge,   
       G4int               iSpin,        G4int               iParity,    
       G4int               iConjugation, G4int               iIsospin,   
       G4int               iIsospin3,    G4int               gParity,
       const G4String&     pType,        G4int               lepton,      
       G4int               baryon,       G4int               encoding,
       G4bool              stable,       G4double            lifetime,
       G4DecayTable        *decaytable )
 : G4VMeson( aName,mass,width,charge,iSpin,iParity,
             iConjugation,iIsospin,iIsospin3,gParity,pType,
             lepton,baryon,encoding,stable,lifetime,decaytable )
{
  SetParticleSubType("kaon");
  //create Decay Table 
  G4DecayTable*   table = GetDecayTable();
  if (table!=NULL) delete table;
  table = new G4DecayTable();

 // create decay channels
  G4VDecayChannel** mode = new G4VDecayChannel*[6];
  // kaon+ -> mu+ + nu_mu
  mode[0] = new G4PhaseSpaceDecayChannel("kaon+",0.635,2,"mu+","nu_mu");
  // kaon+ -> pi+ + pi0
  mode[1] = new G4PhaseSpaceDecayChannel("kaon+",0.212,2,"pi+","pi0");
  // kaon+ -> pi+ + pi+ + pi-
  mode[2] = new G4PhaseSpaceDecayChannel("kaon+",0.056,3,"pi+","pi+","pi-");
  // kaon+ -> pi+ + pi0 + pi0
  mode[3] = new G4PhaseSpaceDecayChannel("kaon+",0.017,3,"pi+","pi0","pi0");
  // kaon+ -> pi0 + e+ + nu_e (Ke3) 
  mode[4] = new G4KL3DecayChannel("kaon+",0.048,"pi0","e+","nu_e");
  // kaon+ -> pi0 + mu+ + nu_mu (Kmu3) 
  mode[5] = new G4KL3DecayChannel("kaon+",0.032,"pi0","mu+","nu_mu");


  for (G4int index=0; index <6; index++ ) table->Insert(mode[index]);  
  delete [] mode;

  SetDecayTable(table);
}

// ......................................................................
// ...                 static member definitions                      ...
// ......................................................................
//     
//    Arguments for constructor are as follows
//               name             mass          width         charge
//             2*spin           parity  C-conjugation
//          2*Isospin       2*Isospin3       G-parity
//               type    lepton number  baryon number   PDG encoding
//             stable         lifetime    decay table 

// In this version, charged pions are set to stable
G4KaonPlus G4KaonPlus::theKaonPlus(
	      "kaon+",    0.493677*GeV,  5.314e-14*MeV,    +1.*eplus, 
		    0,              -1,             0,          
		    1,              +1,             0,             
	      "meson",               0,             0,         321,
		false,       12.371*ns,          NULL
);

G4KaonPlus*  G4KaonPlus::KaonPlusDefinition(){return &theKaonPlus;}
// initialization for static cut values
G4double   G4KaonPlus::theKaonPlusLengthCut = -1.0;
G4double*  G4KaonPlus::theKaonPlusKineticEnergyCuts = NULL;





