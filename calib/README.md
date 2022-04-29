# README file for calib

Calibration files: 
The VMM3a slow control tool https://gitlab.cern.ch/mguth/VMM-software-RD51 can generate calibration files that modify the ADC values, the time measurements or the time walk of each channel. The ADC calibration ensures that all channels have the same response to the same charge. Uncorrected the inner channels of the VMM3a chips have a higher ADC value than the outer channels. The time calibration corrects the non-linear behaviour of the TDC and makes sure that all channels measure the same time e.g. for a test pulse. The behaviour of the ADC and TDC should be linear, hence the corrections for the ADC and time calibrations are linear. There is an offset and a slope correction for the ADC and the time. The time walk (dependency of the time measurement on the ADC) is not linear, the curve resembles an s-curve. The correction parameters are thus offset, scale, mean and sigma. Since the calibration is a property of a particular hybrid, the slow control stores these calibrations in one file per hybrid per calibration type. The tool create_calib_file.py can now be used to create a combined calibration file for a whole system of multiple hybrids. This combined calibration file can be loaded into vmm-sdat to correct the ADC and TDC values (see folder run). 

## Running the create_calib_file.py utility
The tool create_calib_file.py creates a calibration file for a whole system of multiple hybrids. The user has to specify the JSON mapping file that describes the system (mapping between hybrid, FEC and VMM), the name for the new combined system calibration file, the directory with the calibration files of the individual hybrids, and the  choice of calibrations (ADC, time, time walk). An example of a hybrid mapping file is in the directory. Further the user finds 4 hybrid ADC calibration files and 4 hybrid time calibration files in the directory. To create now a combined system calibration file, the user can type at the command line of a terminal:

> python create_calib_file.py hybrid_mapping.json  -c my_system_calib.json -a -t