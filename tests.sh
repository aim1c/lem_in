#!/usr/bin/env bash


red=`tput setaf 1`
green=`tput setaf 2`
reset=`tput sgr0`

../cmake-build-debug/lem_in ../Lem-in-map/map/anil ||
echo "${green}DONE1${reset}"
../cmake-build-debug/lem_in ../Lem-in-map/map/big ||
echo "${green}DONE2${reset}"
../cmake-build-debug/lem_in ../Lem-in-map/map/g ||
echo "${green}DONE3${reset}"
../cmake-build-debug/lem_in ../Lem-in-map/map/map_git ||
echo "${green}DONE4${reset}"
../cmake-build-debug/lem_in ../Lem-in-map/map/map_git1 ||
echo "${green}DONE5${reset}"
../cmake-build-debug/lem_in ../Lem-in-map/map/map_git2 ||
echo "${green}DONE6${reset}"
../cmake-build-debug/lem_in ../Lem-in-map/map/map_git3 ||
echo "${green}DONE7${reset}"
../cmake-build-debug/lem_in ../Lem-in-map/map/map_offi ||
echo "${green}DONE8${reset}"
../cmake-build-debug/lem_in ../Lem-in-map/map/map_offi_custom ||
echo "${green}DONE9${reset}"
../cmake-build-debug/lem_in ../Lem-in-map/map/map_offi_no_way ||
echo "${green}DONE10${reset}"
../cmake-build-debug/lem_in ../Lem-in-map/map/map_offi_pipe_error ||
echo "${green}DONE11${reset}"
../cmake-build-debug/lem_in ../Lem-in-map/map/maptest   ||
echo "${green}DONE12${reset}"
../cmake-build-debug/lem_in ../Lem-in-map/map/norooms   ||
echo "${green}DONE13${reset}"
../cmake-build-debug/lem_in ../Lem-in-map/map/erreur/1 ||
echo "${green}DONE14${reset}"
../cmake-build-debug/lem_in ../Lem-in-map/map/erreur/2 ||
echo "${green}DONE15${reset}"
../cmake-build-debug/lem_in ../Lem-in-map/map/lucas/example ||
echo "${green}DONE16${reset}"
../cmake-build-debug/lem_in ../Lem-in-map/map/lucas/example2 ||
echo "${green}DONE17${reset}"
../cmake-build-debug/lem_in ../Lem-in-map/map/lucas/example3 ||
echo "${green}DONE18${reset}"
../cmake-build-debug/lem_in ../Lem-in-map/map/lucas/good_map ||
echo "${green}DONE19${reset}"
../cmake-build-debug/lem_in ../Lem-in-map/map/lucas/good_map_lot_of_room_without_pipe ||
echo "${green}DONE20${reset}"
../cmake-build-debug/lem_in ../Lem-in-map/map/lucas/good_map_no_com ||
echo "${green}DONE21${reset}"
../cmake-build-debug/lem_in ../Lem-in-map/map/lucas/good_map_one_room_without_pipe ||
echo "${green}DONE22${reset}"
../cmake-build-debug/lem_in ../Lem-in-map/map/lucas/good_map_with_com_between_room_and_pipe ||
echo "${green}DONE23${reset}"
../cmake-build-debug/lem_in ../Lem-in-map/map/lucas/goodmap_aaa ||
echo "${green}DONE24${reset}"
../cmake-build-debug/lem_in ../Lem-in-map/map/lucas/goodmap_end_next_to_start ||
echo "${green}DONE25${reset}"
../cmake-build-debug/lem_in ../Lem-in-map/map/lucas/goodmap_fourmi.map ||
echo "${green}DONE26${reset}"
../cmake-build-debug/lem_in ../Lem-in-map/map/lucas/goodmap_jjj
echo "${green}DONE27${reset}"
../cmake-build-debug/lem_in ../Lem-in-map/map/lucas/wrongmap_multiple_start
echo "${green}DONE28${reset}"