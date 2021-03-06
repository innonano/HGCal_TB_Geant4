# Implemented Geometries
Geometries and the corresponding material are common for both the event display and the standalone simulation. The source code is located in ```/common/``` and it is compiled together with either program.

## Material
All materials are defined globally and their visualisation attributes are set in ```/common/src/materials.cc```. Pointers to the logical volumes are stored within an ```std::map<std::string, G4LogicalVolume*>``` map which is available to both programs. 

### Sensitive material
Geant4 steps within the volume of placed sensitive material are tracked and serve as input for the computation of calorimeter hits. For that, ionizing and non-ionizing energy contributions within each sensitive volume are summed and written to a file for each shower. The following materials are defined as sensitive.

#### Hexagoal HGC silicon diodes
Defined in ```void HGCalTBMaterials::defineSiWaferAndCells()```.

* **SiCell**: Hexagon with side length of 0.6496345 cm and thickness of 0.3 mm, filled with silicon. This is the model for a full ~1cm2 HGC silicon diode.
* **SiWafer**: Hexagon with side length of 11x 0.6496345 cm and thickness of 0.3 mm, filled with air. "SiCell" volumes are placed into this wafer making a 6'' HGC prototype silicon sensor made from full hexagonal diodes only.

##### AHCAL scintillator tiles
Defined in ```void HGCalTBMaterials::defineAHCALSiPM()```.

* **AHCAL_SiPM**: Rectangular box with x-y length of 3 cm and thickness of 5.4 mm filled with Polystyrene. This is the model for a CALICE AHCAL scintillator tile.
* **AHCAL\_SiPM\_2x2HUB**: Rectangular box with x-y length of 24x3 cm and thickness of 5.4 mm filled with air. "AHCAL_SiPM" volumes are placed into the hub making a full sensitive layer of the CALICE AHCAL technical prototype (2018).

### Passive material
Passive material contributes to the shower evolution but any information on deposited energy therein is not tracked.
#### HGCal baseplates
Defined in ```void HGCalTBMaterials::defineHGCalBaseplates()```.

* **CuW_baseplate**: Hexagonal plate with same size as the "SiWafer" and a thickness of 1.2 mm. Filled with 60% copper and 40% tungsten.
* **Cu_baseplate**: Hexagonal plate with same size as the "SiWafer" and a thickness of 1.2 mm. Filled with copper.
* **PCB**: Hexagonal plate with same size as the "SiWafer" and a thickness of 1.2 mm. Filled with carbon.
* **Kapton_layer**: Hexagonal plate with same size as the "SiWafer" and a thickness of 0.05 mm. Filled with G4\_KAPTON.

#### HGCal cases
Defined in ```void HGCalTBMaterials::defineHGCalCases()```.

* **Al_case**: Rectangular box with x-y length of 40 cm and thickness of 2.6 mm filled with aluminium.
* **Steel_case**: Rectangular box with x-y length of 60 cm and thickness of 2.6 mm filled with stainless steel.

#### HGCal EE absorbers
Defined in ```void HGCalTBMaterials::defineHGCalEEAbsorbers()```.

* **Pb_absorber\_EE**: Rectangular box with x-y length of 30 cm and thickness of 4.9 mm filled with lead.
* **Cu_absorber\_EE**: Rectangular box with x-y length of 30 cm and thickness of 6.0 mm filled with copper.
* **W_absorber\_EE**: Rectangular box with x-y length of 30 cm and thickness of 2.8 mm filled with tungsten.
* **W\_2mm\_absorber\_EE_DESY2018**: Rectangular box with x-y length of 15 cm and thickness of 2.0 mm filled with tungsten.
* **W\_4mm\_absorber\_EE_DESY2018**: Rectangular box with x-y length of 15 cm and thickness of 4.0 mm filled with tungsten.

#### HGCal FH absorbers
Defined in ```void HGCalTBMaterials::defineHGCalFHAbsorbers()```.

* **Cu_absorber\_FH**: Rectangular box with x-y length of 50 cm and thickness of 6.0 mm filled with copper.
* **Fe_absorber\_FH**: Rectangular box with x-y length of 50 cm and thickness of 41.0 mm filled with stainless steel.

#### AHCAL absorbers
Defined in ```void HGCalTBMaterials::defineAHCALAbsorbers()```.

* **Al_absorber\_AHCAL**": Rectangular box with x-y length of 72 cm and thickness of 1.0 mm filled with aluminium.
* **PCB_AHCAL**": Rectangular box with x-y length of 72 cm and thickness of 1.2 mm filled with carbon.
* **Fe\_absorber_AHCAL**": Rectangular box with x-length of 80.8 cm, y-length of 65.7 cm and thickness of 17.0 mm filled with stainless steel.

