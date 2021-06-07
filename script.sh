#!/bin/bash

alpr -c eu -n 1 --motion resources/${1}>${2} 2>err

exit 0
