import os
from functools import partial

command = '.\\..\\cppstylecheck.py --verbose=0 --output=vs7 Qt_OpenGL_without_warning\\GLThread.h'

#print command
os.system(command)
os.system('pause')
