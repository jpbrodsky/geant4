// This code implementation is the intellectual property of
// the GEANT4 collaboration.
//
// By copying, distributing or modifying the Program (or any work
// based on the Program) you indicate your acceptance of this statement,
// and all its terms.
//
// $Id: G4ReactionProduct.cc,v 1.2 1999/12/15 14:53:41 gunter Exp $
// GEANT4 tag $Name: geant4-03-01 $
//
 // J.L. Chuma, TRIUMF, 31-Oct-1996
 // last modified: 19-Dec-1996
 // Modified by J.L.Chuma, 05-May-97
 
#include "G4ReactionProduct.hh"

 G4ReactionProduct::G4ReactionProduct() :
    theParticleDefinition(NULL),
    formationTime(0.0),
    hasInitialStateParton(false),
    mass(0.0),
    totalEnergy(0.0),
    kineticEnergy(0.0),
    timeOfFlight(0.0),
    side(0),
    NewlyAdded(false)
  {
    SetMomentum( 0.0, 0.0, 0.0 );
    SetPositionInNucleus( 0.0, 0.0, 0.0 );
  }
 
 G4ReactionProduct::G4ReactionProduct(
  G4ParticleDefinition *aParticleDefinition )
  {
    SetMomentum( 0.0, 0.0, 0.0 );
    SetPositionInNucleus( 0.0, 0.0, 0.0 );
    formationTime = 0.0;
    hasInitialStateParton = false;
    theParticleDefinition = aParticleDefinition;
    mass = aParticleDefinition->GetPDGMass();
    totalEnergy = mass;
    kineticEnergy = 0.0;
    (aParticleDefinition->GetPDGEncoding()<0) ? timeOfFlight=-1.0 : timeOfFlight=1.0;
    side = 0;
    NewlyAdded = false;
  }
 
 G4ReactionProduct::G4ReactionProduct(
  const G4ReactionProduct &right )
  {
    theParticleDefinition = right.theParticleDefinition;
    positionInNucleus = right.positionInNucleus;
    formationTime = right.formationTime;
    hasInitialStateParton = right.hasInitialStateParton;
    momentum = right.momentum;
    mass = right.mass;
    totalEnergy = right.totalEnergy;
    kineticEnergy = right.kineticEnergy;
    timeOfFlight = right.timeOfFlight;
    side = right.side;
    NewlyAdded = right.NewlyAdded;
  }
 
 G4ReactionProduct &G4ReactionProduct::operator=(
  const G4ReactionProduct &right )
  {
    if( this != &right ) {
      theParticleDefinition = right.theParticleDefinition;
      positionInNucleus = right.positionInNucleus;
      formationTime = right.formationTime;
      hasInitialStateParton = right.hasInitialStateParton;
      momentum = right.momentum;
      mass = right.mass;
      totalEnergy = right.totalEnergy;
      kineticEnergy = right.kineticEnergy;
      timeOfFlight = right.timeOfFlight;
      side = right.side;
      NewlyAdded = right.NewlyAdded;
    }
    return *this;
  }
    
 G4ReactionProduct &G4ReactionProduct::operator=(
  const G4DynamicParticle &right )
  {
    theParticleDefinition = right.GetDefinition();
    SetPositionInNucleus( 0.0, 0.0, 0.0 );
    formationTime = 0.0;
    hasInitialStateParton = false;
    momentum = right.GetMomentum();
    mass = right.GetDefinition()->GetPDGMass();
    totalEnergy = right.GetTotalEnergy();
    kineticEnergy = right.GetKineticEnergy();
    (right.GetDefinition()->GetPDGEncoding()<0) ? timeOfFlight=-1.0 : timeOfFlight=1.0;
    side = 0;
    NewlyAdded = false;
    return *this;
  }
 
 void G4ReactionProduct::SetDefinitionAndUpdateE(
  G4ParticleDefinition *aParticleDefinition )
  {
    G4double aKineticEnergy = GetKineticEnergy();
    G4double pp = GetMomentum().mag();
    G4ThreeVector aMomentum = GetMomentum();
    SetDefinition( aParticleDefinition );
    SetKineticEnergy( aKineticEnergy );
    if( pp > DBL_MIN )
      SetMomentum( aMomentum * (sqrt(aKineticEnergy*aKineticEnergy +
                                    2*aKineticEnergy*GetMass())/pp) );
  }

 void G4ReactionProduct::SetDefinition(
  G4ParticleDefinition *aParticleDefinition )
  {
    theParticleDefinition = aParticleDefinition;
    mass = aParticleDefinition->GetPDGMass();
    totalEnergy = mass;
    kineticEnergy = 0.0;
    (aParticleDefinition->GetPDGEncoding()<0) ?
      timeOfFlight=-1.0 : timeOfFlight=1.0;
  }
 
 void G4ReactionProduct::SetMomentum(
  const G4double x, const G4double y, const G4double z )
  {
    momentum.setX( x );
    momentum.setY( y );
    momentum.setZ( z );
  }
 
 void G4ReactionProduct::SetMomentum(
  const G4double x, const G4double y )
  {
    momentum.setX( x );
    momentum.setY( y );
  }
 
 void G4ReactionProduct::SetMomentum( const G4double z )
  {
    momentum.setZ( z );
  }
 
 void G4ReactionProduct::SetZero()
  {
    SetMomentum( 0.0, 0.0, 0.0 );
    totalEnergy = 0.0;
    kineticEnergy = 0.0;
    mass = 0.0;
    timeOfFlight = 0.0;
    side = 0;
    NewlyAdded = false;
    SetPositionInNucleus( 0.0, 0.0, 0.0 );
    formationTime = 0.0;
    hasInitialStateParton = false;
  }
 
 void G4ReactionProduct::Lorentz(
   const G4ReactionProduct &p1, const G4ReactionProduct &p2 )
  {
    G4ThreeVector p1M = p1.momentum;
    G4ThreeVector p2M = p2.momentum;
    G4double p1x = p1M.x(); G4double p1y = p1M.y(); G4double p1z = p1M.z();
    G4double p2x = p2M.x(); G4double p2y = p2M.y(); G4double p2z = p2M.z();
    G4double a = ( (p1x*p2x+p1y*p2y+p1z*p2z)/(p2.totalEnergy+p2.mass) -
                   p1.totalEnergy ) / p2.mass;
    G4double x = p1x+a*p2x;
    G4double y = p1y+a*p2y;
    G4double z = p1z+a*p2z;
    G4double p = sqrt(x*x+y*y+z*z);
    SetMass( p1.mass );
    SetTotalEnergy( sqrt( (p1.mass+p)*(p1.mass+p) - 2.*p1.mass*p ) );
    //SetTotalEnergy( sqrt( p1.mass*p1.mass + x*x + y*y + z*z ) );
    SetMomentum( x, y, z );
  }
 
 G4double G4ReactionProduct::Angle(
  const G4ReactionProduct& p ) const
  {
    G4ThreeVector tM = momentum;
    G4ThreeVector pM = p.momentum;
    G4double tx = tM.x(); G4double ty = tM.y(); G4double tz = tM.z();
    G4double px = pM.x(); G4double py = pM.y(); G4double pz = pM.z();
    G4double a = sqrt( ( px*px + py*py + pz*pz ) * ( tx*tx + ty*ty + tz*tz ) );
    if( a == 0.0 ) {
      return 0.0;
    } else {
      a = ( tx*px + ty*py + tz*pz ) / a;
      if( fabs(a) > 1.0 ) { a<0.0 ? a=-1.0 : a=1.0; }
      return acos( a );
    }
  }
 
 G4ReactionProduct operator+(
  const G4ReactionProduct& p1, const G4ReactionProduct& p2 )
  {
    G4double totEnergy = p1.totalEnergy + p2.totalEnergy;
    G4double x = p1.momentum.x() + p2.momentum.x();
    G4double y = p1.momentum.y() + p2.momentum.y();
    G4double z = p1.momentum.z() + p2.momentum.z();
    G4double newMass = totEnergy*totEnergy - ( x*x + y*y + z*z );
    if( newMass < 0.0 )
      newMass = -1. * sqrt( -newMass );
    else
      newMass = sqrt( newMass );
    G4ReactionProduct result;
    result.SetMass( newMass );
    result.SetMomentum( x, y, z );
    result.SetTotalEnergy( totEnergy );
    result.SetPositionInNucleus( 0.0, 0.0, 0.0 );
    result.SetFormationTime(0.0);
    result.HasInitialStateParton(false);
    return result;
  }
 
 G4ReactionProduct operator-(
  const G4ReactionProduct& p1, const G4ReactionProduct& p2 )
  {
    G4double totEnergy = p1.totalEnergy - p2.totalEnergy;
    G4double x = p1.momentum.x() - p2.momentum.x();
    G4double y = p1.momentum.y() - p2.momentum.y();
    G4double z = p1.momentum.z() - p2.momentum.z();
    G4double newMass = totEnergy*totEnergy - ( x*x + y*y + z*z );
    if( newMass < 0.0 )
      newMass = -1. * sqrt( -newMass );
    else
      newMass = sqrt( newMass );
    G4ReactionProduct result;
    result.SetMass( newMass );
    result.SetMomentum( x, y, z );
    result.SetTotalEnergy( totEnergy );
    result.SetPositionInNucleus( 0.0, 0.0, 0.0 );
    result.SetFormationTime(0.0);
    result.HasInitialStateParton(false);
    return result;
  }
 /* end of code */
 
