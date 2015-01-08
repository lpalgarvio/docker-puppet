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
provision_info['provisions']='01,02,03';

# <official-docker-base>
declare -gA provision_01;
provision_01['status']=true;
provision_01['codename']='official-docker-base';
provision_01['title']='Official Docker/Base';
provision_01['desc']='Official Docker/Base';
provision_01['provisioner']='docker';
provision_01['dir']='official-docker-base';

# solict/provisionous-docker-puppet
declare -gA provision_02;
provision_02['status']=true;
provision_02['codename']='provisionous-docker-puppet';
provision_02['title']='Provisionous Docker/Puppet';
provision_02['desc']='Provisionous Docker/Puppet';
provision_02['provisioner']='docker';
provision_02['dir']='provisionous-docker-puppet';

# local/custom-docker-puppet
declare -gA provision_03;
provision_03['status']=true;
provision_03['codename']='custom-docker-puppet';
provision_03['title']='Custom Docker/Puppet';
provision_03['desc']='Custom Docker/Puppet';
provision_03['provisioner']='docker';
provision_03['dir']='custom-docker-puppet';

