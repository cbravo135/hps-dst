/**
 *	@author:	Omar Moreno <omoreno1@ucsc.edu>
 *	@section institution
 *				Santa Cruz Institute for Particle Physics
 *				University of California, Santa Cruz
 *	@date:		August 15, 2014
 *
 */

#include <EcalScoringPlaneDataWriter.h>

EcalScoringPlaneDataWriter::EcalScoringPlaneDataWriter()
	: ecal_sp_hits_collection_name("TrackerHitsECal")
{}

EcalScoringPlaneDataWriter::~EcalScoringPlaneDataWriter()
{}

void EcalScoringPlaneDataWriter::writeData(EVENT::LCEvent* event, HpsEvent* hps_event)
{
	// Get the collection of Ecal scoring plane hits
	ecal_sp_hits = (IMPL::LCCollectionVec*) event->getCollection(ecal_sp_hits_collection_name); 

	// Loop over the Ecal scoring plane hits and fill the HpsEvent
	for(int ecal_sp_hit_n = 0; ecal_sp_hit_n < ecal_sp_hits->getNumberOfElements(); ++ecal_sp_hit_n){ 
		
		// Get an Ecal scoring plane hit from the LCIO collection 
		ecal_sp_hit = (IMPL::SimTrackerHitImpl*) ecal_sp_hits->getElementAt(ecal_sp_hit_n); 

		// Add an Ecal scoring plane hit to the HpsEvent 
		hps_ecal_sp_hit = hps_event->addEcalScoringPlaneHit(); 

		// Set the position of the Ecal scoring plane hit
		hps_ecal_sp_hit->setPosition(ecal_sp_hit->getPosition()); 
		
	}
}
