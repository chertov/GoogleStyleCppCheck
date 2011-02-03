import os
from functools import partial

command = '.\\..\\cppstylecheck.py --verbose=0 --output=vs7 source.cpp'

print command
print
print 
os.system(command)
os.system('pause')
