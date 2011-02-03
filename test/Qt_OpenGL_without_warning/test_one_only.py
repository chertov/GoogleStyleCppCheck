import os
from functools import partial

path = '.\\'
command = '.\\..\\..\\run.py --verbose=0 --output=vs7 GLThread.h'

#print command
os.system(command)
os.system('pause')
