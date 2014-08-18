/**
 *  @author:	Omar Moreno <omoreno1@ucsc.edu>
 *  @section institution
 *				Santa Cruz Institute for Particle Physics
 *				University of California, Santa Cruz
 *	@date:		August 15, 2014
 *
 */

#include <EcalScoringPlaneHit.h>
#include<iostream>

ClassImp(EcalScoringPlaneHit)

EcalScoringPlaneHit::EcalScoringPlaneHit() 
	: TObject(), 
	  ecal_sp_x(0), ecal_sp_y(0), ecal_sp_z(0)
{}

EcalScoringPlaneHit::~EcalScoringPlaneHit()
{
	Clear();
}

void EcalScoringPlaneHit::Clear(Option_t* /* options */)
{
	TObject::Clear();
}

void EcalScoringPlaneHit::setPosition(const double* position)
{
	ecal_sp_x = position[0];
	ecal_sp_y = position[1];
	ecal_sp_z = position[2];
}

std::vector<double> EcalScoringPlaneHit::getPosition() const
{
	std::vector<double> position(3,0);
	position[0] = ecal_sp_x; 
	position[1] = ecal_sp_y; 
	position[2] = ecal_sp_z; 
	return position;
}
