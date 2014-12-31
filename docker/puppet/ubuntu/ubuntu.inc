#!/bin/bash
#title		:ubuntu.inc
#description	:Configuration for Docker/Puppet/Ubuntu/* images
#author		:lpalgarvio <"lp.algarvio@gmail.com">
#date		:20141231
#version	:0.5
#usage		:-
#notes		:-
#bash_version	:4.1.5(1)-release
#==============================================================================

#
# Distribution information
#

# Ubuntu GNU/Linux
declare -A distro_info;
distro_info['status']=true;
distro_info['family']='debian';
distro_info['codename']='ubuntu';
distro_info['title']='Ubuntu';
distro_info['desc']='Docker/Puppet/Ubuntu';
distro_info['path']='ubuntu';
distro_info['tags']='10_04,12_04,14_04';

#
# Distribution releases/tags
#

# Ubuntu 10.04 (lucid)
declare -A distro_tag_10_04;
distro_tag_10_04['status']=true;
distro_tag_10_04['version']='10.04';
distro_tag_10_04['codename']='lucid';
distro_tag_10_04['title']='Ubuntu 10.04 (lucid)';
distro_tag_10_04['desc']='Docker/Puppet/Ubuntu/10.04 (lucid)';
distro_tag_10_04['url']="solict/provisionous-puppet-ubuntu:lucid";
distro_tag_10_04['path']='10.04_lucid';

# Ubuntu 12.04 (precise)
declare -A distro_tag_12_04;
distro_tag_12_04['status']=true;
distro_tag_12_04['version']='12.04';
distro_tag_12_04['codename']='precise';
distro_tag_12_04['title']='Ubuntu 12.04 (precise)';
distro_tag_12_04['desc']='Docker/Puppet/Ubuntu/12.04 (precise)';
distro_tag_12_04['url']="solict/provisionous-puppet-ubuntu:precise";
distro_tag_12_04['path']='12.04_precise';

# Ubuntu 14.04 (trusty)
declare -A distro_tag_14_04;
distro_tag_14_04['status']=true;
distro_tag_14_04['version']='14.04';
distro_tag_14_04['codename']='trusty';
distro_tag_14_04['title']='Ubuntu 14.04 (trusty)';
distro_tag_14_04['desc']='Docker/Puppet/Ubuntu/14.04 (trusty)';
distro_tag_14_04['url']="solict/provisionous-puppet-ubuntu:trusty";
distro_tag_14_04['path']='14.04_trusty';
