#!/bin/bash

inputDir="$1"

countDir=$(find "$inputDir" -type d | wc -l | xargs)
countFile=$(find "$inputDir" -not -type d | wc -l | xargs)

echo "There were $countDir directories."
echo "There were $countFile regular Files."