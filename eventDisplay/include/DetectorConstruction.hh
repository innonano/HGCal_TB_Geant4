#ifndef DetectorConstruction_h
#define DetectorConstruction_h 1

#include "G4VUserDetectorConstruction.hh"
#include "G4RunManager.hh"
#include "globals.hh"
#include "G4LogicalVolume.hh"
#include <vector>
#include "G4GenericMessenger.hh"
#include "G4UImanager.hh"

#include "TFile.h"
#include "TTree.h"
#include "TBranch.h"
#include "materials.hh"


class G4VPhysicalVolume;
class G4LogicalVolume;

struct VisHit {
    G4int layer;
    G4double x;
    G4double y;
    G4double energy;
    G4double red;
    G4double green;
    G4double blue;
    G4String name;
    G4VPhysicalVolume* physicalVolume;
};


class DetectorConstruction : public G4VUserDetectorConstruction
{
public:
    DetectorConstruction();
    virtual ~DetectorConstruction();

    virtual G4VPhysicalVolume* Construct();
    virtual void ConstructSDandField();

    G4LogicalVolume* GetScoringVolume() const { return fScoringVolume; }

protected:
    G4LogicalVolume*  fScoringVolume;


private:
    G4LogicalVolume* logicWorld;

    void DefineCommands();
    G4GenericMessenger* fMessenger;
    void SelectConfiguration(G4int val);
    G4int _configuration;

    void OpenHGCALNtuple(G4String);
    G4String ntuplepath;
    void OpenAHCALNtuple(G4String);
    G4String ntupleAHCALpath;

    void ReadNtupleEvent(G4int);

    G4double beamLineLength;
    G4double beamLineXY;
    HGCalTBMaterials* materials;

    void ConstructHGCal();


//ntuple readout
    std::vector<G4double> HGCalLayerDistances;
    std::vector<VisHit*> HGCalHitsForVisualisation;

    TFile* m_inputFileHGCal;
    TTree* m_inputTreeHGCal;
    std::map<std::string, TBranch*> hgcalBranches;
    unsigned int eventID;
    unsigned int Nhits;
    std::vector<unsigned int>* rechit_layer_;
    std::vector<unsigned int>* rechit_module_;
    std::vector<unsigned int>* rechit_chip_;
    std::vector<unsigned int>* rechit_channel_;
    std::vector<unsigned int>* rechit_type_;
    std::vector<Float16_t>* rechit_energy_;
    std::vector<unsigned short>* rechit_toa_;
    std::vector<Float16_t>* rechit_x_;
    std::vector<Float16_t>* rechit_y_;
    std::vector<Float16_t>* rechit_z_;
    std::vector<bool>* rechit_noise_flag_;

    std::vector<G4double> AHCALLayerDistances;
    std::vector<VisHit*> AHCALHitsForVisualisation;
    int ahcalOffset;

    float time_cut;

    TFile* m_inputFileAHCAL;
    TTree* m_inputTreeAHCAL;
    std::map<std::string, TBranch*> ahcalBranches;

    int AHCAL_eventID;
    int AHCAL_Nhits;
    int ahc_hitI_[24*24*40];
    int ahc_hitJ_[24*24*40];
    int ahc_hitK_[24*24*40];
    float ahc_hitEnergy_[24*24*40];


//alignment correction
    std::vector<std::pair<float, float> > transverse_alignment_HGCal;    
};

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#endif

