/**
 *  @author:	Omar Moreno <omoreno1@ucsc.edu>
 *  @section institution
 *				Santa Cruz Institute for Particle Physics
 *				University of California, Santa Cruz
 *	@date:		August 14, 2014
 *
 */

#ifndef __ECAL_SCORING_PLANE_HIT__
#define __ECAL_SCORING_PLANE_HIT__

//--- C++ ---//
//-----------//
#include <vector>

//--- ROOT ---//
//------------//
#include <TObject.h>

class EcalScoringPlaneHit : public TObject { 

	public: 

		EcalScoringPlaneHit();
		virtual ~EcalScoringPlaneHit();
		void Clear(Option_t *option="");

		void setPosition(const double*);

		std::vector<double> getPosition() const;

		ClassDef(EcalScoringPlaneHit, 1);

	private:

		double ecal_sp_x;
		double ecal_sp_y;
		double ecal_sp_z;	

}; // EcalScoringPlaneHit

#endif // __ECAL_SCORING_PLANE_HIT__
