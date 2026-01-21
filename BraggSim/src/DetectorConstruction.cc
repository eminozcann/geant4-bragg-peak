#include "DetectorConstruction.hh"
#include "G4NistManager.hh"
#include "G4Box.hh"
#include "G4LogicalVolume.hh"
#include "G4UserLimits.hh"
#include "G4PVPlacement.hh"
#include "G4SystemOfUnits.hh"

G4VPhysicalVolume* DetectorConstruction::Construct() {
    G4NistManager* nist = G4NistManager::Instance();
    G4Material* worldMat = nist->FindOrBuildMaterial("G4_AIR");
    G4Material* waterMat = nist->FindOrBuildMaterial("G4_WATER");

    G4Box* solidWorld = new G4Box("World", 0.5*m, 0.5*m, 0.5*m);
    G4LogicalVolume* logicWorld = new G4LogicalVolume(solidWorld, worldMat, "World");
    G4VPhysicalVolume* physWorld = new G4PVPlacement(0, G4ThreeVector(), logicWorld, "World", 0, false, 0, true);

    // 150 MeV proton suda yaklasik 16 cm gider. Kutu boyutunu buna gore ayarladik.
    G4Box* solidWater = new G4Box("WaterBox", 10*cm, 10*cm, 15*cm); 
    G4LogicalVolume* logicWater = new G4LogicalVolume(solidWater, waterMat, "WaterLV");
    G4UserLimits* stepLimit = new G4UserLimits(0.5 * mm);
    logicWater->SetUserLimits(stepLimit);
    
    new G4PVPlacement(0, G4ThreeVector(0,0,0), logicWater, "WaterPhys", logicWorld, false, 0, true);

    return physWorld;
}
