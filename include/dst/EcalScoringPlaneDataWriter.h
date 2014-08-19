/**
 *	@author:	Omar Moreno <omoreno1@ucsc.edu>
 *	@section institution
 *				Santa Cruz Institute for Particle Physics
 *				University of California, Santa Cruz
 *	@date:		August 15, 2014
 *
 */

#ifndef __ECAL_SCORING_PLANE_DRIVER_WRITER__
#define __ECAL_SCORING_PLANE_DRIVER_WRITER__

//--- C++ ---//
//-----------//
#include <string>

//--- DST ---//
//-----------//
#include <DataWriter.h>

//--- LCIO ---//
//------------//
#include <IMPL/LCCollectionVec.h>
#include <IMPL/SimTrackerHitImpl.h>

//--- HPS Event ---//
//-----------------//
#include <EcalScoringPlaneHit.h>

class EcalScoringPlaneDataWriter : public DataWriter { 

	public: 

		EcalScoringPlaneDataWriter(); 
		~EcalScoringPlaneDataWriter();

		// 
		void writeData(EVENT::LCEvent*, HpsEvent*);

	private:

		std::string ecal_sp_hits_collection_name; 

		IMPL::LCCollectionVec* ecal_sp_hits; 
		IMPL::SimTrackerHitImpl* ecal_sp_hit; 

		EcalScoringPlaneHit* hps_ecal_sp_hit;

}; // EcalScoringPlaneDataWriter

#endif  // __ECAL_SCORING_PLANE_DRIVER_WRITER__
