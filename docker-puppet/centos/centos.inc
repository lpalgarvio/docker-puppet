#!/bin/bash
#title		:centos.inc
#description	:Configuration for Docker/Puppet/CentOS/* images
#author		:lpalgarvio <'lp.algarvio@gmail.com'>
#date		:20141231
#version	:0.5
#usage		:-
#notes		:-
#bash_version	:4.2
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
distro_info['desc']='Docker/Puppet/CentOS';
distro_info['path']='centos';
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
distro_tag_05['desc']='Docker/Puppet/CentOS/5 (centos5)';
distro_tag_05['url']='solict/provisionous-puppet-centos:centos5';
distro_tag_05['path']='05_centos5';

# CentOS 6 (centos6)
declare -gA distro_tag_06;
distro_tag_06['status']=true;
distro_tag_06['version']='6';
distro_tag_06['codename']='centos6';
distro_tag_06['title']='CentOS 6 (centos6)';
distro_tag_06['desc']='Docker/Puppet/CentOS/6 (centos6)';
distro_tag_06['url']='solict/provisionous-puppet-centos:centos6';
distro_tag_06['path']='06_centos6';

# CentOS 7 (centos7)
declare -gA distro_tag_07;
distro_tag_07['status']=true;
distro_tag_07['version']='7';
distro_tag_07['codename']='centos7';
distro_tag_07['title']='CentOS 7 (centos7)';
distro_tag_07['desc']='Docker/Puppet/CentOS/7 (centos7)';
distro_tag_07['url']='solict/provisionous-puppet-centos:centos7';
distro_tag_07['path']='07_centos7';

