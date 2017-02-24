# LIBTBX_SET_DISPATCHER_NAME phenix.xtriage
# LIBTBX_SET_DISPATCHER_NAME mmtbx.xtriage

from __future__ import division
from mmtbx.scaling import xtriage
import sys

if (__name__ == "__main__"):
  xtriage.run(args=sys.argv[1:])
