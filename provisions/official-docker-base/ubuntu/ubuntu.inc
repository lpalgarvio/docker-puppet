#!/bin/bash
#title		 :ubuntu.inc
#description	 :Configuration for Official Docker/Base/Ubuntu/* images
#author		 :lpalgarvio <'lp.algarvio@gmail.com'>
#date		 :20150108
#version         :0.9
#usage		 :-
#notes		 :-
#bash_version	 :4.2
#==============================================================================

#
# Distribution information
#

# Ubuntu GNU/Linux
declare -gA distro_info;
distro_info['status']=true;
distro_info['family']='debian';
distro_info['codename']='ubuntu';
distro_info['title']='Ubuntu';
distro_info['desc']='Official Docker/Base/Ubuntu';
distro_info['dir']='ubuntu';
distro_info['tags']='1004,1204,1404';

#
# Distribution releases/tags
#

# Ubuntu 10.04 (lucid)
declare -gA distro_tag_1004;
distro_tag_1004['status']=true;
distro_tag_1004['version']='10.04';
distro_tag_1004['codename']='lucid';
distro_tag_1004['title']='Ubuntu 10.04 (lucid)';
distro_tag_1004['desc']='Official Docker/Base/Ubuntu/10.04 (lucid)';
distro_tag_1004['url']='ubuntu:lucid';
distro_tag_1004['shell']='/bin/bash';
distro_tag_1004['provision']=false;
distro_tag_1004['provision_dir']='';
distro_tag_1004['container']=false;
distro_tag_1004['container_dir']='';
distro_tag_1004['container_mnt']='';

# Ubuntu 12.04 (precise)
declare -gA distro_tag_1204;
distro_tag_1204['status']=true;
distro_tag_1204['version']='12.04';
distro_tag_1204['codename']='precise';
distro_tag_1204['title']='Ubuntu 12.04 (precise)';
distro_tag_1204['desc']='Official Docker/Base/Ubuntu/12.04 (precise)';
distro_tag_1204['url']='ubuntu:precise';
distro_tag_1204['shell']='/bin/bash';
distro_tag_1204['provision']=false;
distro_tag_1204['provision_dir']='';
distro_tag_1204['container']=false;
distro_tag_1204['container_dir']='';
distro_tag_1204['container_mnt']='';

# Ubuntu 14.04 (trusty)
declare -gA distro_tag_1404;
distro_tag_1404['status']=true;
distro_tag_1404['version']='14.04';
distro_tag_1404['codename']='trusty';
distro_tag_1404['title']='Ubuntu 14.04 (trusty)';
distro_tag_1404['desc']='Official Docker/Base/Ubuntu/14.04 (trusty)';
distro_tag_1404['url']='ubuntu:trusty';
distro_tag_1404['shell']='/bin/bash';
distro_tag_1404['provision']=false;
distro_tag_1404['provision_dir']='';
distro_tag_1404['container']=false;
distro_tag_1404['container_dir']='';
distro_tag_1404['container_mnt']='';

