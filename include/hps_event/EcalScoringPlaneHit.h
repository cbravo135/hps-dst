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
#include <TRef.h>

//--- HPS Event ---//
//-----------------//
#include <HpsParticle.h>

class EcalScoringPlaneHit : public TObject { 

	public: 

		EcalScoringPlaneHit();
		virtual ~EcalScoringPlaneHit();
		void Clear(Option_t *option="");

		void setParticle(HpsParticle* particle){this->particle = particle; };
		void setPosition(const double*);

		HpsParticle* getParticle();
		std::vector<double> getPosition() const;

		ClassDef(EcalScoringPlaneHit, 1);

	private:

		TRef particle;

		double ecal_sp_x;
		double ecal_sp_y;
		double ecal_sp_z;	

}; // EcalScoringPlaneHit

#endif // __ECAL_SCORING_PLANE_HIT__