#### Beam line elements
Defined in ```void HGCalTBMaterials::defineBeamLineElements()```.

* **Scintillator**": 10x10x1 cm3 box filled with carbon.
* **MCP**": Disk with radius of 2 cm and a thickness of 10.0 mm. Filled with quartz.
* **Al_chip**": 1x1x0.2 cm3 box filled with alumnium.
* **DWC**": 10x10x1 cm3 box filled with glas. Inside cavity with 2mm wall thickness is filled with argon.
* **DATURA_full**": 10x10x1.5 cm3 box with a 2x1 cm2 central window filled with alumnium.

#### HERD calorimeter
In October 2018, the HGCal prototype was tested with parasitic beam during a test of the HERD collaboration in the same beam line. A simplied model of its calorimeter is defined in ```void HGCalTBMaterials::defineHERDCalorimeter()```.


## Configurations
The subsequent sequence of placement of the geometries is defined for different calorimeter configurations.
Within the event display and the standalone simulation, defined materials are stacked such that their origin is positioned on the beam axis and their coordinate system is aligned with the global one. Shifts or rotations with respect to that coordinate system are not supported at this point.

### Special arrangements
Exceptions to this linear stacking are possible using the following postfixes:

* **\_DAISY**: This arranges the geometry in a manner identical to how the silicon modules in the FH layers during the October 2018 beam tests were placed. Only "SiWafers" are supported.
* **\_SUMMER2017TRIPLET**: This arranges the geometry in a manner identical to how the silicon modules in the FH layers during the July 2017 beam tests were placed. Only "SiWafers" are supported.
* **_rot30**: A global rotation of the geometry in x-y by 30 deg. is applied.


### !Important Disclaimer!
**Geometries defined below are motivated by the tested HGC calorimeter geometries in the years 2017-18. However, nothing more than a resemblance is guaranteed at this point. A detailed comparison of results from this simulation to data is highly deprecated!**

  
### Summer/Fall 2017 (CERN, H2)
* **Indexes 1 and 2** - ```/common/src/config1_2_Summer2017.cc```: 2 silicon layers in EE, 4 silicon layers in FH.
* Index 3 - ```/common/src/config3_September2017.cc```: 7 silicon layers in EE, 10 silicon layers in FH.

### March 2018 (DESY, T21)
* **Index 15** - ```/common/src/config_DESY2018_42.cc```: 1 silicon module in between the DATURA arms, 2 silicon modules behind 4x 4mm tungsten plates downstream.

### June 2018 (CERN, H2)
* **Indexes 17 to 21** -```/common/src/configs17To21_June2018.cc``` - indexes 17-21: 28-layer fully equipped EE HGC prototype.

### October 2018 (CERN, H2)
* **Index 22** - ```/common/src/config22_October2018_1.cc```: 28 silicon layers in EE, 12 layers in FH with first nine including daisy configurations of the silicon modules. 
* **Index 23** - ```/common/src/config23_October2018_2.cc```: 28 silicon layers in EE, 11 layers in FH with last nine including daisy configurations of the silicon modules. 
* **Index 24** - ```/common/src/config24_October2018_3.cc```: 8 silicon layers in EE, 12 layers in FH with all including daisy configurations of the silicon modules. 
* **Index 25** - ```/common/src/config24_October2018_3_parasitic.cc```: 8 silicon layers in EE, 12 layers in FH with all including daisy configurations of the silicon modules. The HERD calorimeter model is placed upstream in the beam line with respect to the HGC calorimeter prototype model.

### Test configurations
A few extra configuratons are defined which may serve as reference on how to define further geometries. The implementation can be found in: ```/common/src/test_configs.cc```.

* **Index 100** - One layer of silicon.
* **Index 101** - EE with 14 cassettes a 2 silicon modules per cassettes. These are spaced with equal distance with respect to each other
* **Index 102** - One layer of silicon placed behind 3x 4mm of tungsten. In addition, an alumnium chip is placed directly in front of the silicon module PCB.

## Adding a new geometry to the simulation
A few steps need to be followed in order to add a new custom-defined geometry to the framework.

* In ```/common/src/test_configs.cc```and ```/common/include/test_configs.hh``` define a new function with the same signature as the already existing ones.
* Define the view point, i.e. the point to which the visualisation tool will set its initial focus. The beam line extends from -20m to +20m.
* Define a sequence of material placement by appending to the ```dz_map``` object. The first argument is a string identifying the instance of the corresponding logical volume. Ensure that the referred logical volume exists, otherwise the program will abort during execution. The second argument represents the spacing to the previously stacked material.
* Add a call referring to the new function in the ```void DetectorConstruction::SelectConfiguration(G4int val)``` member of the ```DetectorConstruction.cc``` found in the ```/simulation/src``` directory. Ensure that there is no double definition of indices.
