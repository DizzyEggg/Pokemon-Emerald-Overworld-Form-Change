#!/usr/bin/env python

import os
import subprocess
import sys
import shutil
import binascii
import textwrap
import sys
import argparse

if sys.version_info < (3, 4):
        print('Python 3.4 or later is required.')
        sys.exit(1)

# Parse arguments
parser = argparse.ArgumentParser()
parser.add_argument('--base_script', metavar='file', 
                    help='Base script', default='rotom_script_base.rbc')
parser.add_argument('--result_script', metavar='file', 
                    help='The resultant XSE script', default='rotom_result_script.rbc')
args = parser.parse_args()

table={}

with open('offsets.txt','r') as fin:
        for line in fin:
                pair = line.split()
                key=pair[0];
                key=key[:-1];
                value=pair[1];
                value=value[2:]
                table[key]=value

with open(args.base_script, 'r') as oldlines:
        fout=open(args.result_script, 'w')
        for line in oldlines:
                if line.startswith('callasm ##'):
                        line='callasm 0x8' + table[line[10:-1]]+'\n'
                fout.write(line)

