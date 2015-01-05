#!/bin/bash
#title		:debian.inc
#description	:Configuration for Docker/Base/Debian/* images
#author		:lpalgarvio <'lp.algarvio@gmail.com'>
#date		:20150105
#version	:0.6
#usage		:-
#notes		:-
#bash_version	:4.2
#==============================================================================

#
# Distribution information
#

# Debian GNU/Linux
declare -gA distro_info;
distro_info['status']=true;
distro_info['family']='debian';
distro_info['codename']='debian';
distro_info['title']='Debian';
distro_info['desc']='Docker/Base/Debian';
distro_info['dir']='debian';
distro_info['tags']='06,07,08';

#
# Distribution releases/tags
#

# Debian 6 (squeeze)
declare -gA distro_tag_06;
distro_tag_06['status']=true;
distro_tag_06['version']='6';
distro_tag_06['codename']='squeeze';
distro_tag_06['title']='Debian 6 (squeeze)';
distro_tag_06['desc']='Docker/Base/Debian/6 (squeeze)';
distro_tag_06['url']='debian:squeeze';
distro_tag_06['dir']='';

# Debian 7 (wheezy)
declare -gA distro_tag_07;
distro_tag_07['status']=true;
distro_tag_07['version']='7';
distro_tag_07['codename']='wheezy';
distro_tag_07['title']='Debian 7 (wheezy)';
distro_tag_07['desc']='Docker/Base/Debian/7 (wheezy)';
distro_tag_07['url']='debian:wheezy';
distro_tag_07['dir']='';

# Debian 8 (jessie)
declare -gA distro_tag_08;
distro_tag_08['status']=true;
distro_tag_08['version']='8';
distro_tag_08['codename']='jessie';
distro_tag_08['title']='Debian 8 (jessie)';
distro_tag_08['desc']='Docker/Base/Debian/8 (jessie)';
distro_tag_08['url']='debian:jessie';
distro_tag_08['dir']='';

