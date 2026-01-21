#include "RunAction.hh"

void RunAction::BeginOfRunAction(const G4Run*) {
    auto analysisManager = G4AnalysisManager::Instance();
    analysisManager->OpenFile("BraggOutput.root");
    // ID=0, BraggPeak, 300 bin, -150mm ile +150mm arasi
    analysisManager->CreateH1("BraggPeak", "Energy Deposition vs Z", 300, -150., 150.);
}

void RunAction::EndOfRunAction(const G4Run*) {
    auto analysisManager = G4AnalysisManager::Instance();
    analysisManager->Write();
    analysisManager->CloseFile();
}
