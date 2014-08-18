/**
 *
 * @author: 	Omar Moreno <omoreno1@ucsc.edu>
 * @section institution
 * 				Santa Cruz Institute for Particle Physics
 * 				University of California, Santa Cruz
 * @date:       February 19, 2013
 */

#ifndef _HPS_EVENT_H_
#define	_HPS_EVENT_H_

//--- C++ ---//
#include <iostream>
#include <assert.h>

//-- ROOT ---//
#include <TObject.h>
#include <TClonesArray.h>

//--- HPS Event ---//
//-----------------//
#include <SvtTrack.h>
#include <SvtHit.h>
#include <EcalCluster.h> 
#include <EcalHit.h>
#include <MuonCluster.h>
#include <HpsParticle.h>
#include <HpsMCParticle.h>
#include <GblTrackData.h>
#include <GblStripData.h>
#include <GblTrack.h>
#include <EcalScoringPlaneHit.h>

class HpsEvent : public TObject { 

    public:

		HpsEvent();
        HpsEvent(const HpsEvent &hpsEventoObj);
        virtual ~HpsEvent();    
        HpsEvent &operator=(const HpsEvent &hpsEventObj);

		enum collection_t { 
			FINAL_STATE_PARTICLES = 0,
			UC_VTX_PARTICLES	  = 1, 
			BSC_VTX_PARTICLES	  = 2, 
			TC_VTX_PARTICLES	  = 3
		};

        void Clear(Option_t *option="");
        SvtTrack* 		addTrack();
        SvtHit* 		addSvtHit();
        EcalCluster* 	addEcalCluster();
        EcalHit* 		addEcalHit();
        MuonCluster* 	addMuonCluster();
        HpsParticle*    addParticle(collection_t); 
        HpsMCParticle*  addHpsMCParticle();
        GblTrack*   	addGblTrack();
        GblTrackData* 	addGblTrackData();
        GblStripData* 	addGblStripData();
		EcalScoringPlaneHit* addEcalScoringPlaneHit(); 

        void setEventNumber(int event_number){ this->event_number = event_number; };
        void setRunNumber(int run_number){ this->run_number = run_number; };
        void setTriggerBitInfo(std::vector<int> trigger_bits){ this->trigger_bits = trigger_bits; };

        int getEventNumber()            const  { return event_number; };
        int getRunNumber()              const  { return run_number; };
        int getNumberOfTracks()         const  { return n_tracks; };
        int getNumberOfEcalClusters()   const  { return n_ecal_clusters; };
        int getNumberOfMuonClusters()   const  { return n_muon_clusters; };
		int getNumberOfParticles(collection_t)	const; 
        int getNumberOfGblTracks()      const  { return n_gbl_tracks; };
        int getNumberOfGblTracksData()  const  { return n_gbl_tracks_data; };
        int getNumberOfGblStripData()   const  { return n_gbl_strips_data; };
		int getNumberOfEcalScoringPlaneHits() const { return n_ecal_sp_hits; }; 
		std::vector<int> getTriggerBitInfo() const { return trigger_bits; };

        SvtTrack*      getTrack(int);
        SvtHit*        getSvtHit(int);
        EcalCluster*   getEcalCluster(int);
        EcalHit* 	   getEcalHit(int);
        MuonCluster*   getMuonCluster(int);
        HpsMCParticle* getMCParticle(int);
        HpsParticle*   getParticle(collection_t, int); 
        GblTrack*      getGblTrack(int);
        GblTrackData*  getGblTrackData(int);
        GblStripData*  getGblStripData(int);
		EcalScoringPlaneHit* getEcalScoringPlaneHit(int); 

        ClassDef(HpsEvent, 1);	

    private:

        TClonesArray* tracks;              //->
        TClonesArray* svt_hits;            //->
        TClonesArray* ecal_clusters;       //->
        TClonesArray* ecal_hits; 		   //->
        TClonesArray* muon_clusters;       //->
        TClonesArray* fs_particles;        //->
        TClonesArray* uc_vtx_particles;    //->
        TClonesArray* bsc_vtx_particles;   //->
        TClonesArray* tc_vtx_particles;    //->
        TClonesArray* mc_particles; 	   //->
        TClonesArray* gbl_tracks;          //->
        TClonesArray* gbl_tracks_data;     //->
        TClonesArray* gbl_strips_data;     //->
		TClonesArray* ecal_sp_hits;		   //->

        int event_number;
        int run_number;
        int n_tracks;
        int n_svt_hits;
        int n_ecal_clusters;
        int n_ecal_hits;
        int n_muon_clusters;
        int n_fs_particles;
        int n_uc_vtx_particles;
        int n_bsc_vtx_particles;
        int n_tc_vtx_particles;
        int n_mc_particles;
        int n_gbl_tracks;
        int n_gbl_tracks_data;
        int n_gbl_strips_data;
		int n_ecal_sp_hits; 

		std::vector<int> trigger_bits;
};

#endif


