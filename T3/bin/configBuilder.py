#!/usr/bin/env python

import sys
import argparse
import subprocess
from re import sub
from os import getenv
from PandaCore.Tools.Misc import logger
from PandaCore.Tools.job_management import DataSample,convert_catalog

workdir = getenv('SUBMIT_WORKDIR')
parser = argparse.ArgumentParser(description='convert configuration')
parser.add_argument('--infile',type=str,default=None)
parser.add_argument('--outfile',type=str,default=None)
parser.add_argument('--nfiles',type=int,default=None)
args = parser.parse_args()

fin = open(args.infile)
samples = convert_catalog(list(fin),as_dict=True)

fout = open(args.outfile,'w')
keys = sorted(samples)
counter=0
for k in keys:
	sample = samples[k]
	configs = sample.get_config(args.nfiles,suffix='_%i')
	for c in configs:
		fout.write(c%(counter,counter))
		counter += 1

logger.info('configBuilder.py','Submission will have %i jobs'%(counter))

fout.close()
