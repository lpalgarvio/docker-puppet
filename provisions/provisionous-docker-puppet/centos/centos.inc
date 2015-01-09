#!/bin/bash
#title		 :centos.inc
#description	 :Configuration for Provisionous /Puppet/CentOS/* images
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
distro_info['desc']='Provisionous Docker/Puppet/CentOS';
distro_info['dir']='centos';
distro_info['tags']='05,05_rvm,06,06_rvm,07,07_rvm';

#
# Distribution releases/tags
#

# CentOS 5 (centos5)
declare -gA distro_tag_05;
distro_tag_05['status']=true;
distro_tag_05['version']='5';
distro_tag_05['codename']='centos5';
distro_tag_05['title']='CentOS 5 (centos5)';
distro_tag_05['desc']='Provisionous Docker/Puppet/CentOS/5 (centos5)';
distro_tag_05['url']='solict/provisionous-puppet-centos:centos5';
distro_tag_05['shell']='/bin/bash';
distro_tag_05['provision']=true;
distro_tag_05['provision_dir']='05_centos5';
distro_tag_05['container']=true;
distro_tag_05['container_dir']='05_centos5';
distro_tag_05['container_mnt']='/srv';

# CentOS 5 (centos5) RVM
declare -gA distro_tag_05_rvm;
distro_tag_05_rvm['status']=true;
distro_tag_05_rvm['version']='5_rvm';
distro_tag_05_rvm['codename']='centos5_rvm';
distro_tag_05_rvm['title']='CentOS 5 (centos5) RVM';
distro_tag_05_rvm['desc']='Provisionous Docker/Puppet/CentOS/5 (centos5) RVM';
distro_tag_05_rvm['url']='solict/provisionous-puppet-centos:centos5_rvm';
distro_tag_05_rvm['shell']='/bin/bash';
distro_tag_05_rvm['provision']=true;
distro_tag_05_rvm['provision_dir']='05_centos5_rvm';
distro_tag_05_rvm['container']=true;
distro_tag_05_rvm['container_dir']='05_centos5_rvm';
distro_tag_05_rvm['container_mnt']='/srv';

# CentOS 6 (centos6)
declare -gA distro_tag_06;
distro_tag_06['status']=true;
distro_tag_06['version']='6';
distro_tag_06['codename']='centos6';
distro_tag_06['title']='CentOS 6 (centos6)';
distro_tag_06['desc']='Provisionous Docker/Puppet/CentOS/6 (centos6)';
distro_tag_06['url']='solict/provisionous-puppet-centos:centos6';
distro_tag_06['shell']='/bin/bash';
distro_tag_06['provision']=true;
distro_tag_06['provision_dir']='06_centos6';
distro_tag_06['container']=true;
distro_tag_06['container_dir']='06_centos6';
distro_tag_06['container_mnt']='/srv';

# CentOS 6 (centos6) RVM
declare -gA distro_tag_06_rvm;
distro_tag_06_rvm['status']=true;
distro_tag_06_rvm['version']='6_rvm';
distro_tag_06_rvm['codename']='centos6_rvm';
distro_tag_06_rvm['title']='CentOS 6 (centos6) RVM';
distro_tag_06_rvm['desc']='Provisionous Docker/Puppet/CentOS/6 (centos6) RVM';
distro_tag_06_rvm['url']='solict/provisionous-puppet-centos:centos6_rvm';
distro_tag_06_rvm['shell']='/bin/bash';
distro_tag_06_rvm['provision']=true;
distro_tag_06_rvm['provision_dir']='06_centos6_rvm';
distro_tag_06_rvm['container']=true;
distro_tag_06_rvm['container_dir']='06_centos6_rvm';
distro_tag_06_rvm['container_mnt']='/srv';

# CentOS 7 (centos7)
declare -gA distro_tag_07;
distro_tag_07['status']=true;
distro_tag_07['version']='7';
distro_tag_07['codename']='centos7';
distro_tag_07['title']='CentOS 7 (centos7)';
distro_tag_07['desc']='Provisionous Docker/Puppet/CentOS/7 (centos7)';
distro_tag_07['url']='solict/provisionous-puppet-centos:centos7';
distro_tag_07['shell']='/bin/bash';
distro_tag_07['provision']=true;
distro_tag_07['provision_dir']='07_centos7';
distro_tag_07['container']=true;
distro_tag_07['container_dir']='07_centos7';
distro_tag_07['container_mnt']='/srv';

# CentOS 7 (centos7) RVM
declare -gA distro_tag_07_rvm;
distro_tag_07_rvm['status']=true;
distro_tag_07_rvm['version']='7_rvm';
distro_tag_07_rvm['codename']='centos7_rvm';
distro_tag_07_rvm['title']='CentOS 7 (centos7) RVM';
distro_tag_07_rvm['desc']='Provisionous Docker/Puppet/CentOS/7 (centos7) RVM';
distro_tag_07_rvm['url']='solict/provisionous-puppet-centos:centos7_rvm';
distro_tag_07_rvm['shell']='/bin/bash';
distro_tag_07_rvm['provision']=true;
distro_tag_07_rvm['provision_dir']='07_centos7_rvm';
distro_tag_07_rvm['container']=true;
distro_tag_07_rvm['container_dir']='07_centos7_rvm';
distro_tag_07_rvm['container_mnt']='/srv';

