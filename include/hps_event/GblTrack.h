/**
 *
 * @author: 	phansson@slac.stanford.edu
 * @section purpose: GBL track information
 * @version:    v1.0
 * @date:       February 3, 2014
 */

#ifndef _GBL_TRACK_H_
#define _GBL_TRACK_H_

//--- C++ ---//
#include <iostream>

//--- ROOT ---//
#include <TObject.h>
#include <TClonesArray.h>
#include <TRefArray.h>
#include <TMatrixD.h>

class GblTrack : public TObject {
  
 public:
  GblTrack();
  virtual ~GblTrack();

   // setters
   void setSeedTrackParameters(double kappa, double theta, double phi, double d0, double z0);
   void setTrackParameters(double C, double th, double phi0, double dca, double z);
   void setChi2(double c);
   void setNdf(double ndof);
   void setMomentumVector(double x, double y, double z);
   void setCov(const TMatrixD& mat);

   // Getters
   double getPx()  	  const { return px; };
   double getPy()  	  const { return py; };
   double getPz()  	  const { return pz; };
   double getKappa() const { return kappa;}
   double getTheta() const { return theta;}
   double getPhi() const { return phi;}
   double getD0() const { return d0;}
   double getZ0() const { return z0;}
   double getChi2() const { return chi2;}
   double getNdf() const { return ndf;}
   double getSeedKappa() const { return seed_kappa;}
   double getSeedTheta() const { return seed_theta;}
   double getSeedPhi() const { return seed_phi;}
   double getSeedD0() const { return seed_d0; }
   double getSeedZ0() const { return seed_z0; }
   void print();

   ClassDef(GblTrack,1) //Track class for use with GBL
   
 private:
   double kappa;
   double theta;
   double phi;
   double d0;
   double z0;
   double seed_kappa;
   double seed_theta;
   double seed_phi;
   double seed_d0;
   double seed_z0;
   double chi2;
   double ndf;
   double px;
   double py;
   double pz;
   TMatrixD cov;

}; // GblTrack

#endif // _GBL_TRACK_H_