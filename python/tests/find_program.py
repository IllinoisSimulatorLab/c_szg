import os
import sys

def find_program(program):
    if sys.platform == 'win32':
        program += '.exe'
    def is_exe(fpath):
        return os.path.isfile(fpath) and os.access(fpath, os.X_OK)

    fpath, fname = os.path.split(program)
    if fpath:
        if is_exe(program):
            return program
    else:
        for path in os.environ["PATH"].split(os.pathsep):
            path = path.strip('"')
            exe_file = os.path.join(path, program)
            if is_exe(exe_file):
                return exe_file

    return None


if __name__=='__main__':
    print "Is szgserver on path:", find_program('szgserver')
    print "Is foobar on path:", find_program('foobar')
