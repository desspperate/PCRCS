import subprocess


subprocess.call(['gcc',
                 '-o',
                 'test',
                 '-g',
                 'test.c',
                ])


subprocess.call(['./test'])