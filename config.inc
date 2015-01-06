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
# Global flags
#
declare -g debug=false;

#
# Global options
#
declare -g opts_all=false;
declare -g opts_force=false;

#
# Global paths
#
declare -g script_ext='inc';
declare -g common_path='common';
declare -g provisioners_path='provisioners';
declare -g provisions_path='provisions';
declare -g containers_path='containers';

#
# Paths for includes
#
declare -g functions_inc="${common_path}/functions.${script_ext}";
declare -g docker_inc="${provisioners_path}/docker.${script_ext}";

#
# Paths for Docker/Base
#
declare -g provision_docker_base_path="${provisions_path}/docker-base";
declare -g container_docker_base_path="${containers_path}/docker-base";

#
# Paths for Docker/Puppet
#
declare -g provision_docker_puppet_path="${provisions_path}/docker-puppet";
declare -g container_docker_puppet_path="${containers_path}/docker-puppet";

