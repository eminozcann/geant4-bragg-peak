# Geant4 Simulation: Bragg Peak vs. Gamma Attenuation

This project is a Geant4 simulation designed to analyze and compare the energy deposition profiles of charged particles (Protons) and neutral particles (Gamma Rays) in a water phantom.

Main Objective: To demonstrate the physical basis of particle therapy by simulating the Bragg Peak characteristic of protons (which spares healthy tissue) versus the exponential attenuation of Gamma rays used in conventional radiotherapy.

Project Structure (Branches)

This repository contains two different experimental setups located in separate branches. You can switch between them to observe different physical phenomena:

| Branch Name | Particle Type | Energy | Physical Outcome |
| :--- | :--- | :--- | :--- |
| `main` | Proton ($p^+$) | 150 MeV | Bragg Peak: Energy is deposited primarily at a specific depth (~16 cm). |
| `gama-deneyi` | Gamma ($\gamma$) | 2 MeV | Exponential Decay: Energy decreases continuously with depth (Beer-Lambert Law). |

 Technical Specifications
* Geometry: $20 \times 20 \times 30$ cm Water Phantom.
* Physics List: `QGSP_BIC_EMY` (Optimized for medical physics and electromagnetic interactions).
* Precision: Implemented `G4StepLimiterPhysics` with a **0.5 mm** step limit for high-resolution Bragg Peak visualization.
* Output: ROOT format (`BraggOutput.root`) for data analysis.

# Installation and Execution

# 1. Clone and Build
```bash
git clone [https://github.com/eminozcann/geant4-bragg-peak.git](https://github.com/eminozcann/geant4-bragg-peak.git)
cd geant4-bragg-peak
mkdir build && cd build
cmake ..
make -j4

./BraggSim
# In the GUI session:
/run/beamOn 1000

git checkout gama-deneyi
make -j4  # Re-compilation is required after switching branches
./BraggSim
# High statistics recommended for Gamma:
/run/beamOn 100000
