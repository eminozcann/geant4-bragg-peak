#include "SteppingAction.hh"
#include "G4Step.hh"
#include "G4AnalysisManager.hh"
#include "G4SystemOfUnits.hh"

void SteppingAction::UserSteppingAction(const G4Step* step) {
    auto volume = step->GetPreStepPoint()->GetTouchableHandle()->GetVolume();
    if (!volume || volume->GetLogicalVolume()->GetName() != "WaterLV") return;

    G4double edep = step->GetTotalEnergyDeposit();
    if (edep <= 0.) return;

    G4double zPos = step->GetPreStepPoint()->GetPosition().z();
    G4AnalysisManager::Instance()->FillH1(0, zPos, edep);
}
