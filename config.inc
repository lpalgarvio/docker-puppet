#!/bin/bash
#title           :config.inc
#description     :Main configuration file.
#author		 :lpalgarvio <"lp.algarvio@gmail.com">
#date            :20150105
#version         :0.6
#usage		 :-
#notes		 :-
#bash_version    :4.2
#==============================================================================

#
# Global parameters
#
declare -g debug=true;

#
# Global paths
#
declare -g script_ext='inc';
declare -g common_path='common';
declare -g provisioners_path='provisioners';
declare -g provisions_path='provisions';

#
# Paths for includes
#
declare -g functions_inc="${common_path}/functions.${script_ext}";

#
# Paths for provisioners
#
declare -g docker_inc="${provisioners_path}/docker.${script_ext}";

#
# Paths for provisions
#
declare -g docker_base_path="${provisions_path}/docker-base";
declare -g docker_puppet_path="${provisions_path}/docker-puppet";

