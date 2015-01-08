#!/bin/bash
#title		 :centos.inc
#description	 :Configuration for Docker/Base/CentOS/* images
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

# CentOS GNU/Linux
declare -gA distro_info;
distro_info['status']=true;
distro_info['family']='redhat';
distro_info['codename']='centos';
distro_info['title']='CentOS';
distro_info['desc']='Docker/Base/CentOS';
distro_info['dir']='centos';
distro_info['tags']='05,06,07';

#
# Distribution releases/tags
#

# CentOS 5 (centos5)
declare -gA distro_tag_05;
distro_tag_05['status']=true;
distro_tag_05['version']='5';
distro_tag_05['codename']='centos5';
distro_tag_05['title']='CentOS 5 (centos5)';
distro_tag_05['desc']='Docker/Base/CentOS/5 (centos5)';
distro_tag_05['url']='centos:centos5';
distro_tag_05['shell']='/bin/bash';
distro_tag_05['provision']=false;
distro_tag_05['provision_dir']='';
distro_tag_05['container']=false;
distro_tag_05['container_dir']='';
distro_tag_05['container_mnt']='';

# CentOS 6 (centos6)
declare -gA distro_tag_06;
distro_tag_06['status']=true;
distro_tag_06['version']='6';
distro_tag_06['codename']='centos6';
distro_tag_06['title']='CentOS 6 (centos6)';
distro_tag_06['desc']='Docker/Base/CentOS/6 (centos6)';
distro_tag_06['url']='centos:centos6';
distro_tag_06['shell']='/bin/bash';
distro_tag_06['provision']=false;
distro_tag_06['provision_dir']='';
distro_tag_06['container']=false;
distro_tag_06['container_dir']='';
distro_tag_06['container_mnt']='';

# CentOS 7 (centos7)
declare -gA distro_tag_07;
distro_tag_07['status']=true;
distro_tag_07['version']='7';
distro_tag_07['codename']='centos7';
distro_tag_07['title']='CentOS 7 (centos7)';
distro_tag_07['desc']='Docker/Base/CentOS/7 (centos7)';
distro_tag_07['url']='centos:centos7';
distro_tag_07['shell']='/bin/bash';
distro_tag_07['provision']=false;
distro_tag_07['provision_dir']='';
distro_tag_07['container']=false;
distro_tag_07['container_dir']='';
distro_tag_07['container_mnt']='';

