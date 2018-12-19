#!/bin/bash

echo /tmp/core | tee /proc/sys/kernel/core_pattern
ulimit -c unlimited

# if we're not using PaaS mode then start smoked traditionally with sv to control it
if [[ ! "$USE_PAAS" ]]; then
  mkdir -p /etc/service/smoked
  cp /usr/local/bin/smoke-sv-run.sh /etc/service/smoked/run
  chmod +x /etc/service/smoked/run
  runsv /etc/service/smoked
else
  /usr/local/bin/startpaassmoked.sh
fi
