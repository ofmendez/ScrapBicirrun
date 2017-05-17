#!/bin/bash
timestamp() {
  date +"%D , %T"
}
SCRIPT="$(dirname "$0")"
cd $SCRIPT
# wget --mirror --random-wait -R gif,jpg,pdf,png,html,js,ico http://bicirrun.bogota.unal.edu.co/existencias.php
wget -nv --mirror --random-wait -A existencias.php http://bicirrun.bogota.unal.edu.co/existencias.php
timestamp >>RawData.txt
grep -o ">[0-9]* bicicletas" ./bicirrun.bogota.unal.edu.co/existencias.php >> RawData.txt
./fileFormater
rm RawData.txt
rm -r bicirrun.bogota.unal.edu.co