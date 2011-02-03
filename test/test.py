import os
from functools import partial

path = '.\\Qt_OpenGL_without_warning'
command = '.\\..\\run.py --verbose=0 --output=vs7'

join = partial(os.path.join, path)
filelist = [f for f in map(join, os.listdir(path)) if os.path.isfile(f)]
for file in filelist:
    command += ' ' + file

print command
print
print 
os.system(command)
os.system('pause')
