#!/bin/bash
#title		 :ubuntu.inc
#description	 :Configuration for Provisionous Docker/Puppet/Ubuntu/* images
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
distro_info['desc']='Provisionous Docker/Puppet/Ubuntu';
distro_info['dir']='ubuntu';
distro_info['tags']='1004,1004_rvm,1204,1204_rvm,1404,1404_rvm';

#
# Distribution releases/tags
#

# Ubuntu 10.04 (lucid)
declare -gA distro_tag_1004;
distro_tag_1004['status']=true;
distro_tag_1004['version']='10.04';
distro_tag_1004['codename']='lucid';
distro_tag_1004['title']='Ubuntu 10.04 (lucid)';
distro_tag_1004['desc']='Provisionous Docker/Puppet/Ubuntu/10.04 (lucid)';
distro_tag_1004['url']='solict/provisionous-puppet-ubuntu:lucid';
distro_tag_1004['shell']='/bin/bash';
distro_tag_1004['provision']=true;
distro_tag_1004['provision_dir']='1004_lucid';
distro_tag_1004['container']=true;
distro_tag_1004['container_dir']='1004_lucid';
distro_tag_1004['container_mnt']='/srv';

# Ubuntu 10.04 (lucid) RVM
declare -gA distro_tag_1004_rvm;
distro_tag_1004_rvm['status']=true;
distro_tag_1004_rvm['version']='10.04_rvm';
distro_tag_1004_rvm['codename']='lucid_rvm';
distro_tag_1004_rvm['title']='Ubuntu 10.04 (lucid) RVM';
distro_tag_1004_rvm['desc']='Provisionous Docker/Puppet/Ubuntu/10.04 (lucid) RVM';
distro_tag_1004_rvm['url']='solict/provisionous-puppet-ubuntu:lucid_rvm';
distro_tag_1004_rvm['shell']='/bin/bash';
distro_tag_1004_rvm['provision']=true;
distro_tag_1004_rvm['provision_dir']='1004_lucid_rvm';
distro_tag_1004_rvm['container']=true;
distro_tag_1004_rvm['container_dir']='1004_lucid_rvm';
distro_tag_1004_rvm['container_mnt']='/srv';

# Ubuntu 12.04 (precise)
declare -gA distro_tag_1204;
distro_tag_1204['status']=true;
distro_tag_1204['version']='12.04';
distro_tag_1204['codename']='precise';
distro_tag_1204['title']='Ubuntu 12.04 (precise)';
distro_tag_1204['desc']='Provisionous Docker/Puppet/Ubuntu/12.04 (precise)';
distro_tag_1204['url']='solict/provisionous-puppet-ubuntu:precise';
distro_tag_1204['shell']='/bin/bash';
distro_tag_1204['provision']=true;
distro_tag_1204['provision_dir']='1204_precise';
distro_tag_1204['container']=true;
distro_tag_1204['container_dir']='1204_precise';
distro_tag_1204['container_mnt']='/srv';

# Ubuntu 12.04 (precise) RVM
declare -gA distro_tag_1204_rvm;
distro_tag_1204_rvm['status']=true;
distro_tag_1204_rvm['version']='12.04_rvm';
distro_tag_1204_rvm['codename']='precise_rvm';
distro_tag_1204_rvm['title']='Ubuntu 12.04 (precise) RVM';
distro_tag_1204_rvm['desc']='Provisionous Docker/Puppet/Ubuntu/12.04 (precise) RVM';
distro_tag_1204_rvm['url']='solict/provisionous-puppet-ubuntu:precise_rvm';
distro_tag_1204_rvm['shell']='/bin/bash';
distro_tag_1204_rvm['provision']=true;
distro_tag_1204_rvm['provision_dir']='1204_precise_rvm';
distro_tag_1204_rvm['container']=true;
distro_tag_1204_rvm['container_dir']='1204_precise_rvm';
distro_tag_1204_rvm['container_mnt']='/srv';

# Ubuntu 14.04 (trusty)
declare -gA distro_tag_1404;
distro_tag_1404['status']=true;
distro_tag_1404['version']='14.04';
distro_tag_1404['codename']='trusty';
distro_tag_1404['title']='Ubuntu 14.04 (trusty)';
distro_tag_1404['desc']='Provisionous Docker/Puppet/Ubuntu/14.04 (trusty)';
distro_tag_1404['url']='solict/provisionous-puppet-ubuntu:trusty';
distro_tag_1404['shell']='/bin/bash';
distro_tag_1404['provision']=true;
distro_tag_1404['provision_dir']='1404_trusty';
distro_tag_1404['container']=true;
distro_tag_1404['container_dir']='1404_trusty';
distro_tag_1404['container_mnt']='/srv';

# Ubuntu 14.04 (trusty) RVM
declare -gA distro_tag_1404_rvm;
distro_tag_1404_rvm['status']=true;
distro_tag_1404_rvm['version']='14.04_rvm';
distro_tag_1404_rvm['codename']='trusty_rvm';
distro_tag_1404_rvm['title']='Ubuntu 14.04 (trusty) RVM';
distro_tag_1404_rvm['desc']='Provisionous Docker/Puppet/Ubuntu/14.04 (trusty) RVM';
distro_tag_1404_rvm['url']='solict/provisionous-puppet-ubuntu:trusty_rvm';
distro_tag_1404_rvm['shell']='/bin/bash';
distro_tag_1404_rvm['provision']=true;
distro_tag_1404_rvm['provision_dir']='1404_trusty_rvm';
distro_tag_1404_rvm['container']=true;
distro_tag_1404_rvm['container_dir']='1404_trusty_rvm';
distro_tag_1404_rvm['container_mnt']='/srv';

