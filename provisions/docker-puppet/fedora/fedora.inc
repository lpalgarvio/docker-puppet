#!/bin/bash
#title		:fedora.inc
#description	:Configuration for Docker/Puppet/Fedora/* images
#author		:lpalgarvio <'lp.algarvio@gmail.com'>
#date		:20150105
#version	:0.5
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
distro_info['desc']='Docker/Puppet/Fedora';
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
distro_tag_06['desc']='Docker/Puppet/Fedora/6 (zod)';
distro_tag_06['url']='solict/provisionous-puppet-fedora:zod';
distro_tag_06['shell']='/bin/bash';
distro_tag_06['provision']=true;
distro_tag_06['provision_dir']='06_zod';
distro_tag_06['container']=true;
distro_tag_06['container_dir']='06_zod';
distro_tag_06['container_mnt']='/srv';

# Fedora 12 (constantine)
declare -gA distro_tag_12;
distro_tag_12['status']=false;
distro_tag_12['version']='12';
distro_tag_12['codename']='constantine';
distro_tag_12['title']='Fedora 12 (constantine)';
distro_tag_12['desc']='Docker/Puppet/Fedora/12 (constantine)';
distro_tag_12['url']='solict/provisionous-puppet-fedora:constantine';
distro_tag_12['shell']='/bin/bash';
distro_tag_12['provision']=true;
distro_tag_12['provision_dir']='12_constantine';
distro_tag_12['container']=true;
distro_tag_12['container_dir']='12_constantine';
distro_tag_12['container_mnt']='/srv';

# Fedora 19 (schrodinger)
declare -gA distro_tag_19;
distro_tag_19['status']=false;
distro_tag_19['version']='19';
distro_tag_19['codename']='schrodinger';
distro_tag_19['title']='Fedora 19 (schrodinger)';
distro_tag_19['desc']='Docker/Puppet/Fedora/19 (schrodinger)';
distro_tag_19['url']='solict/provisionous-puppet-fedora:schrodinger';
distro_tag_19['shell']='/bin/bash';
distro_tag_19['provision']=true;
distro_tag_19['provision_dir']='19_schrodinger';
distro_tag_19['container']=true;
distro_tag_19['container_dir']='19_schrodinger';
distro_tag_19['container_mnt']='/srv';

