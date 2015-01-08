#!/bin/bash
#title           :config.inc
#description     :Main configuration file.
#author		 :lpalgarvio <"lp.algarvio@gmail.com">
#date            :20150108
#version         :0.9
#usage		 :-
#notes		 :-
#bash_version    :4.2
#==============================================================================

#
# Global flags
#
declare -g debug=false;

#
# Default options
#
declare -g opts_all=false;
declare -g opts_force=false;

#
# System paths
#
declare -g script_ext='inc';
declare -g includes_path='includes';
declare -g provisions_path='provisions';
declare -g containers_path='containers';

#
# Includes
#
declare -g functions_inc="${includes_path}/functions.${script_ext}";
declare -g docker_inc="${includes_path}/docker.${script_ext}";

#
# Provisions
#
declare -gA provision_info;
provision_info['provisions']='01,02';

# ...
declare -gA provision_01;
provision_01['status']=true;
provision_01['codename']='docker-base';
provision_01['title']='Docker/Base';
provision_01['desc']='Docker/Base';
provision_01['provisioner']='docker';
provision_01['dir']='docker-base';

# solict/provisionous-docker-puppet
declare -gA provision_02;
provision_02['status']=true;
provision_02['codename']='docker-puppet';
provision_02['title']='Docker/Puppet';
provision_02['desc']='Docker/Puppet';
provision_02['provisioner']='docker';
provision_02['dir']='docker-puppet';

