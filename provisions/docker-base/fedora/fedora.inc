#!/bin/bash
#title		:fedora.inc
#description	:Configuration for Docker/Base/Fedora/* images
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

# Fedora GNU/Linux
declare -gA distro_info;
distro_info['status']=false;
distro_info['family']='redhat';
distro_info['codename']='fedora';
distro_info['title']='Fedora';
distro_info['desc']='Docker/Base/Fedora';
distro_info['dir']='fedora';
distro_info['tags']='06,12,19';

#
# Distribution releases/tags
#

# Fedora 6 (zod)
declare -gA distro_tag_06;
distro_tag_06['status']=false;
distro_tag_06['version']='6';
distro_tag_06['codename']='zod';
distro_tag_06['title']='Fedora 6 (zod)';
distro_tag_06['desc']='Docker/Base/Fedora/6 (zod)';
distro_tag_06['url']='fedora:zod';
distro_tag_06['shell']='/bin/bash';
distro_tag_06['provision']=false;
distro_tag_06['provision_dir']='';
distro_tag_06['container']=false;
distro_tag_06['container_dir']='';
distro_tag_06['container_mnt']='';

# Fedora 12 (constantine)
declare -gA distro_tag_12;
distro_tag_12['status']=false;
distro_tag_12['version']='12';
distro_tag_12['codename']='constantine';
distro_tag_12['title']='Fedora 12 (constantine)';
distro_tag_12['desc']='Docker/Base/Fedora/12 (constantine)';
distro_tag_12['url']='fedora:constantine';
distro_tag_12['shell']='/bin/bash';
distro_tag_12['provision']=false;
distro_tag_12['provision_dir']='';
distro_tag_12['container']=false;
distro_tag_12['container_dir']='';
distro_tag_12['container_mnt']='';

# Fedora 19 (schrodinger)
declare -gA distro_tag_19;
distro_tag_19['status']=false;
distro_tag_19['version']='19';
distro_tag_19['codename']='schrodinger';
distro_tag_19['title']='Fedora 19 (schrodinger)';
distro_tag_19['desc']='Docker/Base/Fedora/19 (schrodinger)';
distro_tag_19['url']='fedora:schrodinger';
distro_tag_19['shell']='/bin/bash';
distro_tag_19['provision']=false;
distro_tag_19['provision_dir']='';
distro_tag_19['container']=false;
distro_tag_19['container_dir']='';
distro_tag_19['container_mnt']='';

