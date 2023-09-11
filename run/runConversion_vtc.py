#!/usr/bin/python
import os
import subprocess
import re
import sys
	
try:	
	args = ['../build/convertFile', '-f', 'example_vtc.pcapng', '-vmm', '[[0,0,0,0],[0,1,0,1]]',
'-axis', '[[0,0],0],[[0,1],0]', '-bc', '40', '-tac', '60', '-th','0', '-cs','3', '-ccs', '20', '-dt', '5000', '-mst', '1', '-spc', '100000', '-dp', '250000', '-coin', 'center-of-masss', '-crl', '0.1', '-cru', '10', '-save', '[[0],[0],[0]]', '-json','0', '-algo', '6', '-info', 'EXAMPLE_VTC', '-df', 'VTC']	
	subprocess.call(args)


except OSError:
	pass




