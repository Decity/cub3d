#!/bin/bash

for map in maps/fail/*.cub; do
	echo "===== $map ====="
	valgrind ./cub3D "$map"
	echo
done
