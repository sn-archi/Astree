// this file is covered by the General Public License version 2 or later
// please see GPL.html for more details and licensing issues
// copyright Etienne de Foras ( the author )  mailto: etienne.deforas@gmail.com

#ifndef _Light_
#define _Light_

#include <string>
#include <vector>
using namespace std;

class Photon;
class Glass;

class Light
{
public:
    Light();
    virtual ~Light();
    vector<Photon> get_all_photons();
    void set_nb_photons(int iNbX,int iNbY);

    Photon& get_photon(int iPos);
    const vector<Photon>& photons() const;
    int nb_photon();

    void set_tilt(double dTiltX,double dTiltY);
    void get_tilt(double& dTiltX,double& dTiltY) const;
    Glass& material();
    void set_material(Glass* pM);

    void set_colors(const string & vsAllColors);
    static void calc_colors(string sColors,vector<double>& vdLambda,vector<int>& vdVisualColors);
    int get_visual_color(double dLambda) const;

    void set_geometry(double dZ,double dDiameter);

    void compute_spot_size();

    void get_spot_center(double& dCenterX,double& dCenterY) const;
    double spot_size() const;
    double get_FD() const;

    double airy_radius() const;
    double spot_vs_airy() const;

    void init_vignetting();
    double vignetting() const;

private:
    void init();

    vector<Photon> _vPhotons;
    Glass* _pFirstMaterial;
    Glass* _pMaterial;
    bool _bMustInit;
    double _dTiltX,_dTiltY;
    int _iDimX,_iDimY,_iNbPhotons;
    int _iNbPhotonsInitVignetting;
    double _dDiameter,_dZ;
    double _dCenterX,_dCenterY,_dSpotSize;
    double _dFD;
    double _dVignetting;

    string _sAllColors;
    bool _bYellowBlack;
};

#endif

