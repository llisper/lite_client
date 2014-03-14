#!/usr/local/bin/python
import os
import sys
import os.path

config_list = [
    '<?xml version="1.0" encoding="utf-8"?>\n',
    '<core>\n']

base = os.path.normpath(sys.argv[1])
if not os.path.exists(base):
  print '{0} is not exists'.format(base)
  sys.exit(-1)

def dir_walk(arg, dirname, names):
  droid_config = os.path.join(dirname, 'droid_config')
  if os.path.exists(droid_config):
    with open(droid_config, 'r') as f:
      config_list.append('  ' + f.readline())

os.path.walk(base, dir_walk, None)
config_list.append('</core>')

with open(os.path.join(base, 'core.xml'), 'w') as f:
  f.writelines(config_list)
