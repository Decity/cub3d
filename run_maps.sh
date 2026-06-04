#!/bin/bash

for map in maps/fail/*.cub; do
	echo "===== $map ====="
	./cub3D "$map"
	echo
done
